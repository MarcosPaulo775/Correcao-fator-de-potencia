#include "Biblioteca.h"

int main(){

    int resp = 1;

    do{
        function();
        printf("\n\nDeseja continuar?\n"
               "Digite:\n"
               "1 para continuar;\n"
               "0 para parar;\n"
               "-> ");
        scanf("%d",&resp);

    }while(resp == 1);

    return 0;

}
