#include <stdlib.h>
#include "raizes.h"

int main(int argc, char **argv){
	int qtd_a, i;
	double *a, precisao = 0;

	// captura entrada via linha de comando:
	if(argc > 1){
		qtd_a = atoi(argv[1]);
		a = (double*)malloc(sizeof(double));
		if(argc > qtd_a + 1)
			for(i=0; i<qtd_a; i++)
				a[i] = atol(argv[i+2]);
		if(i+2 <= argc)
			precisao = atol(argv[i+2]);
	}
	// captura fim

	inic_arq_saida(NEWTON);
	raiz_newton(f,derivf,CHUTE,PREC_PADRAO,50);
	
	/** inic_arq_saida(NEWTON_MOD,"e^d - 4d2", "e^d - 8d"); */
	/** raiz_newton_mod(f,derivf,CHUTE,PREC_PADRAO,50); */
    /**  */
	/** inic_arq_saida(SECANTE, "e^d - 4d2", "e^d - 8d"); */
	/** raiz_secante(f,CHUTE, CHUTE+0.2, PREC_PADRAO, LIMITE_ITER); */
	return 0;
}
