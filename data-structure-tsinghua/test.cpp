/*
 * test.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: lixudong
 */

#include "dstruct.h"

void test_data(void)
{
	data d(12.0);
	cout << "this is a << test: " << d << endl;
	cout << "input a number:" << endl;
	//cin >> d;
	cout << "data is : " << d << endl;
	data d1(12), d2(43);
	cout << comp(d1, d2) << endl;
}


