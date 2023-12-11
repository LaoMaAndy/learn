/*
 * cprimer.h
 *
 *  Created on: Oct 20, 2017
 *      Author: lixudong
 */

#ifndef CPRIMER_H_
#define CPRIMER_H_

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
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


#endif /* CPRIMER_H_ */
