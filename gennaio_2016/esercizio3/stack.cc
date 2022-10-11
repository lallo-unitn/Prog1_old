using namespace std;
#include <iostream>
#include "stack.h"

void init(stack &s, int maxdim){

    s.dim = maxdim;
    s.elem = new double[s.dim];
    s.index = 0;

}

void deinit(stack &s){

    delete[] s.elem;

}

bool push(stack &s, double n){

    bool res{false};

    if(s.index < s.dim){
        s.elem[s.index] = n;
        s.index++;
        res = true;
    }
    return res;
}

bool top(const stack &s, double &out){

    bool res{false};

    if(s.index > 0){
        out = s.elem[s.index-1];
        res = true;
    }
    return res;
}

bool pop(stack &s){

    bool res{false};

    if(s.index >= 0){
        s.index--;
        res = true;
    }
    return res;

}

void print(const stack &s){

    if(s.index != 0){

    for(int i{s.index-1}; i >= 0; i--){
        cout << s.elem[i] << endl;
    }
    }

}