#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Pi 3.14159265359

typedef struct potenciaComplexa PotComplexa;

struct potenciaComplexa {

    float formPolar[2];
    float formRetangular[2];
    float potAtiva;
    float potReativa;
    float potAparente;
    float angulo;
    float anguloRadianos;
    float fatPotencia;
    float potenciaMotor;
    int adiantado;
    float tensao;
    float frequencia;
    float rendimento;
    float capacitor;
    float corrente;

};
/*
PotComplexa transformPolar(PotComplexa x);
PotComplexa transformRetangular(PotComplexa x);
*/
PotComplexa preenchePot();
PotComplexa setCapacitor(PotComplexa x);
void salvaTxt();

void function();
