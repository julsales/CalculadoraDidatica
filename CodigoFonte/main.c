// Calculadora didática
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int num;
  struct Node *next;
} Node;

void imprimir_elementos(Node *head) {
  while (head != NULL) {
    if (head->num >= 10 && head->num <= 15) {
      printf("%c", 'A' + (head->num - 10));
    } else {
      printf("%d", head->num);
    }
    head = head->next;
  }
}

void guardar_elementos(Node **head, int res) {
  Node *novo = (Node*)malloc(sizeof(Node));
  if (novo != NULL) {
    novo->num = res;
    novo->next = *head;
    *head = novo;
  }
}

void calcular_base2(int *n) {
  Node *head = NULL;
  int numero = *n;
  printf("\nConversão do número decimal %d para base 2:", numero);
  while (1) {
    int res = *n % 2;
    if (*n <= 1) {
      printf("\n %d/2 não tem resto inteiro, então é %d", *n, *n);
    } else {
      printf("\n %d/2 tem resto: %d", *n, res);
    }
    *n = *n / 2;
    guardar_elementos(&head, res);
    if (*n < 1) {
      printf("\n O total é: ");
      imprimir_elementos(head);
      break;
    }
  }
}

void calcular_base8(int *n) {
  Node *head = NULL;
  int numero = *n;
  printf("\nConversão do número decimal %d para base 8:", numero);
  while (1) {
    int res = *n % 8;
    if (*n <= 1) {
      printf("\n %d/8 não tem resto inteiro, então é %d", *n, *n);
    } else {
      printf("\n %d/8 tem resto: %d", *n, res);
    }
    *n = *n / 8;
    guardar_elementos(&head, res);
    if (*n < 1) {
      printf("\n O total é: ");
      imprimir_elementos(head);
      break;
    }
  }
}

void calcular_base16(int *n) {
  Node *head = NULL;
  int numero = *n;
  printf("\nConversão do número decimal %d para base 16:", numero);
  while (1) {
    int res = *n % 16;
    if (*n <= 1) {
      printf("\n %d/16 não tem resto inteiro, então é %d", *n, *n);
    } else {
      printf("\n %d/16 tem resto: %d", *n, res);
    }
    *n = *n / 16;
    guardar_elementos(&head, res);
    if (*n < 1) {
      printf("\n O total é: ");
      imprimir_elementos(head);
      break;
    }
  }
}

void calcular_BCD(int *n) {
  Node *head = NULL;
  int numero = *n;
  printf("\nConversão do número decimal %d para BCD:", numero);
  int cont=1;
  while (*n>0) {
    int digito = *n%10;
    printf("\nPasso %d: Convertendo o dígito %d para BCD (4 bits): ",cont, digito);
    for (int i = 0; i < 4; i++) {
      int bit = (digito >> i) & 1;
      guardar_elementos(&head, bit);
    }
    imprimir_elementos(head);
    *n=*n/10;
    cont++;
  }
  printf("\n O total é: ");
  imprimir_elementos(head);
}

int main(void) {
  int n;
  int escolha;
  printf("\n Escolha um número para calcular: ");
  scanf("%d", &n);
  printf("\n Escolha um processo"
         "\n 1- Calcular base 2"
         "\n 2- Calcular base 8"
         "\n 3- Calcular base 16"
         "\n 4- Calcular BCD"
         "\n 5- Transformar base 10 para base com sinal com 16 bits (Complemento A2) "
         "\n 6- Converter real em decimal para float e double\n");
  scanf("%d", &escolha);

  switch (escolha) {
    case 1:
      calcular_base2(&n);
      break;
    case 2:
      calcular_base8(&n);
      break;
    case 3:
      calcular_base16(&n);
      break;
    case 4:
      calcular_BCD(&n);
      break;
    default:
      printf("\n Opção inválida");
      break;
  }
  return 0;
}
