#include "0head.cpp"

class data
{
friend ostream& operator<< (ostream& os, const data &d) {os << d.d; return os;}
friend istream& operator>> (istream& is, data &d) {is >> d.d; return is;}
friend int comp(const data &i, const data &j) {if (i.d > j.d) return 1; else if (i.d < j.d) return -1; else return 0;}
public:
	typedef double dtype;
	data() {d = 0.0;}
	data(dtype v) {d = v;}
	data(const data& v) {d = v.d;}
	data& operator= (const data& v) {d = v.d; return *this;}
	dtype get() {return d;}
	void set(dtype v) {d = v;}
	int comp(const data &i) {if (d > i.d) return 1; else if (d < i.d) return -1; else return 0;}
private:
	dtype d;
};


void test_data(void)
{
	data d(12.0);
	cout << "this is a << test: " << d << endl;
	cout << "input a number:" << endl;
	//cin >> d;
	cout << "data is : " << d << endl;
	data d1(12), d2(43);
	cout << comp(d1, d2) << endl;
}

int main() {
	test_data();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

