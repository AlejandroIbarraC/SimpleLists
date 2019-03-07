//
// Created by parallels on 2/28/19.
//

#ifndef LISTS_LIST_H
#define LISTS_LIST_H
#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

class list {

private:
    node *head,*tail;
    int length;
public:
    list() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    int getLength() const {
        return length;
    }

    void add(int n) {
        node *tmp = new node;
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

    node* gethead() {
        return head;
    }

    void display() {
        display_aux(gethead(), "[");
    }

    void display_aux(node *head, string result) {
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

    static void concatenate(node *a,node *b) {
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
        node *tmp = new node;
        tmp -> data = n;
        tmp -> next = head;
        head = tmp;
    }

    void after(node *a, int value) {
        node* p = new node;
        p->data = value;
        p->next = a->next;
        a->next = p;
    }

    void del (node *before_del) {
        node* temp;
        temp = before_del->next;
        before_del->next = temp->next;
        delete temp;
    }
};

#endif //LISTS_LIST_H
