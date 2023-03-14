/*
 * 0head.h
 *
 *  Created on: Oct 20, 2017
 *      Author: lixudong
 */

#ifndef CPRIMER_H_
#define CPRIMER_H_

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;
#define COUT_STR(val)		cout << (#val) << endl
#define COUT_VAR(val) 		cout << ("[variable] "#val":\t") << (val) << endl
#define COUT_VAL(val) 		cout << ("[variable] "#val":\t") << (val) << endl
#define COUT_FUN(fun)		cout << ("[function] "#fun":  ") << (fun) << endl
#define COUT_CAL(fun)		cout << ("[function] "#fun":  ") << endl; fun
#define COUT_INF(info, fun) cout << ("[function] "#info": ") << endl; fun
#define COUT_INV(info, val) cout << ("[function] "#info":\t") << (val) << endl
#define COUT_ARY(val, m)	cout << (val) << ((m % 10) == 9 ? "\n" : "\t")
#define TRUE_STR(vf)		(((vf) == false) ? "false" : "true")

#define PRN_VAL(val, type) 	printf("(variable) "#val":\t%"#type"\n", val)
#define PRN_VAR(val, type) 	printf("(variable) "#val":\t%"#type"\n", val)
#define PRN_FUN(fun, type) 	printf("(function) "#fun":\t%"#type"\n", fun)
#define PRN_CAL(fun)		printf("(function) "#fun"\n");fun
#define PRN_SEN(sen)		printf("(sentence) "#sen";\n");sen
#define PRN_STR(str)		printf(#str"\n")
#define PRN_PRN				printf

#endif /* CPRIMER_H_ */
