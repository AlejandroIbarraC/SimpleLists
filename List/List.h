//
// Created by Alejandro Ibarra on 2019-03-07.
//

#ifndef LISTS_LIST_H
#define LISTS_LIST_H
#include <iostream>
#include "Node.cpp"
#include "Collector.cpp"

using namespace std;

class List {

private:
    Node *head,*tail;
    int length;

    /**
     * Displays the node itself in firs instance
     * @param head
     * @param result
     */
    void display_aux(Node *head, string result) {
        if(head == NULL) {
            result.erase(result.size() - 2);
            result.append("]");
            cout << result << endl;
        }
        else {
            string current = to_string(head->data);
            result.append(current);
            result.append(", ");
            display_aux(head->next, result);
        }
    }

    /**
     * First definition of the list
     */
public:
    List() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    /**
     * This method adds a new space of data in a node
     * @param n
     */
    void add(int n) {
        Collector& thanos = Collector::getInstance();
        Node *tmp = thanos.getMemory();
        tmp->data = n;
        tmp->next = NULL;
        tmp->prev = tail;
        length += 1;

        if(head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    /**
     * Deletes the node an its information
     * @param toDel
     */
    void del (Node *toDel) {
        if (toDel == head) {
            Node *temp;
            temp = head;
            head = head->next;
            Collector &thanos = Collector::getInstance();
            thanos.freeMemory(temp);
        } else {
            toDel->prev->next = toDel->next;
            Collector &thanos = Collector::getInstance();
            thanos.freeMemory(toDel);
        }
        length -= 1;
    }

   /**
    * displays the list in the console
    */
    void display() {
        display_aux(gethead(), "[");
    }

    /**
     * Obtains the head of the list
     * @return
     */
    Node* gethead() {
        return head;
    }

   /**
    * Obtain the leght of the group of elements
    * @return
    */
    int getLength() const {
        return length;
    }
    /**
     * Remove the node from the list
     * @param n
     */
    void remove(int n) {
        Node *temp = this->head;
        while (temp != NULL) {
            if (temp->data == n) {
                del(temp);
            }
            temp = temp->next;
        }
    }

};

#endif //LISTS_LIST_H
