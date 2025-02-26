/**
* @file OperaterLoginMenu.h
* @Author Gürkan Kayý (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief OperaterLoginMenu class to be used in robot applications to login as an operator.
* 
* OperatorLoginMenu class is used to login as an operator.
* It is derived from Menu class.
* It has a vector of RobotOperator objects to store the operators.
* It has a RobotOperator object.
* It has two boolean variables to check if the username and access code are correct.
* It has a constructor to initialize the vector of RobotOperator objects.
* It has a showMenu function and handleChoice function.
*/

#ifndef OPERATERLOGINMENU_H
#define OPERATERLOGINMENU_H

#include "Menu.h"
#include "RobotOperator.h"
#include <vector>
using namespace std;

class OperatorLoginMenu : public Menu {
private:
    //! A vector of RobotOperator objects to store the operators.
    vector<RobotOperator> robotOperators;
    //! A RobotOperator object.
    RobotOperator authorizedOperator;
    //! A boolean variable to check if the username is correct.
    bool authorizedUsername;
    //! A boolean variable to check if the access code is correct.
    bool authorizedAccessCode;

public:
    //! A constructor.
    OperatorLoginMenu(const vector<RobotOperator>& operators);
    //! Shows operator login menu.
    void showMenu() override;
    //! Handles the choice of the user.
    void handleChoice() override;
};

#endif // OPERATERLOGINMENU_H
