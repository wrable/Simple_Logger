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
#include <memory>

using namespace std;

class Logger {
private:
	fstream logFile;
	string LogFileName = "log.txt";
	size_t MAX_LEN = 80;
	string getTime();
	string generateLog(string type, string msg);
	bool saveLogToFile(string msg,string logfile);
public:
	bool info(string msg);
	bool error(string msg);
	bool debug(string msg);
	bool cleanLog();

	Logger();
	virtual ~Logger();

};

#endif /* LOGGER_H_ */
