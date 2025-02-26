/**
* @file RecordMenu.cpp
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "RecordMenu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <streambuf>
#include <string>
using namespace std;

RecordMenu::RecordMenu() {}

//! @param control RobotControl object.
RecordMenu::RecordMenu(RobotControl control) : robotControl(control) {}

void RecordMenu::showMenu() {
	do {
		cout << endl;
		cout << "=== Record Menu ===\n";
        cout << "1. Read From File\n";
        cout << "2. Write To File\n";
        cout << "3. Record Path\n";
		cout << "4. Back to Main Menu\n";
		cout << "Enter your choice: ";
		cin >> recordChoice;
		handleChoice();
	} while (recordChoice != 4);
}

void RecordMenu::handleChoice() {
    switch (recordChoice) {
    case 1:
        readFromFile();
        break;
    case 2:
        writeToFile();
        break;
    case 3:
		robotControl.recordPathToFile();
		break;
    case 4:
        cout << "\nBack to Main Menu.\n";
        break;
    default:
        cout << "\nInvalid choice. Please try again.\n";
        break;
    }
}

void RecordMenu::readFromFile() {
    //! @param fileName Name of the file to read from.
    string fileName;
    cout << "\nEnter the file name to read from: ";
    cin >> fileName;

    //! Set the file name for the Record class.
    record.setFileName(fileName);

    //! Open the file.
    if (record.openFile()) {
        //! Read all lines from the file.
        //! @param data is to read from the file.
        string data;
        while (!(data = record.readLine()).empty()) {
            cout << "Read from file: " << data << endl;
        }

        //! Close the file.
        record.closeFile();
    }
}

void RecordMenu::writeToFile() {
    //! @param fileName is the name of the file to write to.
    //! @param data is to write to the file.
    string fileName, data;
    cout << "\nEnter the file name to write to: ";
    cin >> fileName;

    //! Set the file name for the Record class.
    record.setFileName(fileName);

    //! Open the file.
    if (record.openFile()) {
        //! Get data from the user.
        cout << "Enter data to write to the file: ";
        cin.ignore(); //! Ignore the newline character from the previous input.
        getline(cin, data);

        //! Write data to the file.
        record << data;
        cout << "\nWrite to file successful.\n";

        //! Close the file.
        record.closeFile();
    }
}
