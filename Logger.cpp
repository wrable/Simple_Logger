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
	plik.open(logfile, ios::out | ios::trunc);
	if (plik.is_open()) {
		plik.close();
	} else
		cout << "[Clean_Log] Can't create or open log file !" << endl;
}

void Logger::saveLogToFile(string buffer, string logfile) {
	plik.open(logfile, ios_base::app);
	if (plik.is_open()) {
		plik << buffer;
		plik.close();
	} else
		cout << "[Save_Log_To_File]Can't create or open log file !" << endl;
}

string Logger::generateLog(string type, string msg) {
	stringstream buffer;
	buffer << "["<< type <<"];@" << getlogin() << ";" << getTime() << ";" << msg << endl;
	return buffer.str();
}
void Logger::info(string msg) {
	saveLogToFile(generateLog("Info", msg), logfile);
}

void Logger::error(string msg) {
	saveLogToFile(generateLog("Error", msg), logfile);
}

void Logger::debug(string msg) {
	saveLogToFile(generateLog("Debug", msg), logfile);
}
