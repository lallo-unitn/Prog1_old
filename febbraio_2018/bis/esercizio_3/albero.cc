#include <iostream>
#include "albero.h"
using namespace std;

void inizializza(Albero &t){

    t = NULL;

}

boolean vuoto(const Albero &t){

    boolean res{FALSO};    

    if(t == NULL){
        res = VERO;
    }

    return res;

}

boolean inserisci(Albero &t, int val){

    boolean res{FALSO};

    if(vuoto(t) == VERO){
        Albero temp = new (nothrow) Nodo;
        
        temp->val = val;
        temp->sx = NULL;
        temp->dx = NULL;

        t = temp;
        res = VERO;
    }
    else if(val <= t->val) res = inserisci(t->sx, val);
    else if(val > t->val) res = inserisci(t->dx, val);

    return res;

}

boolean cerca(const Albero &t, int val){

    boolean res{FALSO};

    if(vuoto(t) == FALSO){
        if(val == t->val) res = VERO;
        else if(val > t->val) res = cerca(t->dx,val);
        else if(val < t->val) res = cerca(t->sx,val);
    }

    return res;

}

void stampa(const Albero &t){

    if(vuoto(t) == FALSO){

        stampa(t->sx);
        cout << t->val << endl;
        stampa(t->dx);

    }

}