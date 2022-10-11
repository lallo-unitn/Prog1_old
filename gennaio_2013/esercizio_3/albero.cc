#include <iostream>
#include "albero.h"
using namespace std;

void init(Tree &t){

    t = NULL;

}

boolean empty(const Tree &t){

    boolean res{FALSE};

    if(t == NULL) res = TRUE;

    return res;

}

boolean insert(Tree &t, char val){

    boolean res{FALSE};

    if(t == NULL){
            Tree temp = new (nothrow) Node;

                if(temp != NULL){
                temp->val = val;
                temp->left = NULL;
                temp->right = NULL;
                t = temp;
                res = TRUE;
            }
        }
    else if(val <= t->val) res = insert(t->left, val);
    else if(val > t->val) res = insert(t->right, val);

    return res;

}

boolean search(const Tree &t, char val){

    boolean res{FALSE};

    if(!empty(t)){

        if(val < t->val) res = search(t->left, val);
        else if(val > t->val) res = search(t->right, val);
        else if(val == t->val) res = TRUE;
    }

    return res;

}

void print(const Tree &t){

    if(!empty(t)){

        print(t->left);
        cout << t->val << endl;
        print(t->right);

    }

}