/**
* @file RecordMenu.h
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief RecordMenu class to be used in robot applications to read sth from a file and write to a file.
* 
* RecordMenu class to be used for reading sth from a file and writing to a file.
* It is derived from Menu class.
* It has a Record object and a RobotControl object.
* It has a recordChoice variable to be used in switch-case.
* It has a showMenu function and a handleChoice function.
* It has also a readFromFile function and a writeToFile function.
*/

#ifndef RECORDMENU_H
#define RECORDMENU_H

#include "Menu.h"
#include "Record.h"
#include "RobotControl.h"

class RecordMenu : public Menu {
private:
    //! Record object to be used in RecordMenu class.
    Record record;
    //! RobotControl object to be used in RecordMenu class.
    RobotControl robotControl;
    //! recordChoice variable to be used in switch-case.
    int recordChoice;

public:
    //! Constructor of RecordMenu class.
    RecordMenu();
    //! Constructor of RecordMenu class with parameters.
    RecordMenu(RobotControl control);
    //! Shows record menu to user.
    void showMenu() override;
    //! Handles user's choice.
    void handleChoice() override;
    //! Reads from a file.
    void readFromFile();
    //! Writes to a file.
    void writeToFile();
};

#endif // RECORDMENU_H
