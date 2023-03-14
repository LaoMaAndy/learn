#include "c0208p.hpp"
using namespace std;
int main(void)
{
	point p;

	p.info();
	p.moveto(3, 4);
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

	return 0;
}
