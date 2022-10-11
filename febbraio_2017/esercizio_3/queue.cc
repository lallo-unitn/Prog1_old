using namespace std;
#include <iostream>
#include "queue.h"

static int succ(const queue &q,int indice){

    indice = (indice+1) % q.dim;

    return indice;

}

static bool full_q(const queue& q){

    bool res{false};
    if(succ(q,q.tail) == q.head){
        res = true;
    }

    return res;

}

static bool empty_q(const queue& q){

    bool res{false};
    if(q.tail == q.head){
        res = true;
    }

    return res;

}

void init(queue &q, int maxdim){

    q.dim = maxdim;
    q.elem = new float[q.dim];
    q.head = q.tail = 0; 

}

void deinit(queue &q){

    delete[] q.elem;

}

bool enqueue(queue &q, float n){

    bool res{false};

    if(!full_q(q)){
        q.elem[q.tail] = n;
        q.tail = succ(q,q.tail);
        res = true;
    }

    return res;

}

bool dequeue(queue &q){

    bool res{false};

    if(!empty_q(q)){
        q.head = succ(q,q.head);
        res = true;
    }

    return res;

}

bool first(queue &q, float &out){

    bool res{false};

    if(!empty_q(q)){
        out = q.elem[q.head];
        res = true;
    }

    return res;

}

void print(const queue &q){

    for(int i{q.head}; i != q.tail; i = succ(q,i)){
        cout << q.elem[i] << endl;
    }

}