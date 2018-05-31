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
string Logger::Get_Time() {
	time_t czas;
	time(&czas);
	char buffor[80];
	tm czasTM = *localtime(&czas);
	strftime(buffor, 80, "%x;%H:%M:%S", &czasTM);
	return (string) buffor;
}

void Logger::Clean_Log() {
	plik.open(logfile, ios::out | ios::trunc);
	if (plik.is_open()) {
		plik.close();
	} else
		cout << "[Clean_Log] Can't create or open log file !" << endl;
}

void Logger::Save_Log_To_File(string buffer, string logfile) {
	plik.open(logfile, ios_base::app);
	if (plik.is_open()) {
		plik << buffer;
		plik.close();
	} else
		cout << "[Save_Log_To_File]Can't create or open log file !" << endl;
}

string Logger::Generate_Log(string type, string msg) {
	stringstream buffer;
	buffer << "["<< type <<"];@" << getlogin() << ";" << Get_Time() << ";" << msg << endl;
	return buffer.str();
}
void Logger::Info(string msg) {
	Save_Log_To_File(Generate_Log("Info", msg), logfile);
}

void Logger::Error(string msg) {
	Save_Log_To_File(Generate_Log("Error", msg), logfile);
}

void Logger::Debug(string msg) {
	Save_Log_To_File(Generate_Log("Debug", msg), logfile);
}
