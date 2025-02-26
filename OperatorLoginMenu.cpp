/**
* @file OperaterLoginMenu.cpp
* @Author Gürkan Kayý (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "MainMenu.h"
#include "OperatorLoginMenu.h"
#include <iostream>
#include <conio.h>
using namespace std;

//! @param operators is the list of robot operators.
//! @param authorizedUsername is the flag for the username authorization.
//! @param authorizedAccessCode is the flag for the access code authorization.
OperatorLoginMenu::OperatorLoginMenu(const vector<RobotOperator>& operators) : robotOperators(operators), authorizedUsername(false), authorizedAccessCode(false) {}

void OperatorLoginMenu::showMenu() {
    cout << "-------------------------------------------\n";
    cout << "Welcome to Webots Robot Control Application\n";
    cout << "-------------------------------------------\n\n";
    cout << "Operator Login Menu\n";
    cout << "-------------------\n";
    cout << "Please enter your username and access code to use the app!\n\n";
    handleChoice();
}

void OperatorLoginMenu::handleChoice() {
    authorizedUsername = false;
    authorizedAccessCode = false;
    //! @param authorizedOperator is the authorized robot operator.
    RobotOperator authorizedOperator = robotOperators[0];
    do {
        //! @param enteredUsername is a string variable entered by the user.
        string enteredUsername;
        cout << "Please enter your username: ";
        cin >> enteredUsername;

        //! Check if the entered username is valid.
        //! @param robotOperator is a robot operator.
        for (const auto& robotOperator : robotOperators) {
            if (robotOperator.checkUsername(enteredUsername)) {
                authorizedUsername = true;
                authorizedOperator = robotOperator;
                break;
            }
        }

        //! If the entered username is valid, check the access code.
        if (authorizedUsername) {
            //! @param enteredCode is an unsigned integer variable entered by the user.
            unsigned int enteredCode;

            do {
                cout << "Please enter your access code: ";

                //! Hide input for the access code.
                enteredCode = 0;
                char ch;
                while ((ch = _getch()) != '\r') {
                    //! Handle backspace.
                    if (ch == '\b' && enteredCode > 0) {
                        cout << "\b \b";
                        enteredCode /= 10;
                    }
                    else if (isdigit(ch)) {
                        enteredCode = enteredCode * 10 + (ch - '0');
                        cout << '*'; //! Display asterisk instead of the digit.
                    }
                }

                //! Check if the entered access code is valid.
                authorizedAccessCode = authorizedOperator.checkAccessCode(enteredCode);

                //! If the entered access code is invalid, display a message.
                if (!authorizedAccessCode) {
                    cout << endl << "\nAccess code is invalid. Try again.\n";
                }

            } while (!authorizedAccessCode);

            cout << endl << "\nOperator authorized. Access granted.\n";
            cout << "Operator Informations:";
            //! Print the authorized operator's information.
            authorizedOperator.print();
        }
        else {
            cout << "\nUsername not found. Try again.\n";
        }
    } while (!authorizedAccessCode);
}
