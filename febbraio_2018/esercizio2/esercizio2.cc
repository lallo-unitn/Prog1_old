using namespace std;
#include <iostream>
const int DIM = 81;

char* estrai(char s[]);
char* estrai_ric(char s[], char res[], int indice_s, int indice_res);

int main() {

  char stringa[DIM], *estratta, risposta;
  
  do {
      
    cout << "Inserisci la stringa da controllare: ";
    cin >> stringa;
    
    estratta = estrai(stringa);
    
    cout << "La stringa estratta e’: " << estratta << endl;
    cout << "Vuoi inserire un’altra stringa? [s/n] ";
    cin >> risposta;
      
  } while (risposta != 'n' && risposta != 'N');
      
  return 0;
        
}

char* estrai(char s[]){

  //Non hai allocato dinamicamente l'array res, occhio che per
  //questo errore mi ha dato 0 all'esercizio 2
  
  //char s_2[DIM];
  //s_2[0] = '\0';

  char *s_2 = new char[DIM]; //Non puoi ritornare stringhe allocate staticamente
  
  //char* res{NULL};

    char* res = new char[DIM];
    res = estrai_ric(s, s_2, 0, 0);
    cout << res;

    return res;

}

char* estrai_ric(char s[], char res[], int indice_s, int indice_res){

    if(s[indice_s] != '\0'){
        if(s[indice_s] >= 'A' && s[indice_s] <= 'Z'){
            res[indice_res] = s[indice_s];
            indice_s++;
            indice_res++;
            //res[indice_res] = '\0';
            cout << indice_s << endl << indice_res << endl;
            res = estrai_ric(s, res, indice_s, indice_res);
        }
        else{
            indice_s++;
            res = estrai_ric(s, res, indice_s, indice_res);
        }
    };

    cout << res << endl;

    return res;

}

//Oppure senza usare due stringhe dinamiche diverse, fai così

/*

char* estrai(char* s)
{
  char *res = new char[DIM];
  estrai_wrapper(s,res,0,0);
  return res;
}

void estrai_wrapper(char* s,char* res,int a,int b)
{
  if(s[b] != '\0' && b < DIM)
    {
      if(s[b] >= 'A' && s[b] <= 'Z')
	{
	  res[a]=s[b];
	  a++;
	}
      estrai_wrapper(s,res,a,b+1);
    }
}

*/
