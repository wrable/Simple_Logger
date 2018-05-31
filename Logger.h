/*
 * Logger.h
 *
 *  Created on: 31 maj 2018
 *      Author: wrable
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <time.h>
#include <sstream>
using namespace std;

class Logger {
private:
	fstream plik;
	string logfile = "log.txt";
	string Get_Time();
	string Generate_Log(string type, string msg);
	void Save_Log_To_File(string msg,string logfile);
public:
	void Info(string msg);
	void Error(string msg);
	void Debug(string msg);
	void Clean_Log();

	Logger();
	virtual ~Logger();

};

#endif /* LOGGER_H_ */
