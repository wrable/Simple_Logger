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
	char buffor[MAX_LEN];
	tm timeTM = *localtime(&vtime);
	strftime(buffor, MAX_LEN, "%x;%H:%M:%S", &timeTM);
	return (string) buffor;
}

void Logger::cleanLog() {
	logFile.open(LogFileName, ios::out | ios::trunc);
	if (logFile.is_open()) {
		logFile.close();
	} else
		cout << "[Clean_Log] Can't create or open log file !" << endl;
}

void Logger::saveLogToFile(string buffor, string logfile) {
	logFile.open(LogFileName, ios_base::app);
	if (logFile.is_open()) {
		logFile << buffor;
		logFile.close();
	} else
		cout << "[Save_Log_To_File]Can't create or open log file !" << endl;
}

string Logger::generateLog(string type, string msg) {
	stringstream buffor;
	buffor << "["<< type <<"];@" << getlogin() << ";" << getTime() << ";" << msg << endl;
	return buffor.str();
}
void Logger::info(string msg) {
	saveLogToFile(generateLog("Info", msg), LogFileName);
}

void Logger::error(string msg) {
	saveLogToFile(generateLog("Error", msg), LogFileName);
}

void Logger::debug(string msg) {
	saveLogToFile(generateLog("Debug", msg), LogFileName);
}
