/**
* @file RecordTest.cpp
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "Record.h"
#include <iostream>
#include <fstream>
using namespace std;

//! Tests the Record class.
static void RecordTest() {
    cout << "RecordTest:" << endl;

    //! Create a Record object.
    Record record;
    //! Set the file name.
    record.setFileName("testfile.txt");

    //! Test open file.
    if (record.openFile()) {
        cout << "File opened successfully." << endl;

        //! Test write line.
        record << "Test Line 1";
        record << "Test Line 2";

        //! Reset file position to the beginning.
        record.closeFile();
        record.openFile();

        //! Test read a line.
        //! @param data is a string variable to store the line read from the file.
        cout << "Read from file:" << endl;
        string data;
        record >> data;
        cout << data << endl;

        //! Test close file.
        record.closeFile();
        cout << "File closed successfully." << endl;
    }
    //! An error occured while opening the file.
    else {
        cout << "Error opening file." << endl;
    }
    cout << endl;
}
