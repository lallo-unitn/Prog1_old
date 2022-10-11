using namespace std;
#include <iostream>
#include "queue.h"


void   init    (queue &q){

    q.head = NULL;
    q.tail = NULL;

}

retval enqueue (queue &q, long val){

    retval res{FALSE};

    node* temp = new (nothrow) node;

    if(temp != NULL){
        temp->val = val;
        temp->next = NULL;

        if(q.head == NULL){
            q.head = temp;
            q.tail = q.head;
            res = TRUE;
        }
        else{
            q.tail->next = temp;
            q.tail = temp;
            res = TRUE;
        }
    }

    return res;

}

retval dequeue (queue &q){

    retval res{FALSE};

    if(q.head != NULL){
        node* temp = q.head;
        q.head = q.head->next;
        delete temp;
        res = TRUE;
    }

    return res;

}

retval empty   (const queue &q){

    retval res{FALSE};

    if(q.head == NULL){
        res = TRUE;
    }

    return res;

}

retval first   (const queue &q, long &result){

    retval res{FALSE};

    if(!empty(q)){

        result = q.head->val;
        res = TRUE;

    }

    return res;

}

void   print   (const queue &q){

    node* temp =q.head;

    while(temp != NULL){
        cout << temp->val << endl;
        temp = temp->next;
    }

    delete temp;

}