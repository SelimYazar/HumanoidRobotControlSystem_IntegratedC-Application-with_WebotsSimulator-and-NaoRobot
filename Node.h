/**
* @file Node.h
* @Author Umutcan Cakmak (152120191006@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief Node class to be used in robot applications to node the pose of the robot.
* 
* Node class is used to store the pose of the robot.
* It has a pointer to the next node and a Pose object to store the pose of the node.
*/

#ifndef NODE_H
#define NODE_H

#include "Pose.h"

class Node {
public:
    //! @param next is a pointer to Node class to store the next node.
    Node* next;
    //! @param pose is a Pose object to store the pose of the node.
    Pose pose;
};

#endif // NODE_H
