// ConsoleApplication25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;
int main()
{

	int myInts[] = { 37,12,5,78,2,1,14 };

	vector<int> myvector(myInts, myInts + 7);
	sort(myvector.begin(), myvector.begin() + 3); // ((5,12,37),78,2,1,14)
	//sort(myvector.begin(), myvector.end()); // (1,2,5,12,14,37,78)
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		cout << ' ' << *it;

    return 0;
}

