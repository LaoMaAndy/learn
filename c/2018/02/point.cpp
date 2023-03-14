#include "point.hpp"

using namespace std;


void testpre()
{
	double d = 123.4567890;
	cout << "print precision" << endl;
	cout << d << endl;
}

int main(void)
{
	point p;

	p.info();
	p.moveto(3.01, 4.02);
	p.info();
	point p1(p);
	p1.info();
	p1 += p;
	p1.info();	
	p1 -= p;
	p1.info();
	p1 -= p;
	cout << "p1 dist p: " << dist(p1, p) << endl;
	cout << "p1 equal p ? " << (p1 == p) << endl;

	testpre();

	return 0;
}
