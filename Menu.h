/**
* @file Menu.h
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief Menu class to be used in robot applications to control menu.
*
* Menu class is used to control the menu of the robot application.
* It is an abstract class and it has two pure virtual functions.
* It is inherited by MainMenu and SubMenu classes.
*/

#ifndef MENU_H
#define MENU_H

class Menu {
public:
    //! Pure virtual function to display the menu.
    virtual void showMenu() = 0;
    //! Pure virtual function to handle the choice.
    virtual void handleChoice() = 0;
    //! Virtual destructor.
    virtual ~Menu() {}
};

#endif // MENU_H
