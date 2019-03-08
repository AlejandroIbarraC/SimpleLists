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

struct CollectorNode {
    Node *data;
    CollectorNode *next;
};

class Collector {

private:
    CollectorNode *head,*tail;
    int length;
public:
    Collector() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    static Collector& getInstance(){
        static Collector theInstance;
        return theInstance;
    }

    int getLength() const {
        return length;
    }

    Node* getMemory() {
        Node *result = new Node;
        this->add(result);
        return result;
    }

    void add(Node *n) {
        CollectorNode *tmp = new CollectorNode;
        tmp->data = n;
        tmp->next = NULL;
        length += 1;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    CollectorNode * gethead() {
        return head;
    }

    void display() {
        display_aux(gethead(), "[");
    }

    void display_aux(CollectorNode *head, string result) {
        if(head == NULL) {
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

    static void concatenate(Node *a, Node *b) {
        if( a != NULL && b!= NULL ) {
            if (a->next == NULL)
                a->next = b;
            else
                concatenate(a->next,b);
        }
        else {
            cout << "Either a or b is NULL\n";
        }
    }

    void del (CollectorNode *before_del) {
        length -= 1;
        CollectorNode* temp;
        temp = before_del->next;
        before_del->next = temp->next;
        delete temp;
    }

    void freeMemory (Node *toDelete) {
        CollectorNode *tmp = this->head;
        while (tmp->data != toDelete) {
            tmp = tmp->next;
        }
        delete toDelete;
    }

};


#endif //LISTS_COLLECTOR_H
