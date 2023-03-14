/*
function: var_type, string_type, vector_type, array_type
			bit_prn, bit_chk, bit_set
*/
#include "0head.cpp"
void var_type(void)
{
	int a  = 1;
	int *ap = &a;
	int &ar = a;
	int *&apr = ap;
	const int b = 10;
	const int &arc = a;
	const int *bp = &b;
	const int &br = b;
	const int *&bpr = bp;
	const int *const bccp = &b;
	constexpr int c = b;
	vector<int> ca(10);
	vector<int> cb(10, 1);
	vector<int> cc{10};
	vector<int> cd = {10, 10};
	typedef const unsigned long CUL;
	typedef vector<int> VINT;
	using VSTR = VINT;
	using VVSTR = vector<vector<string>>;
	VINT f;
	VINT *fp;
	auto gb = f.begin();
	auto ge = f.end();
	vector<int>::iterator hi;
	vector<int>::reverse_iterator hr;
	decltype(f.end()) h_end;
	decltype(f.size()) h_size;
	decltype(*fp) rf = f;
	decltype((fp)) rp = fp;
}
void string_type(void)
{
	string s("12345");
	string t("abcdefg");
	string r;
	s.size();
	s.empty();
	s.push_back('s');
	s[0];
	r = s + t;
	r = s;
	int i;
	i = (s == t);
	i = (s != t);
	i = (s > t);
	i = (s < t);
}
void vector_type(void)
{
	vector<int> v(10);
	ptrdiff_t pt = v.cend() - v.cbegin();
	auto vp = &v;
	auto n1 = v.size();
	auto n2 = (*vp).size();
	auto n3 = vp->size();
	auto n4 = v.cend() - v.cbegin();
	int n = 0;
	for (auto &i : v)
		i = n++;
	for (auto i : v)
		COUT_VAR(i);
	for (auto ca = v.begin(); ca != v.end(); ++ca)
		*ca = *ca * *ca;
	for (size_t i = 0; i < v.size(); ++i)
		COUT_VAR(v[i]);
	for (size_t i = 0; i < v.size(); ++i)
		COUT_VAR(*(v.begin() + i) * i);
	for (auto i : v)
		COUT_VAR(i);
}
void array_type(void)
{
	int ia[20];
	int i = 1, j = 0;
	for (auto pi = begin(ia); pi < end(ia); ++pi)
		*pi = i + j, j = i, j = *pi;
	vector<int> vi(begin(ia), end(ia));
	for (auto array_item : vi)
		COUT_VAR(array_item);
	int ib[4][5];
	for (auto &row : ib)
		for (auto &col : row)
			col = ia[i++];
	for (auto &row : ib)
		for (auto &col : row)
			COUT_VAR(col);	
}

void bit_prn(unsigned long v)
{
	unsigned long m = ~(~0UL >> 1);
	for (int n = 0; n < sizeof(v) * 8; ++n, m >>= 1)
	  cout << (((v & m) == 0) ? 0 : 1) << ((n % 8 == 0 && n != 0) ? " - " : " ");
	cout << endl;
}
bool bit_chk(unsigned long v, int n)
{
	return (v & (1UL << n) == 0 ? false : true);
}
void bit_set(unsigned long &v, int n)
{
	v |= 1UL << n;
}
void bit_clr(unsigned long &v, int n)
{
	v &= ~(1UL << n);
}
/*test these function */
void bit_type(void)
{
	unsigned long i = 0;
	bit_set(i , 3);
	bit_set(i , 4);
	bit_prn(i);
	bit_clr(i, 4);
	bit_set(i, 0);
	bit_set(i, sizeof(i) * 8 - 1);
	COUT_VAL(bit_chk(i, 3));
	bit_prn(i);
}
int main() {
	vector_type();
	array_type();
	string_type();
	bit_type();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}


