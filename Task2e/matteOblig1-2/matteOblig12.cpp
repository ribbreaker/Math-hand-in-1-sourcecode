// matteOblig12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <iostream>
using namespace std;

int main()
{
	random_device rd;  //make a random number generator
	mt19937 gen(rd()); //seed another generator

	uniform_real_distribution<> flo(1, 10); //generate a float
	uniform_int_distribution<> in(1, 10); //generate an integer
	
	
	cout << "floats\n";
	for (int i = 0; i <= 5; i++)
	{

		cout << flo(gen) << endl;
	}

	cout << "integers\n";
	for (int i = 0; i <= 5; i++)
	{

		cout << in(gen) << endl;
	}

    return 0;
}

