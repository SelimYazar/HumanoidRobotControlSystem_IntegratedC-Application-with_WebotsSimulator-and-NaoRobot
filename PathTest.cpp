/**
* @file PathTest.cpp
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "Path.h"
#include <iostream>
using namespace std;

//! Tests the Path class.
static void PathTest() {
    cout << "PathTest:" << endl;

    //! Create a Path object.
    Path path;

    //! Create Pose objects.
    Pose pose1(1.0, 2.0, 45.0);
    Pose pose2(3.0, 4.0, 90.0);
    Pose pose3(5.0, 6.0, 135.0);

    //! Add positions to the path.
    path.addPos(pose1);
    path.addPos(pose2);
    path.addPos(pose3);

    //! Print the original path.
    cout << "Original Path:" << endl;
    path.print();

    //! Get and print the position at index 1.
    Pose poseAtIndex1 = path.getPos(1);
    cout << "Position at index 1: (" << poseAtIndex1.getX() << ", " << poseAtIndex1.getY() << ", " << poseAtIndex1.getTh() << ")" << endl;

    //! Insert a new position at index 1.
    Pose newPose(7.0, 8.0, 180.0);
    path.insertPos(1, newPose);

    //! Print the path after insertion.
    cout << "\nPath after insertion:" << endl;
    path.print();

    //! Remove the position at index 2.
    path.removePos(2);

    //! Print the path after removal.
    cout << "\nFinal Path:" << endl;
    path.print();
    cout << endl;
}
