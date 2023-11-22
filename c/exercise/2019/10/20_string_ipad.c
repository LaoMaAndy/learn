#include “head.h”

size_t Strlen(const char *s) {
    size_t len;
    
    for (len = 0; s[len] != ‘\0’; ++len)
        ;
    return len;
}
size_t Stlen2(const char *s) {
    const char *p;
    
    for (p = s; *p != ‘\0’; ++p)
        ;
    return p - s;
}
char *Strcpy(char *dest, const char *src) {
    char *p = dest;
    
    while ((*dest++ = *src++) != ‘\0’)
        ;
    return p;
}
char *Strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    
    for (i = 0; i < n && src[i] != ‘\0’; ++i)
        dest[i] = src[i];
    for ( ; i < n; ++i)
        dest[i] = ‘\0’;
    return dest;
}
char *Strcat(char *dest, const char *src) {
    char *p = dest;
    
    dest += Strlen(dest);
    Strcpy(dest, src);
    return p;
}
char *Strncat(char *dest, const char *src, size_t n) {
    size_t dest_len, i;
    
    dest_len = Strlen(dest);
    for (i = 0; i < n; ++i)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = ‘\0’;
    return dest;
}
int Strcmp(const char *s, const char *t) {
    for ( ; *s == *t; ++s, ++t)
        if (*s == ‘\0’)
            return 0;
    return *s - *t;
}
int Strncmp(const char *s, const char *t, size_t n) {
    size_t i;
    
    if (n == 0)
        return 0;
    for (i = 0; i < n - 1 && s[i] == t[i]; ++i)
        if (s[i] == ‘\0’)
            return 0;
    return s[i] - t[i];
}
char *Strstr(const char *dest, const char *sub) {
    size_t sub_len;
    
    sub_len = Strlen(sub);
    for ( ; *dest != ‘\0’; ++dest)
        if (*dest == *sub)
            if (Strncmp(dest, sub, sub_len) == 0)
                return (char *) dest;
    return NULL;
}
size_t Strindex(const char *dest, const char *sub) {
    const char *p = dest;
    
    dest = Strstr(dest, sub);
    return (dest == NULL) ? -1 : (dest - p);
}
char *Strchr(const char *dest, char c) {
    for ( ; *dest != ‘\0’; ++dest)
        if (*dest == c)
            return (char *) dest;
    return NULL;
}
char *Strrchr(const char *dest, char c) {
    const char *p = dest;
    
    dest += Strlen(dest);
    for (—-dest; dest >= p; —-dest)
        if (*dest = c)
            return (char *) dest;
    return NULL;
}
size_t Strspn(const char *dest, const char *pre) {
    const char *p = dest;
    
    for ( ; *dest != ‘\0’; ++dest)
        if (Strchr(pre, *dest) == NULL)
            break;
    return dest - p;
}
size_t Strcspn(const char *dest, const char *pre) {
    const char *p = dest;
    
    for ( ; *dest != ‘\0’; ++dest)
        if (Strchr(pre, *dest !=‘\0’))
            break;
    return p - dest;
}
char *Strpbrk(const char *dest, const char *pre) {
    dest += Strcspn(dest, pre);
    return (*dest == ‘\0’) ? NULL : (char *) dest;
}
char *Strrev(char *s) {
    char *p, *r, c;
    
    p = r = s;
    r += Strlen(s);
    for (—-r; r > p; —-r, ++p) {
        c = *r;
        *r = *p;
        *p = c;
    }
    return s;
}
char *Strdup(const char *s) {
    char *p;
    
    p = (char *) malloc(Strlen(s) + 1);
    return (p == NULL) ? NULL : Strcpy(p, s);
}
char *Strsqz(char *dest, char c) {
    char *cur, *ret;
    
    cur = ret = dest;
    for ( ; *dest != ‘\0’; ++dest)
        if (*dest != c)
            *cur++ = *dest;
    *cur = ‘\0’;
    return ret;
}
char *Strsqzs(char *dest, const char *sq) {
    for ( ; *sq != ‘\0’; ++sq)
        Strsqz(dest, *sq);
    return dest;
}
char *Strtoup(char *s) {
    char *ret = s;
    
    for ( ; *s != ‘\0’; ++s)
        *s = Toupper(*s);
    return ret;
}
char *Strtolow(char *s) {
    char *ret = s;
    
    for ( ; *s != ‘\0’; ++s)
        *s = Tolower(*s);
    return ret;
}
char *Strlead(char *s) {
    char *cur;
    
    for (cur = s; *s != ‘\0’; ++s)
        if (!Isspace(*s))    
            break;
    return (cur == s) ? cur : Strcpy(cur, s);
}
char *Strtail(char *dest) {
    char *head = dest;
    
    dest += Strlen(dest);
    for (—-dest; dest >= head; —dest)
        if (!Isspace(*dest))
            break;
    *++dest = ‘\0’;
    return head;
}
char *Strtrim(char *dest) {
    return Strlead(Strtail(dest));
}

    
    
