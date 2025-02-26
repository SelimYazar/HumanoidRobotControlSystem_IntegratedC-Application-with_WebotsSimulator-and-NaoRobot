/**
* @file RobotOperator.cpp
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "RobotOperator.h"
#include "Encryption.h"
#include <iostream>
using namespace std;

vector<RobotOperator> RobotOperator::robotOperators;

int RobotOperator::encryptCode(int code) {
    return Encryption::encrypt(code);
}

int RobotOperator::decryptCode(int code) {
    return Encryption::decrypt(code);
}

//! @param n is a string variable to store the name of the operator.
//! @param s is a string variable to store the surname of the operator.
//! @param uname is a string variable to store the username of the operator.
//! @param code is an integer variable to store the access code of the operator.
RobotOperator::RobotOperator(const string& n, const string& s, const string& u, unsigned int code)
    : name(n), surname(s), username(u), accessCode(encryptCode(code)), accessState(true) {
    robotOperators.push_back(*this);
}

bool RobotOperator::checkUsername(const string& uname) const {
    return (username == uname);
}

bool RobotOperator::checkAccessCode(int code) {
    return accessCode == encryptCode(code);
}

void RobotOperator::print() {
    cout << "\nName: " << name << "\nSurname: " << surname << "\nAccess State: " << accessState << endl;
}
