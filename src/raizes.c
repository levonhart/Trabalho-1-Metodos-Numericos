#include "raizes.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

double raiz_newton(double (*func)(double), double (*deriv)(double), double x0, double precisao, int maxIter){
	double Fx = func(x0), x = HUGE_VAL;
	FILE *saida = fopen("data/newton.txt", "a");
	if (saida == NULL) saida = stdout;

	fprintf(saida, "<iter>\n\
					Xo = %lf , f(Xo) = %lf\n" \
					,x0,Fx);
	if (deriv(x0) != 0)
		for (int i = 0; fabs(x-x0) > precisao && i < maxIter; i++) {
			x = x0 - Fx/(*deriv)(x);
			Fx = func(x);
			fprintf(saida, "%lf %lf\n",x,Fx);
			x0=x;
		}
	fprintf(saida, "</iter>\n\
					<result>\n\
					Xr = %lf , f(Xr) = %lf\n\
					</result>", \
					x, Fx);
	return x;
}

double raiz_newton_mod(double (*func)(double), double (*deriv)(double), double x0, double precisao, int maxIter){
	double Fx = func(x0), derivx0 = deriv(x0), x = HUGE_VAL;
	FILE *saida = fopen("data/newton-mod.txt", "a");
	if (saida == NULL) saida = stdout;

	fprintf(saida, "<iter>\n\
					Xo = %lf , f(Xo) = %lf\n" \
					,x0,Fx);
	if (derivx0 != 0)
		for (int i = 0; fabs(x-x0) > precisao && i < maxIter; i++) {
			x = x0 - Fx/derivx0;
			Fx = func(x);
			fprintf(saida, "%lf %lf\n",x,Fx);
			x0=x;
		}
	fprintf(saida, "</iter>\n\
					<result>\n\
					Xr = %lf , f(Xr) = %lf\n\
					</result>", \
					x, Fx);
	return x;
}

/** double raiz_secante(double (*func)(double), double x0, double x1, double precisao, int maxIter){
	double Fx0 = func(x0), Fx1 = func(x1);
	printf("(%d)\t%lf\t%lf\n",0,x1,Fx1);
	if (fabs(Fx0) < precisao) return x0;
	if (fabs(Fx1) < precisao) return x1;
	for (int i = 0; fabs(Fx1) > precisao && i < maxIter; i++) {
		x1 = x1 - Fx1/(Fx1-Fx0) * (x1-x0);
		x0 = x1;
		printf("(%d)\t%lf\t%lf\n",i+1,x1,Fx1);
	}
	return x1;
} */

int inic_arq_saida(char* metodo, char* funcao, char* func_iter){
	FILE *arq;
	if (strcmp(metodo,NEWTON)) {
		arq = fopen("data/newton.txt", "w");
	} else if (strcmp(metodo,NEWTON_MOD)) {
		arq = fopen("data/newton-mod.txt", "w");
	} else if (strcmp(metodo,SECANTE)) {
		arq = fopen("data/secante.txt", "w");
	} else {
		return 1;
	}

	fprintf(arq, "<info>\n\
					f(x) = %s\n\
					Método = %s\n\
					%s = %s\n\
					</info>\n", \
				funcao, metodo, \
				strcmp(metodo,NEWTON) || strcmp(metodo,NEWTON_MOD) ? "Derivada" : "Fi", \
				func_iter);
	fclose(arq);
	return 0;
}
