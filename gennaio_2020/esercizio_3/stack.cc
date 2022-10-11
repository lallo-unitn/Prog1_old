using namespace std;
#include <iostream>
#include "stack.h"

void init(stack& s){
    s = NULL;
}

void deinit(stack& s){
    if(empty(s) == FALSE){
        pop(s);
    }
}

void push(stack& s, int val){
    node* temp = new (nothrow) node;

    if(temp != NULL){
        temp->val = val;
        if(empty(s) == FALSE){
            temp->next = s;
            s = temp;
        }
        else{
            temp->next = NULL;
            s = temp;
        }
    }
}

retval pop(stack& s){

    retval res{FALSE};

    if(empty(s) == FALSE){
        node* temp = s;
        s = s->next;
        delete temp;
        res = TRUE;
    }
    return res;
}

retval empty(const stack& s){

    retval res{FALSE};

    if(s == NULL){
        res = TRUE;
    }

    return res;

}

retval top(const stack& s, int& result){

    retval res{FALSE};

    if(empty(s) == FALSE){
        result = s->val;
        res = TRUE;
    }

    return res;

}

void print(const stack& s){

    node* temp = s;

    while(temp != NULL){
        cout << temp->val << "      ";
        temp = temp->next;
    }

    cout << endl;

}