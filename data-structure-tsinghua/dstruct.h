/*
 * dstruct.h
 *
 *  Created on: Oct 31, 2017
 *      Author: lixudong
 */

#ifndef DSTRUCT_H_
#define DSTRUCT_H_

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <stdexcept>
#include <initializer_list>
using namespace std;
#define COUT_STR(val)		cout << (val) << endl
#define COUT_REM(rem)		cout << (#rem)<< endl
#define COUT_VAR(val) 		cout << ("[variable] "#val":\t") << (val) << endl
#define COUT_VAL(val) 		cout << ("[variable] "#val":\t") << (val) << endl
#define COUT_FUN(fun)		cout << ("[function] "#fun":  ") << (fun) << endl
#define COUT_CAL(fun)		cout << ("[function] "#fun":  ") << endl; fun
#define COUT_INF(info, fun) cout << ("[function] "#info": ") << endl; fun
#define COUT_INV(info, val) cout << ("[function] "#info":\t") << (val) << endl
#define COUT_ARY(val, m)	cout << (val) << ((m % 10) == 9 ? "\n" : "\t")
#define TRUE_STR(vf)		(((vf) == false) ? "false" : "true")

class data
{
friend ostream& operator<< (ostream& os, const data &d) {os << d.d; return os;}
friend istream& operator>> (istream& is, data &d) {is >> d.d; return is;}
friend int comp(const data &i, const data &j) {if (i.d > j.d) return 1; else if (i.d < j.d) return -1; else return 0;}
public:
	typedef double dtype;
	data() : d(0.0) {}
	data(dtype v) : d(v) {}
	data(const data& v) : d(v.d) {}
	data& operator= (const data& v) {d = v.d; return *this;}
	dtype get() {return d;}
	void set(dtype v) {d = v;}
	int comp(const data &i) {if (d > i.d) return 1; else if (d < i.d) return -1; else return 0;}
private:
	dtype d;
};

void test_data(void);

#endif /* DSTRUCT_H_ */
