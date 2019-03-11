//
// Created by Alejandro Ibarra on 2019-03-07.
//

#ifndef LISTS_COLLECTOR_H
#define LISTS_COLLECTOR_H
#include <iostream>
#include "Node.cpp"
#include <sstream>
#include <string>

using namespace std;

class Collector {

private:
    Node *head,*tail;
    int length;

    void display_aux(Node *head, string result) {
        if (head == NULL) {
            result.erase(result.size() - 2);
            result.append("]");
            cout << result << endl;
        }
        else {
            ostringstream address;
            address << (void const *)head->data;
            string current = address.str();
            result.append(current);
            result.append(", ");
            display_aux(head->next, result);
        }
    }

    Node * gethead() {
        return head;
    }

public:
    Collector() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void freeMemory (Node *toDelete) {
        if (head == NULL) {
            toDelete->next = NULL;
            toDelete->prev = NULL;
            head = toDelete;
            tail = toDelete;
        }
        else {
            toDelete->next = NULL;
            toDelete->prev = NULL;
            tail->next = toDelete;
            tail = tail->next;
        }
        length += 1;
    }

    static Collector& getInstance(){
        static Collector theInstance;
        return theInstance;
    }

    Node* getMemory() {
        Node *result;
        if (gethead() == NULL) {
            result = new Node;
        } else {
            result = gethead();
            del(result);
        }
        return result;
    }

    void del (Node *toDel) {
        if (toDel == head) {
            Node *temp;
            temp = head;
            head = head->next;
        } else {
            toDel->prev->next = toDel->next;
        }
        length -=1;
    }

    void display() {
        if (gethead() == NULL) {
            cout << "Collector is empty" << endl;
        } else {
            display_aux(gethead(), "[");
        }
    }

};


#endif //LISTS_COLLECTOR_H
