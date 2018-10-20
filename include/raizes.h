#ifndef RAIZES_H_GSLVRNKE
#define RAIZES_H_GSLVRNKE

#define NEWTON "Newton-Raphson"
#define NEWTON_MOD "Newton-Raphson Modificado"
#define SECANTE "Secante"

double raiz_newton(double (*func)(double), double (*deriv)(double), double x0, double lim_erro, int maxIter);

double raiz_secante(double (*func)(double), double x0, double x1, double precisao, int maxIter);

int inic_arq_saida(char* metodo, char* funcao, char* func_iter);

#endif /* end of include guard: RAIZES_H_GSLVRNKE */