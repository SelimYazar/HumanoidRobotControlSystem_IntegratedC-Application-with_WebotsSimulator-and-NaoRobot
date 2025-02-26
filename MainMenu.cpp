/**
* @file MainMenu.cpp
* @Author Hassan Moshtaq (152120181073@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "MainMenu.h"
#include "ConnectionMenu.h"
#include "OperateRobotMenu.h"
#include "SensorMenu.h"
#include "PathMenu.h"
#include "RecordMenu.h"
#include <iostream>
using namespace std;

MainMenu::MainMenu() {}

//! @param subMenus is a vector of Menu pointers.
MainMenu::~MainMenu() {
	for (int i = 0; i < subMenus.size(); i++) {
		delete subMenus[i];
	}
}

//! @param menus is a vector of Menu pointers.
MainMenu::MainMenu(vector<Menu*>& menus) : subMenus(menus), mainChoice(0) {
	subMenus.push_back(new ConnectionMenu());
	subMenus.push_back(new OperateRobotMenu());
	subMenus.push_back(new SensorMenu());
    subMenus.push_back(new PathMenu());
	subMenus.push_back(new RecordMenu());
}

void MainMenu::showMenu() {
    do {
        cout << endl;
        cout << "=== Main Menu ===\n";
        cout << "1. Connection\n";
        cout << "2. Operate Robot\n";
        cout << "3. Sensor\n";
        cout << "4. Path\n";
        cout << "5. Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;
        handleChoice();
    } while (mainChoice != 6);
}

void MainMenu::handleChoice() {
    switch (mainChoice) {
    case 1:
        subMenus[0]->showMenu();
		break;
    case 2:
		subMenus[1]->showMenu();
        break;
    case 3:
        subMenus[2]->showMenu();
		break;
    case 4:
		subMenus[3]->showMenu();
        break;
    case 5:
		subMenus[4]->showMenu();
        break;
    case 6:
        cout << "\nExiting the program...\n";
		break;
    default:
		cout << "\nInvalid choice. Try again.\n";
		break;
    }
}

int MainMenu::getMainChoice() const {
    return mainChoice;
}
