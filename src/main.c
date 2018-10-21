#include <stdio.h>
#include <math.h>
#include "raizes.h"

#define COEFICIENTE 1.0
#define PREC_PADRAO 0.0001
#define CHUTE 0.5
#define LIMITE_ITER 50

double param_a = COEFICIENTE;

double _f(double d, double a){
	return a*exp(d) - 4*pow(d,2);
}
double _derivf(double d, double a){
	return a*exp(d) - 8*d;
}
double f(double d){
	return _f(d,param_a);
}
double derivf(double d){
	return param_a*exp(d) - 8*d;
}

int main(int argc, char *argv[]){
	inic_arq_saida(NEWTON,"e^d - 4d2", "e^d - 8d");
	raiz_newton(f,derivf,CHUTE,PREC_PADRAO,50);
	
	inic_arq_saida(NEWTON_MOD,"e^d - 4d2", "e^d - 8d");
	raiz_newton_mod(f,derivf,CHUTE,PREC_PADRAO,50);

	return 0;
}
