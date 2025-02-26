/**
* @file PathMenu.h
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief PathMenu class to be used in robot applications to use path menu.
* 
* PathMenu class is used to create a menu for the user to choose the path.
* It is derived from the Menu class.
* It has a Path object to be used in the menu.
* It has a Pose object to be used in the menu.
* It has a pathChoice variable to be used in the menu.
* It has a showMenu function and a handleChoice function.
*/

#ifndef PATHMENU_H
#define PATHMENU_H

#include "Menu.h"
#include "Path.h"
#include "Pose.h"
#include "RobotControl.h"

class PathMenu : public Menu {
private:
    //! Path object to be used in the menu.
    Path path;
    //! Pose object to be used in the menu.
    Pose pose;
    //! RobotControl object to be used in the menu.
    RobotControl robotControl;
    //! pathChoice variable to be used in the menu.
    int pathChoice;

public:
    //! Constructor of PathMenu class.
    PathMenu();
    //! Shows path menu.
    void showMenu() override;
    //! Handles the choice of the user.
    void handleChoice() override;
};

#endif // PATHMENU_H
