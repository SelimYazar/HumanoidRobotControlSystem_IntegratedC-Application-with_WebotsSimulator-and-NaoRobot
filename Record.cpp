/**
* @file Record.cpp
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "Record.h"
#include <iostream>
using namespace std;

Record::Record(const string& name) {
	setFileName(name);
	openFile();
}

Record::Record() {}

Record::~Record() {}

bool Record::openFile() {
    file.open(fileName, ios::in | ios::out | ios::app);

    if (!file.is_open()) {
        cout << "\nError opening file: " << fileName << endl;
        return false;
    }
    return true;
}

bool Record::closeFile() {
    file.close();
    return true;
}

//! @param name is a string variable to store the name of the file.
void Record::setFileName(const string& name) {
    fileName = name;
}

//! @param line is a string variable to store the line read from the file.
string Record::readLine() {
    string line;
    if (getline(file, line)) {
        return line;
    }
    else {
        //! Handle end-of-file or other errors.
        return "";
    }
}

//! @param str is a string variable to store the line to be written to the file.
bool Record::writeLine(const string& str) {
    file << str << endl;
    return true;
}

//! @param data is a string variable to store the line to be written to the file.
Record& Record::operator<<(const string& data) {
    writeLine(data);
    return *this;
}

//! @param data is a string variable to store the line read from the file.
Record& Record::operator>>(string& data) {
    data = readLine();
	return *this;
}
