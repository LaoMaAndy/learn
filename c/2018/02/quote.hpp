/*
   class derived
*/

#ifndef QUOTE_HPP
#define QUOTE_HPP

#include <memory>
#include <iostream>
#include <string>
#include <cstddef>

class quote
{
	friend std::istream& operator>>(std::istream&, quote&);
	friend std::ostream& operator>>(std::ostream&, const quote&);
	public:
		quote() = default;
		quote(const std::string &b, double s) : bookno(b), price(s) { }
		virtual ~quote() = default;
		std::string isbn() const { return bookno; }
		virtual double net_price(std::size_t n) const { return n * price; }
		virtual quote* clone() const { return new quote(*this); }
	private:
		std::string bookno;
	protected:
		double price = 0.0;
};

class disc_quote : public quote
{
	public:
		disc_quote() = default;
		disc_quote(const std::string& book, double price, std::size_t q, double d) :
					quote(book, price), quantity(q), discount(d) { }
		double net_price(std::size_t) const = 0;
		std::pair<size_t, double> discount_policy() const { return {quantity, discount}; }
	protected:
		std::size_t quantity = 0;
		double discount = 0.0;
};

class bulk_quote : public disc_quote
{
	bulk_quote() = default;
	bulk_quote(const std::string& book, double p, std::size_t qty, double disk) :
				disc_quote(book, p, qty, disk) { }
	double net_price(std::size_t) const override;
	bulk_quote* clone() const { return new bulk_quote(*this); }
};

class lim_quote : public disc_quote
{
	public:
		lim_quote(const std::string& book = "", 
				  double p = 0.0, 
				  std::size_t qty = 0, 
				  double disk_rate = 0.0) :
					disc_quote(book, p, qty, disk_rate) { }
		double net_price(std::size_t) const;
		lim_quote* clone() const { return new lim_quote(*this); }
};


#endif

