using namespace std;
#include <iostream>
#include "queue.h"

void init(queue &q){

    q.head = NULL;
    q.tail = NULL;

}

void deinit(queue &q);

bool enqueue(queue &q, float n){

    bool res{false};

    elem* temp = new (nothrow) elem;
    if(temp != NULL){

        temp->value = n;
        temp->next = NULL;

        if(q.head == NULL){

            q.head = temp;
            q.tail = temp;
            res = true;

        }

        else{

            q.tail->next = temp;
            q.tail = q.tail->next;
            res = true;

        }

    };

    return res;

}

bool dequeue(queue &q){

    bool res{false};

    elem* temp = new elem;

    if(q.head != NULL){
        temp = q.head;
        q.head = q.head->next;
        delete temp;
        res = true;
    }

    return res;

}

bool first(const queue &q, float &out){

    bool res{false};

    if(q.head != NULL){

        out = q.head->value;
        res = true;

    }

    return res;

}

void print(const queue &q){

    elem* temp = new elem;
    temp = q.head;

    while(temp != NULL){
    
        cout << temp->value << endl;
        temp = temp->next;

    }

}

void deinit(queue &q){

    while(q.head != NULL){

        dequeue(q);

    };

}