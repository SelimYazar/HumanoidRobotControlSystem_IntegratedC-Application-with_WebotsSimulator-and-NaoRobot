/**
* @file Record.h
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief Record class to be used in robot applications to write data to a file and read from a file.
*
* Record class is used to read and write data to a file. It has a file name and a file object.
* The file is opened by the openFile function.
* The file is closed by the closeFile function.
* The file name is set by the setFileName function.
* The data is read from the file by the readLine function.
* The data is written to the file by the writeLine function.
* The data is written to the file by the << operator.
* The data is read from the file by the >> operator.
*/

#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <fstream>
using namespace std;

class Record {
private:
	//! @param fileName is a string variable to store the name of the file.
	string fileName;
	//! @param file is an ifstream variable to store the file object.
	fstream file;

public:
	//! A constructor with a parameter.
	Record(const string& name);
	//! A constructor.
	Record();
	//! A destructor.
	~Record();
	//! A constructor.
	bool openFile();
	//! A destructor.
	bool closeFile();
	//! Sets the file name.
	void setFileName(const string& name);
	//! Reads a line from the file.
	string readLine();
	//! Writes a line to the file.
	bool writeLine(const string& str);
	//! Writes lines to the file.
	Record& operator<<(const string& data);
	//! Reads lines from the file.
	Record& operator>>(string& data);
};

#endif // !RECORD_H
