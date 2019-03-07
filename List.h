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
public:
    List() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    int getLength() const {
        return length;
    }

    void add(int n) {
        Collector& thanos = Collector::getInstance();
        Node *tmp = thanos.getMemory();
        tmp->data = n;
        tmp->next = NULL;
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

    Node* gethead() {
        return head;
    }

    void display() {
        display_aux(gethead(), "[");
    }

    void display_aux(Node *head, string result) {
        if(head == NULL) {
            //cout << length << endl;
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

    void front(int n) {
        length += 1;
        Node *tmp = new Node;
        tmp -> data = n;
        tmp -> next = head;
        head = tmp;
    }

    void after(Node *a, int value) {
        length += 1;
        Node* p = new Node;
        p->data = value;
        p->next = a->next;
        a->next = p;
    }

    void del (Node *before_del) {
        length -= 1;
        Node* temp;
        temp = before_del->next;
        before_del->next = temp->next;
        delete temp;
    }

};

#endif //LISTS_LIST_H
