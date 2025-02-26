/**
* @file MainMenu.h
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief MainMenu class to be used in robot applications to control main menu.
* 
* MainMenu class is used to control the main menu of the robot application.
* It is derived from Menu class.
* It has a vector to store instances of different menus.
* It has a constructor, a destructor, a showMenu function, a handleChoice function and a getMainChoice function.
*/

#ifndef MAINMENU_H
#define MAINMENU_H

#include "Menu.h"
#include <vector>
using namespace std;

class MainMenu : public Menu {
private:
    //! A vector to store instances of different menus.
    vector<Menu*> subMenus;
    //! An integer to store the choice of the user.
    int mainChoice;

public:
    //! A constructor.
    MainMenu();
    //! A destructor.
    ~MainMenu();
    //! A constructor with parameters.
    MainMenu(vector<Menu*>& menus);
    //! Shows the main menu.
    void showMenu() override;
    //! Handles the choice of the user.
    void handleChoice() override;
    //! Returns the choice of the user.
    int getMainChoice() const;
};

#endif // MAINMENU_H
