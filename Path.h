/**
* @file Path.h
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief Path class to be used in robot applications to get and manage the path of the robot.
* 
* Path class is used to get and manage the path of the robot.
* It has Node* tail, Node* head and int number variables.
* It has addPos, print, operator[], getPos, removePos, insertPos, operator<< and operator>> functions.
*/

#ifndef PATH_H
#define PATH_H

#include "Pose.h"
#include <iostream>
using namespace std;

class Node;

class Path {
private:
    //! @param tail is a Node* variable to store the tail of the path.
    Node* tail;
    //! @param head is a Node* variable to store the head of the path.
    Node* head;
    //! @param number is an integer variable to store the number of the poses in the path.
    int number;

public:
    //! A constructor.
    Path();
    //! A destructor.
    ~Path();
    //! Adds the given pose to the path.
    void addPos(const Pose& pose);
    //! Prints the path.
    void print() const;
    //! Returns the pose at the given index.
    const Pose& operator[](int index) const;
    //! Returns the pose at the given index.
    const Pose& getPos(int index) const;
    //! Removes the pose at the given index.
    bool removePos(int index);
    //! Inserts the given pose to the given index.
    bool insertPos(int index, const Pose& pose);
    //! Prints the path.
    friend ostream& operator<<(ostream& os, const Path& path);
    //! Reads the path.
    friend istream& operator>>(istream& is, Path& path);
    //! Gets the size of the path.
    int getSize();
};

#endif // PATH_H
