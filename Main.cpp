/**
* @file Main.cpp
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "NaoRobotAPI.h"
#include "RobotControl.h"
#include "NaoRobotInterface.h"
#include "Menu.h"
#include "MainMenu.h"
#include "ConnectionMenu.h"
#include "OperateRobotMenu.h"
#include "SensorMenu.h"
#include "PathMenu.h"
#include "RecordMenu.h"
#include "OperatorLoginMenu.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    //! Create instances of required classes.
    //! @param robotAPI is a pointer to NaoRobotAPI class.
    //! @param robotControl is an instance of RobotControl class.
    NaoRobotAPI* robotAPI = new NaoRobotAPI();
    RobotControl robotControl;
    NaoRobotInterface* robotINT = new NaoRobotInterface();

    //! Vector to store multiple operators.
    //! @param robotOperators is a vector of RobotOperator class.
    vector<RobotOperator> robotOperators;

    //! Create instances of RobotOperators.
    RobotOperator robotOperator1("Gurkan", "Kayi", "gur26", 1234);

    //! Add operators to the vector.
    robotOperators.push_back(robotOperator1);

    //! Create instances of menu classes.
    //! @param loginMenu is an instance of OperatorLoginMenu class.
    //! @param connectionMenu is an instance of ConnectionMenu class.
    //! @param operateRobotMenu is an instance of OperateRobotMenu class.
    //! @param sensorMenu is an instance of SensorMenu class.
    //! @param pathMenu is an instance of PathMenu class.
    //! @param recordMenu is an instance of RecordMenu class.
    OperatorLoginMenu* loginMenu = new OperatorLoginMenu(robotOperators);
    ConnectionMenu* connectionMenu = new ConnectionMenu(robotAPI, robotControl);
    OperateRobotMenu* operateRobotMenu = new OperateRobotMenu(robotINT);
    SensorMenu* sensorMenu = new SensorMenu(robotAPI);
    PathMenu* pathMenu = new PathMenu();
    RecordMenu* recordMenu = new RecordMenu(robotControl);

    //! Login menu.
    loginMenu->showMenu();

    //! If login is successful, show main menu.
    //! @param mainMenu is an instance of MainMenu class.
    //! @param menus is a vector of Menu class.
    if (loginMenu) {
        vector<Menu*> menus = { connectionMenu, operateRobotMenu, sensorMenu, pathMenu, recordMenu };
        MainMenu mainMenu(menus);
        do {
            mainMenu.showMenu();
            mainMenu.handleChoice();
        } while (mainMenu.getMainChoice() != 6);
    }
    
    //! Delete robotAPI instance.
    delete robotAPI;

    return 0;
}
