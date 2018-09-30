#ifndef RAIZES_H_GSLVRNKE
#define RAIZES_H_GSLVRNKE

double raiz_newton(double (*func)(double), double (*deriv)(double), double x0, double lim_erro, int maxIter);

double raiz_secante(double (*func)(double), double x0, double x1, double lim_erro, int maxIter);

#endif /* end of include guard: RAIZES_H_GSLVRNKE */
