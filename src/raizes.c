#include "raizes.h"
#include <math.h>
#include <stdio.h>

double raiz_newton(double (*func)(double), double (*deriv)(double), double x0, double lim_erro, int maxIter){
	double Fx = func(x0);
	printf("%d\t%lf\t%lf\n",0,x0,Fx);
	for (int i = 0; fabs(Fx) > lim_erro && i < maxIter; i++) {
		x0 = x0 - Fx/(*deriv)(x0);
		Fx = func(x0);
		printf("%d\t%lf\t%lf\n",i+1,x0,Fx);
	}
	return x0;

}

double raiz_secante(double (*func)(double), double x0, double x1, double lim_erro, int maxIter){
	double Fx0 = func(x0), Fx1 = func(x1);
	printf("(%d)\t%lf\t%lf\n",0,x1,Fx1);
	if (fabs(Fx0) < lim_erro) return x0;
	if (fabs(Fx1) < lim_erro) return x1;
	for (int i = 0; fabs(Fx1) > lim_erro && i < maxIter; i++) {
		x1 = x1 - Fx1/(Fx1-Fx0) * (x1-x0);
		x0 = x1;
		printf("(%d)\t%lf\t%lf\n",i+1,x1,Fx1);
	}
	return x1;
}
