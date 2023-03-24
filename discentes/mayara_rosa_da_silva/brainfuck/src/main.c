#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 30000
// log geral
void error(char *msg) {
  fprintf(stderr, "Erro: %s\n", msg);
  exit(1);
}

// lê arquivo e armazena buffer
char *load_code(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    error("Não foi possível abrir o arquivo");
  }

  // alocando memoria
  char *code = (char *)malloc(MEMORY_SIZE);
  if (code == NULL) {
    error("Não foi possível alocar memória para o código");
  }

  int i = 0;
  int c;
  // função fgetc lê cada caractere do arquivo
  while ((c = fgetc(file)) != EOF && i < MEMORY_SIZE) {
    if (c == '>' || c == '<' || c == '+' || c == '-' || c == '.' || c == ',' ||
        c == '[' || c == ']') {
      code[i++] = c;
    }
  }
  fclose(file);

  return code;
}

// executa o código armazena no buffer
void execute_code(char *code) {
  char memory[MEMORY_SIZE] = {0}; // memoria como array
  char *ptr = memory;             // celula atual da fita
  int loop_stack[MEMORY_SIZE];     // pilha indice
  int loop_stack_size = 0;         // tamanho pilha indice
  int i = 0;                      // percorrer a fita

  while (code[i] != '\0') {
    if (code[i] == '>') {
      ptr++;
    } else if (code[i] == '<') {
      ptr--;
    } else if (code[i] == '+') {
      (*ptr)++;
    } else if (code[i] == '-') {
      (*ptr)--;
    } else if (code[i] == '.') {
      putchar(*ptr);
    } else if (code[i] == ',') {
      *ptr = getchar();
    } else if (code[i] == '[') {
      if (*ptr == 0) {
        int level = 1;
        while (level > 0) {
          i++;
          if (code[i] == '[') {
            level++;
          } else if (code[i] == ']') {
            level--;
          }
        }
      } else {
        loop_stack[loop_stack_size++] = i;
      }
    } else if (code[i] == ']') {
      if (*ptr != 0) {
        i = loop_stack[loop_stack_size - 1];
      } else {
        loop_stack_size--;
      }
    }

    i++;
  }
}

int main(int argc, char *argv[]) {

  char *code = load_code("input.txt");
  execute_code(code);
  free(code);

  return 0;
}