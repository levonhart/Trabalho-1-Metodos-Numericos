#include "raizes.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

double raiz_newton(double (*func)(double), double (*deriv)(double), double x0, double precisao, int maxIter){
	double Fx = func(x0), EA = HUGE_VAL, x;
	FILE *saida = fopen("data/newton.txt", "a");
	if (saida == NULL) saida = stdout;

	fprintf(saida, "<iter>\nXo = %lf , f(Xo) = %lf\n",x0,Fx);
	if (deriv(x0) != 0)
		for (int i = 0; fabs(EA) > precisao && i < maxIter; i++) {
			x = x0 - Fx/(*deriv)(x0);
			Fx = func(x);
			fprintf(saida, "%lf , %lf\n",x,Fx);
			EA = x - x0;
			x0=x;
		}
	fprintf(saida, "</iter>\n<result>\nXr = %lf , f(Xr) = %lf\n</result>\n", x, Fx);
	fclose(saida);
	return x;
}

double raiz_newton_mod(double (*func)(double), double (*deriv)(double), double x0, double precisao, int maxIter){
	double Fx = func(x0), derivx0 = deriv(x0), EA = HUGE_VAL, x;
	FILE *saida = fopen("data/newton-mod.txt", "a");
	if (saida == NULL) saida = stdout;

	fprintf(saida, "<iter>\nXo = %lf , f(Xo) = %lf\n",x0,Fx);
	if (derivx0 != 0)
		for (int i = 0; fabs(EA) > precisao && i < maxIter; i++) {
			x = x0 - Fx/derivx0;
			Fx = func(x);
			fprintf(saida, "%lf , %lf\n",x,Fx);
			EA = x - x0;
			x0=x;
		}
	fprintf(saida, "</iter>\n<result>\nXr = %lf , f(Xr) = %lf\n</result>", x, Fx);
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

double raiz_secante(double (*func)(double), double Xo, double Xn, double precisao, int maxIter){
	double EA = HUGE_VAL, Xatual;
	int cont = 0;
	FILE *arq = fopen("data/secante.txt", "a");
	if (arq == NULL) arq = stdout;

	fprintf(arq, "<iter>\nXo = %lf , f(Xo) = %lf\nX1 = %lf , f(X1) = %lf\n" \
					,Xo, func(Xo), Xn, func(Xn));
	/** fprintf(arq, "<info>\n"); */
	/** fprintf(arq, "Metodo = secante\n"); */
	/** fprintf(arq, "f(x) = a(E^d) -4(d^2)\n"); */
	/** fprintf(arq, "fi(Xn+1) = Xn - ((Xn-(Xn-1))/f(Xn) - f(Xn-1)) * f(Xn)\n"); */
	/** fprintf(arq, "</info>\n"); */
	/** fprintf(arq, "<inter>\n"); */
	while(EA > precisao && cont < maxIter){
		Xatual = Xn - ((Xn - Xo)/(func(Xn) - func(Xo))) * func(Xn);
		fprintf(arq, "%lf , %lf\n", Xatual, func(Xatual));
		/** fprintf(arq, "Xo = %f\n", Xo); */
		/** fprintf(arq, "Xn = %f\n",Xn ); */
		/** fprintf(arq, "Xatual = %f\n",Xatual); */
		EA = fabs(Xatual - Xn);
		Xo = Xn;
		Xn = Xatual;
		cont++;
	}
	fprintf(arq, "</inter>\n");
	fprintf(arq, "f(x) = %f\n",Xatual);
	return Xatual;
}

int inic_arq_saida(char* metodo, char* funcao, char* func_iter){
	FILE *arq;
	if (!strcmp(metodo,NEWTON)) {
		arq = fopen("data/newton.txt", "w");
	} else if (!strcmp(metodo,NEWTON_MOD)) {
		arq = fopen("data/newton-mod.txt", "w");
	} else if (!strcmp(metodo,SECANTE)) {
		arq = fopen("data/secante.txt", "w");
	} else {
		return 1;
	}

	fprintf(arq, "<info>\nf(x) = %s\nMétodo = %s\n%s = %s\n</info>\n", \
				funcao, metodo, \
				(!strcmp(metodo,NEWTON) || !strcmp(metodo,NEWTON_MOD)) ? "Derivada" : "Fi", \
				func_iter);
	fclose(arq);
	return 0;
}
