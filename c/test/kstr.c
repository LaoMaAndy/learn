/*
   k-str: count string
*/
#include "0head.c"

struct kstr
{
	char *base;
	size_t len;
	size_t msize;
};
typedef struct kstr kstr;
#define KSTR_UNIT 64

size_t k_calc_size(size_t n)
{
	return (++n / KSTR_UNIT + 1) * KSTR_UNIT;
}
kstr *k_reinit(kstr *k, size_t n)
{
	if (k == NULL)
	{
		k = (kstr *) malloc(sizeof(kstr));
		if (k == NULL)
			return NULL;
		k->base = NULL;
	}
	size_t l = k_calc_size(n);
	char *sp =  malloc(l + sizeof(kstr));
	if (sp == NULL)
	{	
		free(k);
		return NULL;
	}
	if (k->base != NULL)
		free(k->base);
	k->base = sp;
	k->len = 0;
	k->msize = l;
	k->base[0] = '\0';
	return k;
}
kstr *k_init(size_t n)
{
	return k_reinit(NULL, n);
}
kstr *k_resize(kstr *k, size_t l)
{
	if (k == NULL)
		return k_init(l);
	size_t n = k_calc_size(l);
	char *p = (char *)realloc(k->base, n);
	if (p == NULL)
		return k;
	k->len = n > k->len ? k->len : n;
	k->msize = n;
	k->base = p;
	k->base[k->len] = '\0';
	return k;
}
void k_free(kstr *k)
{
	if (k != NULL)
	{
		if (k->base != NULL)
			free(k->base);
		free(k);
	}
}
kstr *k_str(const char *s)
{
	size_t n = strlen(s);
	kstr *k = k_init(n);
	memcpy(k->base, s, n + 1);
	k->len = n;
	return k;
}
void k_prn(const kstr *k)
{
	printf("str: %s\n" , k->base);
	printf("len: %ld\n", k->len);
	printf("mem: %ld\n", k->msize);
}
void test_resize(void)
{
	printf("---test: resize---\n");
	kstr *p = k_str("kstr resize test.");
	k_prn(p);
	k_resize(p, 1024);
	k_prn(p);
}
kstr *k_ncopy(kstr *dest, const kstr *src, size_t n)
{
	if (dest == NULL)
		return NULL;
	if (src == NULL)
		return dest;
	if (dest->len < n)
		k_reinit(dest, n + 1);
	memcpy(dest->base, src->base, n);
	dest->len = n;
	dest->base[n] = '\0';
	return dest;	
}
kstr *k_copy(kstr *dest, const kstr *src)
{
	return k_ncopy(dest, src, src->len);
}
kstr *k_dup(const kstr *src)
{
	kstr *k = k_init(0);
	return k_copy(k, src);
}
void test_ncopy(void)
{
	printf("---test: ncopy---\n");
	kstr *k1 = k_str("sorce string");
	kstr *k2 = k_str("dest string");
	k_prn(k1);
	k_prn(k2);
	printf("---after: k_ncopy\n");
	k_ncopy(k2, k1, 3);
	k_prn(k2);
	printf("---test k_dup:\n");
	kstr *k3 = k_dup(k1);
	k_prn(k3);
}
void test_copy(void)
{
	kstr *k = NULL;
	kstr *src = k_str("test kstr copy");

	k_copy(k, src);
	printf("---test: copy---\n");
	k_prn(k);
}

size_t k_len(kstr *dest)
{
	if (dest != NULL)
		return dest->len;
	return 0;
}
void test_str(void)
{
	kstr *p = k_str("this is a test");
	printf("---test: str---\n");
	k_prn(p);
}
kstr *k_ncat(kstr *dest, const kstr *src, size_t n)
{
	if (dest == NULL)
		return NULL;
	if (src == NULL)
		return dest;
	if (dest->len + n < dest->msize)
		k_resize(dest, dest->len + n);
	memcpy(dest->base + dest->len, src->base, n);
	dest->len += n;
	dest->base[dest->len] = '\0';
}
kstr *k_cat(kstr *dest, const kstr *src)
{
	k_ncat(dest, src, src->len);
}
void test_cat(void)
{
	kstr *k1 = k_str("aaaa");
	kstr *k2 = k_str("bbbb");
	printf("---test k_cat\n");
	k_cat(k1, k2);
	k_prn(k1);
}

kstr *k_swap(kstr *dest, kstr *src)
{
	char *temp;
	size_t i;

	if (dest == NULL || src == NULL)
		return NULL;
	temp = dest->base;
	dest->base = src->base;
	src->base = temp;
	i = dest->len;
	dest->len = src->len;
	src->len = i;
	i = dest->msize;
	dest->msize = src->msize;
	src->msize = i;
	return dest;
}
int k_ncomp(const kstr *s, const kstr *t, size_t n)
{
	if (s == NULL && t == NULL)
		return 0;
	if (s == NULL)
		return -1;
	if (t == NULL)
		return 1;
	return strncmp(s->base, t->base, n);
}
int k_comp(const kstr *s, const kstr *t)
{
	return k_ncomp(s, t, s->len > t->len ? s->len : t->len);
}
void test_comp(void)
{
	printf("---test: ncomp, comp---\n");
	kstr *k1 = k_str("b");
	kstr *k2 = k_str("a");
	k_prn(k1);
	k_prn(k2);
	printf("compare k1, k2: %d\n", k_comp(k1, k2));
}
size_t k_index(const kstr *dest, const kstr *sub)
{
	char *p = strstr(dest->base, sub->base);
	if (p != NULL)
		return p - dest->base;
	else
		return -1;
}
kstr *k_sub(kstr *dest, const kstr *tar, const kstr *sub)
{
	if (dest == NULL)
		return NULL;
	if (tar == NULL)
		return dest;
	size_t l = (dest->len / tar->len + 1) * sub->len;
	kstr *k = k_init(l);
	if (k == NULL)
		return NULL;

	size_t flen = tar->len, rlen = sub->len;
	const char *sp = dest->base;
	char *dp = k->base;
	char *cur;
	int c = tar->base[0];

	while (*sp != '\0')
		if (*sp == c && (strncmp(sp, tar->base, flen) == 0))
		{
			strncpy(dp, sub->base, rlen);
			dp += rlen;
			sp += flen;
		}
		else
			*dp++ = *sp++;
	k->len = dp - k->base;
	k_swap(dest, k);
	k_free(k);
	return dest;
}
void test_subs(void)
{
	printf("---test subs---\n");
	kstr *dest = k_str("t1t2t3t");
	kstr *tar = k_str("t");
	kstr *sub = k_str("TTT");
	k_sub(dest, tar, sub);
	k_prn(dest);
}
void test_m(void)
{
	printf("size_t: %ld\n", sizeof(size_t));
	for (int n = 0; n < 200; n++)
	{
		int l = k_calc_size(n);
		printf("n is: %3d, l is: %3d\n", n, l);
	}
}

int main(void)
{
	test_subs();
	test_comp();
	test_cat();
	test_ncopy();
	test_str();
	test_resize();
	return 0;
}
