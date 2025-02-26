/**
* @file EncryptionTest.cpp
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "RobotOperator.h"
#include <iostream>
using namespace std;

//! Tests the RobotOperator class.
static void RobotOperatorTest() {
    cout << "RobotOperatorTest:" << endl;

    //! Create a RobotOperator object.
    RobotOperator robotOperator("Gurkan", "Kayi", "Gurr26", 1234);

    //! Test check access code.
    //! @param correctCode is an integer variable to store the correct access code.
    int correctCode = 1234;

    //! Test check access correct code.
    if (robotOperator.checkAccessCode(correctCode)) {
        cout << "Access granted. ";
        robotOperator.print();
    }
    //! Access denied warning.
    else {
        cout << "Access denied." << endl;
    }
    cout << endl;
}
