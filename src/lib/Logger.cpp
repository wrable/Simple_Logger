/*
 * Logger.cpp
 *
 *  Created on: 31 maj 2018
 *      Author: wrable
 */

#include "Logger.h"

Logger::Logger() {
}

Logger::~Logger() {
}
string Logger::getTime() {
	time_t vtime = time(nullptr);
	char *buffor = new char[MAX_LEN];
	tm timeTM = *localtime(&vtime);
	strftime(buffor, MAX_LEN, "%x;%H:%M:%S", &timeTM);
	delete[] buffor;
	return (string) buffor;
}

bool Logger::cleanLog() {
	logFile.open(LogFileName, ios::out | ios::trunc);
	if (logFile.is_open()) {
		logFile.close();
		return true;
	} else{
		cout << "[Clean_Log] Can't create or open log file !" << endl;
		return false;
	}
}


bool Logger::saveLogToFile(string buffor, string logfilename) {
	logFile.open(logfilename, ios_base::app);
	if (logFile.is_open()) {
		logFile << buffor;
		logFile.close();
		return true;
	}else{
		cout << "[Save_Log_To_File]Can't create or open log file !" << endl;
		return false;
	}
}


string Logger::generateLog(string type, string msg) {
	stringstream buffor;
	buffor << "["<< type <<"];@" << getlogin() << ";" << getTime() << ";" << msg << endl;
	return buffor.str();
}
bool Logger::info(string msg) {
	return saveLogToFile(generateLog("Info", msg), LogFileName);
}

bool Logger::error(string msg) {
	return saveLogToFile(generateLog("Error", msg), LogFileName);
}

bool Logger::debug(string msg) {
	return saveLogToFile(generateLog("Debug", msg), LogFileName);
}
