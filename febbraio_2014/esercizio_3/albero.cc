#include <iostream>
#include "albero.h"
using namespace std;

void inizializza(Albero &t){
    t = NULL;
}

boolean vuoto(const Albero &t){

    boolean res{FALSO};
    if(t == NULL) res = VERO;
    return res;
}

boolean inserisci(Albero &t, int val){

    boolean res{FALSO};

        if(t == NULL){
            Albero temp = new (nothrow) Nodo;
            if(temp != NULL){
                temp->val = val;
                t = temp;
                t->sx = NULL;
                t->dx = NULL;
                res = VERO;
            }
        }
        else if(val <= t->val)res = inserisci(t->sx,val);
        else if(val > t->val)res = inserisci(t->dx,val);

    return res;

}

boolean cerca(const Albero &t, int val){

    boolean res{FALSO};

    if(t != NULL){

        if(val < t->val)res = cerca(t->sx,val);
        else if(val > t->val)res = cerca(t->dx,val);
        else if(val == t->val)res = VERO;
    
    }

    return res;

}

void stampa(const Albero &t){

    if(t != NULL){
        stampa(t->sx);
        cout << t->val << endl;
        stampa(t->dx);
    }

}