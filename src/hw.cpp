#include <iostream>
#include <unistd.h>
#include "hw.h"

int helloWorld()
{
	std::cout << "Hello World" << std::endl;
	sleep(1);
	return 0;
}