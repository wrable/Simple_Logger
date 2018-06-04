//============================================================================
// Name        : Logger.cpp
// Author      : Krzysztof Wróblewski
// Version     :
// Copyright   : Your copyright notice
// Description : This is example how to use logger..
//============================================================================

#include <iostream>
#include "logger.h"
using namespace std;

int main() {
	cout << "Example logger program \n " << endl; // prints !!!Hello World!!!
	Logger Logger;
	Logger.cleanLog();
	Logger.error("to jest error");
	Logger.info("to jest info");
	Logger.debug("to jest debug");

	return 0;
}
