#include <math.h>
#include "secante.h"
#include <stdio.h>
#define E 2.71828182846

float elevado(float x , float n){
	if(n == 0) return 1;
	if(n == 1) return x;
	if(n < 0) return 1/elevado(x,-n);
	float xo = x;
	for (int i = 1; i < n-1 ; ++i){
		x = x*xo;
	}return x;
}


float f(float x,float a){
	return a * elevado(E,x) - 4 * elevado(x,2);
}


float secante(float a,float Xo, float Xn, float e, FILE* arq, int k){
	float EA = 999,Xatual;
	int cont = 0;
	fprintf(arq, "<info>\n");
	fprintf(arq, "Metodo = secante\n");
	fprintf(arq, "f(x) = a(E^d) -4(d^2)\n");
	fprintf(arq, "fi(Xn+1) = Xn - ((Xn-(Xn-1))/f(Xn) - f(Xn-1)) * f(Xn)\n");
	fprintf(arq, "</info>\n");
	fprintf(arq, "<inter>\n");
	while(EA > e || cont == k){
		Xatual = Xn - ((Xn - Xo)/(f(Xn,a) - f(Xo,a))) * f(Xn,a);
		fprintf(arq, "Xo = %f\n", Xo);
		fprintf(arq, "Xn = %f\n",Xn );
		fprintf(arq, "Xatual = %f\n",Xatual);
		EA = Xatual - Xn;
		if(EA < 0) EA = EA * -1;
		Xo = Xn;
		Xn = Xatual;
		cont++;
	}
	fprintf(arq, "</inter>\n");
	fprintf(arq, "f(x) = %f\n",Xatual);
	return Xatual;
}
