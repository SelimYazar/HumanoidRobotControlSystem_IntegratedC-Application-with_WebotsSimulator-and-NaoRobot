/**
* @file OperateRobotMenu.h
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief OperateRobotMenu class to be used in robot applications to operate the robot.
*
* OperateRobotMenu class is used to operate the robot.
* It is derived from Menu class.
* It has a RobotControl object to operate the robot.
*/

#ifndef OPERATEROBOTMENU_H
#define OPERATEROBOTMENU_H

#include "Menu.h"
#include "RobotControl.h"
#include "NaoRobotInterface.h"

class OperateRobotMenu : public Menu {
private:
    //! NaoRobotInterface object to operate the robot.
    NaoRobotInterface* robotINT;
    //! RobotControl object to operate the robot.
    RobotControl robotControl;
    //! Robot choice to be used in switch-case.
    int robotChoice;

public:
    //! Default constructor.
    OperateRobotMenu();
    //! Constructor with RobotControl object.
    OperateRobotMenu(NaoRobotInterface* robotINT);
    //! Shows operate robot menu.
    void showMenu() override;
    //! Handles operate robot menu choices.
    void handleChoice() override;
};

#endif //OPERATEROBOTMENU_H
