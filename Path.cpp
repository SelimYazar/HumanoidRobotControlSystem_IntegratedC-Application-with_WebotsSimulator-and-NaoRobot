/**
* @file Path.cpp
* @Author Selim Can Yazar (152120191023@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "Path.h"
#include "Node.h"

Path::Path() : tail(nullptr), head(nullptr), number(0) {}

//! @param current is a Node* variable to store the current node of the path.
//! @param next is a Node* variable to store the next node of the path.
Path::~Path() {
    Node* current = head;
    Node* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    tail = nullptr;
    head = nullptr;
    number = 0;
}

//! @param pose is a Pose variable to store the pose of the path.
//! @param newNode is a Node* variable to store the new node of the path.
void Path::addPos(const Pose& pose) {
    Node* newNode = new Node{ nullptr, pose };

    if (tail == nullptr) {
        tail = newNode;
        head = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    number++;
}

void Path::print() const {
    Node* current = head;

    while (current != nullptr) {
        cout << "(" << current->pose.getX() << ", " << current->pose.getY() << ", " << current->pose.getTh() << ") ";
        current = current->next;
    }
    cout << endl;
}

//! @param count is an integer variable to store the index of the path.
const Pose& Path::operator[](int index) const {
    Node* current = head;
    int count = 0;

    while (current != nullptr) {
        if (count == index) {
            return current->pose;
        }
        current = current->next;
        count++;
    }

    throw out_of_range("Index out of bounds");
}

//! @param index is an integer variable to store the index of the path.
const Pose& Path::getPos(int index) const {
    return (*this)[index];
}

//! @param previous is a Node* variable to store the previous node of the path.
bool Path::removePos(int index) {
    if (index < 0 || index >= number) {
        return false;
    }
    Node* current = head;
    Node* previous = nullptr;
    int count = 0;

    while (current != nullptr) {
        if (count == index) {
            if (previous == nullptr) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }

            if (current == tail) {
                tail = previous;
            }

            delete current;
            number--;
            return true;
        }

        previous = current;
        current = current->next;
        count++;
    }

    return false;
}

bool Path::insertPos(int index, const Pose& pose) {
    if (index < 0 || index > number) {
        return false;
    }

    Node* newNode = new Node{ nullptr, pose };

    if (index == 0) {
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }
    }
    else {
        Node* current = head;
        Node* previous = nullptr;
        int count = 0;

        while (current != nullptr) {
            if (count == index) {
                previous->next = newNode;
                newNode->next = current;

                if (current == tail) {
                    tail = newNode;
                }

                number++;
                return true;
            }
            previous = current;
            current = current->next;
            count++;
        }
    }
    return false;
}

//! @param os is an ostream variable to store the output stream.
//! @param path is a Path variable to store the path.
ostream& operator<<(ostream& os, const Path& path) {
    Node* current = path.head;

    while (current != nullptr) {
        os << "(" << current->pose.getX() << ", " << current->pose.getY() << ", " << current->pose.getTh() << ") ";
        current = current->next;
    }
    return os;
}

//! @param is is an istream variable to store the input stream.
//! @param x is a double variable to store the x coordinate of the pose.
//! @param y is a double variable to store the y coordinate of the pose.
//! @param th is a double variable to store the orientation of the pose.
istream& operator>>(istream& is, Path& path) {
    double x, y, th;
    is >> x >> y >> th;
    Pose pose(x, y, th);
    path.addPos(pose);
    return is;
}

int Path::getSize() {
	return number;
}
