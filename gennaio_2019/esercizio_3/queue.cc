using namespace std;
#include "queue.h"
#include <iostream>

void init(queue &q, int maxdim){
    q.head = q.tail = 0;
    q.dim = maxdim+1;
    q.elem = new float[q.dim];
}

void deinit(queue &q){
    if(q.elem != NULL){
        delete[] q.elem;
    }
}

bool enqueue(queue &q, float n){

    bool stato{false};

    if((q.tail+1) % q.dim != q.head){
        q.elem[q.tail] = n;
        q.tail = (q.tail+1) % q.dim;
        stato = true;
    }
    return stato;
}

bool dequeue(queue &q){

    bool stato{false};

    if(q.head != q.tail){
        q.head = (q.head+1) % q.dim;
        stato = true;
    }

    return stato;

}

bool first(queue &q, float &out){

    bool stato{false};

    if(q.head != q.tail){
        out = q.elem[q.head];
        stato = true;
    }

    return stato;

}

void print(const queue &q){

    for(int i{q.head}; i != q.tail; i = (i+1) % q.dim){
        cout << q.elem[i] << endl;
    }
    cout << endl;
}