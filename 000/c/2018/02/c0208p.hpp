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
		point() = default;
		point(int x, int y = 0) : xcoord(x), ycoord(y) { }
	public:
		point& operator=(const point &p) { xcoord = p.xcoord; ycoord = p.ycoord; }
		point& operator+=(const point&);
		point& operator-=(const point&);
		point& moveto(const point&);
		point& moveto(int x, int y) { xcoord = x; ycoord = y; }
		int getx() const { return xcoord; }
		int gety() const { return ycoord; }
		void setx(int x) { xcoord = x; }
		void sety(int y) { ycoord = y; }
		void set(int x, int y) { xcoord = x ; ycoord = y; }
		int	dist() const; 
		int dist(const point&) const;
		void info();
	private:
		int xcoord = 0;
		int ycoord = 0;
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

int
point::dist(const point &p) const
{
	int x = xcoord - p.xcoord;
	int y = ycoord - p.ycoord;
	return sqrt(x * x + y * y);
}

inline int
point::dist() const
{
	return dist(point(0, 0));
}

inline int
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
operator==(const point &lhs, const point &rhs)
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
	out << "x:" << std::setw(6) << p.xcoord;
	out << ", ";
	out << "y:" << std::setw(6) << p.ycoord;
	out << " , distance: " << std::setw(6) << p.dist() << std::endl;
	return out;
}


#endif
