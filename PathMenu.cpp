/**
* @file PathMenu.cpp
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "PathMenu.h"
#include <iostream>
using namespace std;

PathMenu::PathMenu() : pathChoice(0) {}

void PathMenu::showMenu() {
    do {
		cout << endl;
		cout << "=== Path Menu ===\n";
		cout << "1. Add Pose\n";
		cout << "2. Print Path\n";
		cout << "3. Get Pose at Index\n";
		cout << "4. Remove Pose at Index\n";
		cout << "5. Insert Pose at Index\n";
        cout << "6. Add to Path\n";
        cout << "7. Clear Path\n";
		cout << "8. Back to Main Menu\n";
		cout << "Enter your choice: ";
		cin >> pathChoice;
		handleChoice();
	} while (pathChoice != 8);
}

void PathMenu::handleChoice() {
    switch (pathChoice) {
    case 1: {
        //! @param x is the x coordinate of the pose.
        //! @param y is the y coordinate of the pose.
        //! @param th is the orientation of the pose.
        double x, y, th;
        cout << "\nEnter x for the pose: ";
        cin >> x;
        cout << "Enter y for the pose: ";
        cin >> y;
        cout << "Enter th for the pose: ";
        cin >> th;
        //! @param pose is the pose to be added to the path.
        Pose pose(x, y, th);
        path.addPos(pose);
        cout << "\nPose added to the path.\n";
        break;
    }
    case 2:
        cout << endl;
        if (path.getSize() > 0) {
            cout << "Path printed:\n";
            path.print();
        }
        else {
			cout << "Path is empty.\n";
		}
        break;
    case 3: {
        //! @param index is the index of the pose to be returned.
        int index;
        cout << "\nEnter the index to get the pose: ";
        cin >> index;

        //! try-catch block to handle out of range exception.
        try {
            const Pose& pose = path[index];
            cout << "\nPose at index " << index << ": " << pose << endl;
        }
        catch (const out_of_range& e) {
            cout << "\nInvalid index. " << e.what() << endl;
        }
        break;
    }
    case 4: {
        int index;
        cout << "\nEnter the index to remove the pose: ";
        cin >> index;

        if (path.removePos(index)) {
            cout << "\nPose removed from the path.\n";
        }
        else {
            cout << "\nInvalid index. Pose not removed.\n";
        }
        break;
    }
    case 5: {
        int index;
        cout << "\nEnter the index to insert the pose: ";
        cin >> index;

        double x, y, th;
        cout << "\nEnter x for the pose: ";
        cin >> x;
        cout << "Enter y for the pose: ";
        cin >> y;
        cout << "Enter th for the pose: ";
        cin >> th;
        Pose pose(x, y, th);

        if (path.insertPos(index, pose)) {
            cout << "\nPose inserted into the path.\n";
        }
        else {
            cout << "\nInvalid index. Pose not inserted.\n";
        }
        break;
    }
    case 6:
        robotControl.addToPath();
		break;
    case 7:
		robotControl.clearPath();
		break;
    case 8:
        cout << "\nBack to Main Menu.\n";
        break;
    default:
        cout << "\nInvalid choice. Please try again.\n";
        break;
    }
}
