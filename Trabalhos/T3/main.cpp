#include "Cesar.h"

using namespace cifra;

int main() {
    Cesar cesar;
    int k =-500;
    cesar.encripte("entrada.txt", "encriptado.txt", k);
    cesar.encripte("encriptado.txt", "saida.txt", -k);
    
    return 0;
}

