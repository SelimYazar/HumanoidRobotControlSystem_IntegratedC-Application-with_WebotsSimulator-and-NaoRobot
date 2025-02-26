/**
* @file RobotOperator.h
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief RobotOperator class to be used in robot applications to authorize the operator who will control the robot.
*
* RobotOperator class is used to authorize the operator who will control the robot. It has a name, surname, access code and access state.
* The access code is encrypted and decrypted by the Encryption class.
* The access state is true if the access code is correct, otherwise it is false.
* The access code is set by the constructor.
* The access state is checked by the checkAccessCode function.
* The operator's information is printed by the print function.
*/

#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H

#include <string>
#include <vector>
using namespace std;

class RobotOperator {
private:
    //! @param name is a string variable to store the name of the operator.
    string name;
    //! @param surname is a string variable to store the surname of the operator.
    string surname;
	//! @param username is a string variable to store the username of the operator.
    string username;
    //! @param accessCode is an integer variable to store the access code of the operator.
    unsigned int accessCode;
    //! @param accessState is a boolean variable to store the access state of the operator.
    bool accessState;
    //! Encrypts the given code.
    int encryptCode(int code);
    //! Decrypts the given code.
    int decryptCode(int code);
    //! Static vector to store multiple operators.
    //! @param operators is a static vector to store multiple operators.
    static vector<RobotOperator> robotOperators;

public:
    //! A default constructor.
    RobotOperator() = default;
    //! A constructor.
    RobotOperator(const string& n, const string& s, const string& u, unsigned int code);
    //! Checks the given username with the username.
    bool checkUsername(const string& uname) const;
    //! Checks the given code with the access code.
    bool checkAccessCode(int code);
    //! Prints the operator's information.
    void print();
};

#endif // ROBOTOPERATOR_H
