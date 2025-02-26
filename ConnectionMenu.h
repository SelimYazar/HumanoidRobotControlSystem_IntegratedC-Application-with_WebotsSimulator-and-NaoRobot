/**
* @file ConnectionMenu.h
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief ConnectionMenu class to be used in robot applications to control connection.
* 
* ConnectionMenu class to be used in robot applications to control connection.
* It is derived from Menu class.
* It has a NaoRobotAPI object and a RobotControl object.
* It has a showMenu function to show menu and a handleChoice function to handle user choice.
*/

#ifndef CONNECTIONMENU_H
#define CONNECTIONMENU_H

#include "Menu.h"
#include "NaoRobotAPI.h"
#include "RobotControl.h"

class ConnectionMenu : public Menu {
private:
    //! NaoRobotAPI object to be used in connection menu.
    NaoRobotAPI* robotAPI;
    //! RobotControl object to be used in connection menu.
    RobotControl robotControl;
    //! User choice to be used in connection menu.
    int connectionChoice;

public:
    //! Default constructor of ConnectionMenu class.
    ConnectionMenu();
    //! Constructor of ConnectionMenu class.
    ConnectionMenu(NaoRobotAPI* robotAPI, RobotControl robotControl);
    //! Shows the connection menu.
    void showMenu() override;
    //! Handles user choices.
    void handleChoice() override;
};

#endif CONNECTIONMENU_H
