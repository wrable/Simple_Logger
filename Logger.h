/*
 * Logger.h
 *
 *  Created on: 31 maj 2018
 *      Author: wrable
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <unistd.h>
#include <ctime>
#include <sstream>
using namespace std;

class Logger {
private:
	fstream plik;
	string logfile = "log.txt";
	int MAX_LEN = 80;
	string getTime();
	string generateLog(string type, string msg);
	void saveLogToFile(string msg,string logfile);
public:
	void info(string msg);
	void error(string msg);
	void debug(string msg);
	void cleanLog();

	Logger();
	virtual ~Logger();

};

#endif /* LOGGER_H_ */
