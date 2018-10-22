#ifndef RAIZES_H_GSLVRNKE
#define RAIZES_H_GSLVRNKE

#define NEWTON "Newton-Raphson"
#define NEWTON_MOD "Newton-Raphson Modificado"
#define SECANTE "Secante"
#define COEFICIENTE 1.0
#define PREC_PADRAO 0.0001
#define CHUTE 0.5
#define LIMITE_ITER 50

// double param_a = COEFICIENTE;

double f(double d);
double derivf(double d);

double raiz_newton(double (*func)(double), double (*deriv)(double), double x0, double precisao, int maxIter);

double raiz_newton_mod(double (*func)(double), double (*deriv)(double), double x0, double precisao, int maxIter);

double raiz_secante(double (*func)(double), double Xo, double Xn, double precisao, int maxIter);

int inic_arq_saida(char* metodo);

#endif /* end of include guard: RAIZES_H_GSLVRNKE */
