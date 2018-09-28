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
