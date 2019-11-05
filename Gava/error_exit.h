#pragma once
#include<iostream>
using namespace std;

static inline void exit_with_massage(string message) {
	cerr << message << endl;
	exit(-1);
}