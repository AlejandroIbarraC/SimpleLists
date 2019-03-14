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
/**
 * Fisrt definition of the node and its head
 */
private:
    Node *head,*tail;
    int length;
/**
 *
 * @param head
 * @param result
 * This Method dislays the node and basically inizialited it and its head
 */
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

    /**
     * Get the head of the node
     * @return
     */
    Node * gethead() {
        return head;
    }
/**
 * Definition of the collector itself
 */
public:
    Collector() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    /**
     *
     * @param toDelete
     * This Method was created in order to set free the information in the nodes
     */
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

    /**
     * Static parameter get instance of the collector
     * @return
     */
    static Collector& getInstance(){
        static Collector theInstance;
        return theInstance;
    }
    /**
     *
     * @return
     * This method was created in order to obtain the information in one node
     */
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
    /**
     *
     * @param toDel
     * Method that delete a certain node position
     */
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
    /**
     *
     * This method displays the head of the node
     */
    void display() {
        if (gethead() == NULL) {
            cout << "Collector is empty" << endl;
        } else {
            display_aux(gethead(), "[");
        }
    }

};


#endif //LISTS_COLLECTOR_H
