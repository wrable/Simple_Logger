//============================================================================
// Name        : Logger.cpp
// Author      : Krzysztof Wróblewski
// Version     :
// Copyright   : Your copyright notice
// Description : This is example how to use logger..
//============================================================================

#include <iostream>
#include "lib/Logger.h"
using namespace std;

int main() {
	cout << "Example logger program" << endl; // prints !!!Hello World!!!
	Logger Logger;
	cout << Logger.cleanLog() << endl;
	cout << Logger.error("to jest error");
	Logger.info("to jest info");
	Logger.debug("to jest debug");

	return 0;
}
