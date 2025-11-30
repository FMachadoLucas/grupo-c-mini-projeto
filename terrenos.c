#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terrenos.h"

//implementacao das funcoes
void inicializarVetor(Terrenos ** terrenos){
    for (int i=0;i<100;i++){
        terrenos[i] = NULL;
    }
}