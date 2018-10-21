# Trabalho-1-Metodos-Numericos
Programa em C capaz de calcular raizes do polinomio a*e^d - 4*d^2

## Tarefa:
Seja um movimento físico regido pela função f(d) = a×e<sup>d</sup> – 4d², onde a são amplitudes dadas devido à oscilação encontrada em cada
movimento considerado e d é o deslocamento encontrado em cada um desses movimentos, variando com o valor de a. O método de
Newton modificado é tal que a função de iteração ϕ(x) utilizada é dada por ϕ(x) = x – (f(x) / f’(x<sub>o</sub>)), onde x<sub>o</sub> é uma aproximação inicial e
é tal que f’(x<sub>o</sub>) ≠ 0. Desenvolva um sistema para calcular o valor de d que deve atender aos seguintes requisitos dados pelos itens abaixo:

a) Implementar algoritmo para calcular d pelo método de Newton-Raphson original.\
b) Implementar algoritmo para calcular d pelo método da Newton-Raphson modificado.\
c) Implementar algoritmo para calcular d pelo método da Secante.\
d) Calibrar o sistema usando como padrão a = 1, d<sub>0</sub> = 0,5 e ε = 10<sup>-4</sup>.\
e) Fornecer um quadro resposta, variando os valores de a para vários casos.\
f) Fornecer um quadro comparativo, com todos os dados para cada método.\
g) Analisar o efeito da variação do valor de a para cada método considerado.

*Dados de entrada: n (número de valores de a), d (para cada n) e ε (precisão).* \
*Dados de saída: quadros resposta (com d, E<sub>A</sub> para cada a e método) e comparativo.*
