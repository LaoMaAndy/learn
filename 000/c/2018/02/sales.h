
#ifndef SALES_H
#define SALES_H

#include <iostream>
#include <string>

class sales {
friend std::istream& operator>>(std::istream&, sales&);
friend std::ostream& operator<<(std::ostream&, const sales&);
friend bool operator<(const sales&, const sales&);
friend bool operator==(const sales&, const sales&);
public:
    // constructors are explained in section 7.1.4, pages 262 - 265
    // default constructor needed to initialize members of built-in type
    sales() = default;
    sales(const std::string &book): book_no(book) { }
    sales(std::istream &is) { is >> *this; }
public:
    // operations on sales objects
    // member binary operator: left-hand operand bound to implicit this pointer
    sales& operator+=(const sales&);
    
    // operations on sales objects
    std::string isbn() const { return book_no; }
    double aprice() const;
// private members as before
private:
    std::string book_no;      // implicitly initialized to the empty string
    unsigned sold = 0;        // explicitly initialized
    double revenue = 0.0;
};

// used in chapter 10
inline
bool compareIsbn(const sales &lhs, const sales &rhs) 
{ return lhs.isbn() == rhs.isbn(); }

// nonmember binary operator: must declare a parameter for each operand
sales operator+(const sales&, const sales&);

inline bool 
operator==(const sales &lhs, const sales &rhs)
{
    // must be made a friend of sales
    return lhs.sold == rhs.sold &&
           lhs.revenue == rhs.revenue &&
           lhs.isbn() == rhs.isbn();
}

inline bool 
operator!=(const sales &lhs, const sales &rhs)
{
    return !(lhs == rhs); // != defined in terms of operator==
}

// assumes that both objects refer to the same ISBN
sales& sales::operator+=(const sales& rhs) 
{
    sold += rhs.sold; 
    revenue += rhs.revenue; 
    return *this;
}

// assumes that both objects refer to the same ISBN
sales 
operator+(const sales& lhs, const sales& rhs) 
{
    sales ret(lhs);  // copy (|lhs|) into a local object that we'll return
    ret += rhs;           // add in the contents of (|rhs|) 
    return ret;           // return (|ret|) by value
}

std::istream& 
operator>>(std::istream& in, sales& s)
{
    double price;
    in >> s.book_no >> s.sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.sold * price;
    else 
        s = sales();  // input failed: reset object to default state
    return in;
}

std::ostream& 
operator<<(std::ostream& out, const sales& s)
{
    out << s.isbn() << " " << s.sold << " "
        << s.revenue << " " << s.aprice();
    return out;
}

double sales::aprice() const
{
    if (sold) 
        return revenue/sold; 
    else 
        return 0;
}
#endif
