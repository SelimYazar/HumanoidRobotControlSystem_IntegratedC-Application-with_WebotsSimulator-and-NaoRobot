/**
* @file NodeTest.cpp
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "Node.h"
#include <iostream>
using namespace std;

//! Tests the Node class.
static void NodeTest() {
    cout << "NodeTest:" << endl;

    //! Create a Pose object.
    Pose pose(1.0, 2.0, 3.0);

    //! Create a Node object.
    //! @param node is a Node object to store the node.
    Node node;
    node.pose = pose;

    //! Print the node data.
    cout << "Node Data: (" << node.pose.getX() << ", " << node.pose.getY() << ", " << node.pose.getTh() << ")" << endl;

    //! Print the next pointer.
    cout << "Next Pointer: " << node.next << endl;
    cout << endl;
}
