# Interpretador BrainFuc\*

Esse é um código em C que implementa um interpretador para a linguagem de programação Brainfuck.

Brainfuck é uma linguagem de programação minimalista, que opera em uma fita de memória com células de 8 bits, e consiste em apenas 8 comandos:

'+' e '-' para incrementar e decrementar o valor da célula atual, respectivamente.
'>' e '<' para mover o ponteiro da célula atual para a direita ou para a esquerda, respectivamente.
'.' para imprimir o valor da célula atual na saída padrão.
',' para ler um caractere da entrada padrão e armazená-lo na célula atual.
'[' e ']' para controlar fluxo, sendo que '[' inicia um loop enquanto o valor da célula atual é diferente de zero e ']' encerra um loop.
O código em C abre um arquivo chamado "input.txt", que deve conter o código em Brainfuck a ser interpretado. O código é lido e armazenado em um array de caracteres chamado "code".

O programa usa um array de caracteres como memória e um ponteiro para acompanhar a célula atual da memória. Ele lê o código fonte do BrainF\*ck de um arquivo, filtra caracteres não instruções e executa o código fonte usando as funções execute_code(). Quando uma instrução [ é encontrada, o índice da instrução é empilhado em loop_stack. Quando uma instrução ] é encontrada, o índice da instrução no topo da pilha é removido e usada como a próxima instrução a ser executada, se o valor atual da célula da memória for diferente de zero.

# Makefile

- CC=gcc: define a variável CC como o compilador padrão, no caso, gcc.
- CFLAGS=-Wall: define a variável CFLAGS como as opções de compilação a serem usadas pelo compilador, no caso, -Wall - que habilita todas as opções de aviso.
- SRCDIR=src: define a variável SRCDIR como o diretório onde estão os arquivos-fonte.
- SOURCES=$(wildcard $(SRCDIR)/\*.c): define a variável SOURCES como a lista de arquivos-fonte no diretório $(SRCDIR) que terminam com a extensão .c. A função $(wildcard) encontra todos os arquivos que correspondem ao padrão especificado.
- OBJECTS=$(SOURCES:.c=.o): define a variável OBJECTS como a lista de arquivos-objeto correspondentes aos arquivos-fonte listados em $(SOURCES). A função de substituição de sufixos .c=.o altera a extensão dos arquivos de .c para .o.
- EXECUTABLE=program: define a variável EXECUTABLE como o nome do arquivo executável gerado.

## REFERENCIAS:

- Conversor Brainfuck: https://www.dcode.fr/brainfuck-language
- Interpretador Base: https://github.com/Camto/Shorterpreters/blob/master/Brainfuck/brainfuck.py
- http://orion.lcg.ufrj.br/compgraf1/downloads/MakefileTut.pdf
