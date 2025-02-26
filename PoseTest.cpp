/**
* @file PoseTest.cpp
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "Pose.h"
#include <iostream>
using namespace std;

static void PoseTest() {
    cout << "PoseTest:" << endl;

    //! Create Pose objects.
    //! @param pose1 and pose2 are created with different values.
    Pose pose1(1.0, 2.0, 45.0);
    Pose pose2(2.0, 3.0, 60.0);

    //! Test basic operations.
    //! @param sum and diff are created with the sum and difference of pose1 and pose2.
    Pose sum = pose1 + pose2;
    Pose diff = pose1 - pose2;

    cout << "Sum: (" << sum.getX() << ", " << sum.getY() << ", " << sum.getTh() << ")\n";
    cout << "Difference: (" << diff.getX() << ", " << diff.getY() << ", " << diff.getTh() << ")\n";

    //! Test comparison.
    if (pose1 == pose2) {
        cout << "Poses are equal.\n";
    }
    else {
        cout << "Poses are not equal.\n";
    }

    //! Test distance and angle calculation.
    double distance = pose1.findDistanceTo(pose2);
    double angle = pose1.findAngleTo(pose2);

    cout << "Distance between poses: " << distance << "\n";
    cout << "Angle between poses: " << angle << "\n";
    cout << endl;
}
