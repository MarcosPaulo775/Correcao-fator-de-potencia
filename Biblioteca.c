#include "Biblioteca.h"

PotComplexa preenchePot(){

    PotComplexa potencia;

    printf("Qual a potencia do motor? (HP)\n-> ");
    scanf("%f", &potencia.potenciaMotor);

    printf("\nQual o fator de potencia do motor?\n-> ");
    scanf("%f", &potencia.fatPotencia);

    printf("\nDigite:\n"
            "- 0 para fator de potencia atrasado;\n"
            "- 1 para fator de potencia adiantado;\n-> ");
    scanf("%f", &potencia.adiantado);

    printf("\nQual e o potencial eletrico do motor?\n-> ");
    scanf("%f", &potencia.tensao);

    printf("\nQual a frequencia?\n-> ");
    scanf("%f", &potencia.frequencia);

    printf("\nQual o rendimento do motor? (%)\n-> ");
    scanf("%f", &potencia.rendimento);

    return potencia;

}

PotComplexa setCapacitor(PotComplexa potencia){

    float c, xc;

    if(potencia.adiantado == 1){
        potencia.formPolar[1] = -1 * acos(potencia.fatPotencia);
    }else{
        potencia.formPolar[1] = acos(potencia.fatPotencia);
    }

    potencia.formRetangular[0] = potencia.potenciaMotor * 746 / (potencia.rendimento / 100);

    potencia.formRetangular[1] = potencia.formRetangular[0] * tan(potencia.formPolar[1]);

    potencia.formPolar[0] = sqrt(pow(potencia.formRetangular[0],2) + pow(potencia.formRetangular[1],2));

    potencia.corrente = potencia.formRetangular[0] / potencia.tensao;

    xc = pow(potencia.tensao, 2) / potencia.formRetangular[1];

    c = 1 / (2 * Pi * potencia.frequencia * xc);

    potencia.capacitor = c;

    return potencia;
}

void salvaTxt(PotComplexa x){

    // Criar um ponteiro

    FILE *ponteiro;
    char nome[20];

    // Esse ponteiro deverá aportar para o documento

    ponteiro = fopen ("Banco de Dados.txt", "a");

    // Para escrever você irá utilizar o "w", para ler "r", para alterar "a"

    // Vou escrever "5" no documento para exemplificar
    printf("\nDigite o nome do Cliente para salvarmos em nosso Banco de Dados:\n->");
    scanf("%s",&nome);

    fprintf(ponteiro, "\n\nCliente: %s\n\n"
                      "Dados do Motor:\n"
                      "Potencia: %.2f HP\n"
                      "Fator de Potencia: %.2f\n"
                      "Potencial Eletrico: %.2f V\n"
                      "Frequencia: %.2f HZ\n"
                      "Rendimento: %.2f %\n"
                      "Capacitor Necessario: %fF\n",nome
                                                 ,x.potenciaMotor
                                                 ,x.fatPotencia
                                                 ,x.tensao
                                                 ,x.frequencia
                                                 ,x.rendimento
                                                 ,x.capacitor);


}

function(){

    PotComplexa potencia;

    potencia = preenchePot();

    potencia = setCapacitor(potencia);

    printf("\nO valor do capacitor necessario é de %f F \n\n", potencia.capacitor);

    salvaTxt(potencia);

}
