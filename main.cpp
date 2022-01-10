// #include <iostream>
#include "inc/hw.h"
#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char** argv)
{
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	helloWorld();
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	cout << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " s. \n";
	return 0;
}