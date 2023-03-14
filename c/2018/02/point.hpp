/*
   class of point
*/

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <iomanip>
#include <cmath>

class point
{
	friend std::istream& operator>>(std::istream&, point&);
	friend std::ostream& operator<<(std::ostream&, const point&);
	friend bool operator==(const point&, const point&);
	public:
		typedef double type;
		point() = default;
		point(type x, type y = (type) 0) : xcoord(x), ycoord(y) { }
		point(const point& p) : xcoord(p.xcoord), ycoord(p.ycoord) { }
	public:
		point& operator=(const point& p) { xcoord = p.xcoord; ycoord = p.ycoord; }
		point& operator+=(const point&);
		point& operator-=(const point&);
		point& moveto(const point&);
		point& moveto(type x, type y) { xcoord = x; ycoord = y; }
		type getx() const { return xcoord; }
		type gety() const { return ycoord; }
		void setx(type x) { xcoord = x; }
		void sety(type y) { ycoord = y; }
		void set(type x, type y) { xcoord = x ; ycoord = y; }
		type dist() const; 
		type dist(const point&) const;
		void info();
	private:
		type xcoord = (type) 0;
		type ycoord = (type) 0;
};

inline point&
point::moveto(const point& p)
{
	xcoord = p.xcoord;
	ycoord = p.ycoord;
	return *this;
}

inline void 
point::info()
{
	std::cout << *this;
}

point::type
point::dist(const point &p) const
{
	type x = xcoord - p.xcoord;
	type y = ycoord - p.ycoord;
	return sqrt(x * x + y * y);
}

inline point::type
point::dist() const
{
	return dist(point(0, 0));
}

inline point::type
dist(const point &lhs, const point &rhs)
{
	return lhs.dist(rhs);
}
	
inline point&
point::operator+=(const point& p)
{
	xcoord += p.xcoord;
	ycoord += p.ycoord;
	return *this;
}

inline point
operator+(const point& lhs, const point& rhs)
{
	point temp(lhs);
	temp += rhs;
	return temp;
}

inline point&
point::operator-=(const point& p)
{
	xcoord -= p.xcoord;
	ycoord -= p.ycoord;
	return *this;
}

inline point
operator-(const point& lhs, const point& rhs)
{
	point temp(lhs);
	temp -= rhs;
	return temp;
}

inline bool
operator==(const point& lhs, const point& rhs)
{
	return (lhs.xcoord == rhs.xcoord) && (lhs.ycoord == rhs.ycoord);
}

inline bool
operator!=(const point &lhs, const point &rhs)
{
	return !(lhs == rhs);
}

inline bool
compare(const point &lhs, const point &rhs)
{
	return lhs == rhs;
}

std::istream&
operator>>(std::istream& in, point& p)
{
	in >> p.xcoord >> p.ycoord;
	if (!in)
		p = point();
	return in;
}

std::ostream&
operator<<(std::ostream& out, const point& p)
{
	out << "point information: " ;
	out << "x:" << std::setw(7) << std::setprecision(2) << std::fixed << p.xcoord;
	out << ", ";
	out << "y:" << std::setw(7) << std::setprecision(2) << std::fixed << p.ycoord;
	out << ", distance: " << std::setw(7) << std::setprecision(2) << std::fixed << p.dist() << std::endl;
	return out;
}


#endif
