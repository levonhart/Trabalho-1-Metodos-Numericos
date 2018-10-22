#include <stdio.h>
#include <stdlib.h>
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

int main(int argc, char **argv){
	int qtd_a, i;
	double *a, precisao = 0;

	// captura entrada via linha de comando:
	if(argc > 1){
		qtd_a = atoi(argv[1]);
		a = (double*)malloc(sizeof(double));
		if(argc > qtd_a + 1)
			for(i=0; i<qtd_a; i++)
				a[i] = atol(argv[i+2];
		if(i+2 <= argc)
			precisao = atol(argv[i+2]);
	}
	// captura fim

	/*
	inic_arq_saida(NEWTON,"e^d - 4d2", "e^d - 8d");
	raiz_newton(f,derivf,CHUTE,PREC_PADRAO,50);
	
	inic_arq_saida(NEWTON_MOD,"e^d - 4d2", "e^d - 8d");
	raiz_newton_mod(f,derivf,CHUTE,PREC_PADRAO,50);

	inic_arq_saida(SECANTE, "e^d - 4d2", "e^d - 8d");
	raiz_secante(f,CHUTE, CHUTE+0.2, PREC_PADRAO, LIMITE_ITER);
	*/
	return 0;
}
