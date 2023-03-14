/*
   point class
*/
#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <iomanip>
#include <cmath>

class point
{
	friend std::istream& operator>>(std::istream&, point&);
	friend std::ostream& operator<<(std::istream&, const point&);
	friend bool operator==(const point&, const point&);
	public:
		typedef double type;
		point() = default;
		point(type x, type y) : xval(x), yval(y) { }
		point(const point& p) : xval(p.xval), yval(p.yval) { }
		type x() const { return xval; }
		type y() const { return yval; }
		point& x(type a) { xval = a; return *this; }
		point& y(type b) { yval = b; return *this; }
		point& set(type a, type b) { xval = a; yval = b; return *this; }
	private:
		type xval = (type) 0;
		type yval = (type) 0;
};

#endif

