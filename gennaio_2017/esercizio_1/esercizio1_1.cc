#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;
const int DIM_RIGA = 256;
const char* PAROLA_CHIAVE = "INCLUDI";
int main(int argc, char * argv[]) 
{
    fstream primo_file, secondo_file, file_di_output;
    // Controllo argomenti passati in ingresso
    if (argc != 4) {
        cerr << "Sintassi: ./a.out <primo_file> <secondo_file> <file_di_output>" << endl;
        exit(EXIT_FAILURE);
    }
    // Tentativo di apertura file di input
    primo_file.open(argv[1], ios::in);
    secondo_file.open(argv[2], ios::in);
    if (primo_file.fail() || secondo_file.fail()) {
        cerr << "Non riesco ad accedere ad uno dei file di input (" << argv[1] << "," << argv[2] << endl;
        exit(EXIT_FAILURE);
    }
    // Chiudo per poterlo riaprire in seguito
    secondo_file.close();
    // Apertura file di output
    file_di_output.open(argv[3], ios::out);
    // Buffer per una riga
    char riga[DIM_RIGA], riga2[DIM_RIGA];
    // Ciclo di lettura
    while(primo_file.getline(riga, DIM_RIGA, '\n')) {
        // Ogni riga letta, compresa la parola chiave,
        // va scritta sul file di output
        file_di_output << riga << endl;
        // Se ho letto la parola chiave
        cout << strlen(riga) << endl;
        for( int i = 0; riga[i] != '\0'; i++ )
            cout << "[" << i << "]" << riga[i] << " " << (int) riga[i] << endl;
        if(strcmp(riga, PAROLA_CHIAVE) == 0 || strcmp(riga, "INCLUDI\r") == 0 || strcmp(riga, "INCLUDI ") == 0) {
            // Includo il secondo file
            secondo_file.open(argv[2], ios::in);
            // Ciclo di I/O
            while(secondo_file.getline(riga2, DIM_RIGA)) {file_di_output << riga2 << endl;}
            // Lo stream va chiuso per poter essere eventualmente
            // riaperto in seguito
            secondo_file.close();
        }
    } 
    // Chiude i file
    primo_file.close();
    file_di_output.close();
    return 0;
}