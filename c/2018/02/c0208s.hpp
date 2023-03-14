/*
   header file of book sales record
*/
#ifndef SALES_HPP
#define SALES_HPP

#include <iostream>
#include <string>

class sales
{
	friend std::istream& operator>>(std::istream&, sales&);
	friend std::ostream& operator<<(std::ostream&, const sales&);
	friend bool operator<(const sales&, const sales&);
	friend bool operator==(const sales&, const sales&);
	public:
		sales() = default;
		sales(const std::string &book) : book_no(book) { }
		sales(std::istream &is) { is >> *this;}
	public:
		sales& operator+=(const sales&);
		std::string isbn() const { return book_no; }
		double aprice() const;
	private:
		std::string book_no;
		unsigned sold = 0;
		double revenue = 0.0;
};

inline bool
compare(const sales &lhs, const sales& rhs)
{
	return lhs.isbn() == rhs.isbn();
}

inline bool
operator==(const sales &lhs, const sales &rhs)
{
	return lhs.sold == rhs.sold &&
		   lhs.revenue == rhs.revenue &&
		   lhs.isbn() == rhs.isbn();
}

inline bool
operator!=(const sales &lhs, const sales &rhs)
{
	return !(lhs == rhs);
}

sales&
sales::operator+=(const sales& rhs)
{
	sold += rhs.sold;
	revenue += rhs.revenue;
	return *this;
}

std::istream&
operator>>(std::istream& in, sales& s)
{
	double price;
	in >> s.book_no >> s.sold >> price;
	if (in)
		s.revenue = s.sold * price;
	else
		s = sales();
	return in;
}

std::ostream&
operator<<(std::ostream& out, const sales &s)
{
	out << s.isbn() << " " << s.sold << " "
		<< s.revenue << " " << s.aprice();
	return out;
}

double
sales::aprice() const
{
	if (sold)
		return revenue / sold;
	else
		return 0;
}

#endif
