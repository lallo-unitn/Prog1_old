using namespace std;
#include <iostream>
#include "queue.h"

static int succ(const queue& q, int n){
    n = (n+1) % q.dim;
    return n;
}

static bool empty(const queue& q){
    
    bool res{false};
    if(q.head == q.tail) res = true;
    return res;

}

static bool full(const queue& q){
    
    bool res{false};
    if(succ(q,q.tail) == q.head) res = true;
    return res;

}

void init(queue &q, int maxdim){

    q.head = 0;
    q.tail = 0;
    q.dim = maxdim + 1;
    q.elem = new float[q.dim];

}

void deinit(queue &q){

    delete[] q.elem;

}

bool enqueue(queue &q, float n){

    bool res{false};

    if(!full(q)){
        q.elem[q.tail] = n;
        q.tail = succ(q,q.tail);
        res = true;
    }

    return res;

}

bool dequeue(queue &q){

    bool res{false};

    if(!empty(q)){
        q.head = succ(q,q.head);
        res = true;
    }

    return res;

}

bool first(queue &q, float &out){

    bool res{false};

    if(!empty(q)){
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