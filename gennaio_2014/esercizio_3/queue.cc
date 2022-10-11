using namespace std;
#include <iostream>
#include "queue.h"

static int succ(int index, const queue& q){

    index = (index + 1) % q.dim;
    return index;

}

static bool empty(queue& q){

    bool res{false};
    if(q.head == q.tail) res = true;
    return res;

}

static bool full(queue& q){

    bool res{false};
    if(succ(q.tail,q) == q.head) res = true;
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
        q.tail = succ(q.tail,q);
        res = true;
    }

    return res;

}

bool dequeue(queue &q){

    bool res{false};

    if(!empty(q)){
        q.head = succ(q.head,q);
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

    for(int i{q.head}; i != q.tail; i = succ(i,q)){
        cout << q.elem[i] << " ";
    }
    cout << endl;

}