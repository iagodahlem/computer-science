/**
 * Linked List
 *
 * Exercicios:
 * 1 - Inserir o 4o nodo da lista.
 * 2 - Inserir antes do 5o nodo da lista.
 * 3 - Inserir no início da lista (inserir a esquerda).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int data;
  struct Node *next;
};

int size(struct Node *first);
void add(struct Node *first, struct Node *last, int data, int *signal);
void addFirst(struct Node *first, int data, int *signal);
void addFourth(struct Node *first, struct Node *last, int data, int *signal);
void addBeforeFifth(struct Node *first, int data, int *signal);

void main() {
  struct Node last = { 2, NULL };
  struct Node first = { 1, &last };
  int signal;

  add(&first, &last, 3, &signal);
  add(&first, &last, 5, &signal);

  addFourth(&first, &last, 4, &signal);

  int counter = 0;
  struct Node *aux;

  aux = &first;

  while (aux) {
    printf("node->data: %x\n", aux->data);

    counter++;
    aux = aux->next;
  }
}

int size(struct Node *first) {
  int counter = 0;
  struct Node *aux;

  aux = first;

  while (aux != NULL) {
    counter++;
    aux = aux->next;
  }

  return counter;
}

void add(struct Node *first, struct Node *last, int data, int *signal) {
  struct Node *p;

  if (!p) {
    *signal = 0;
  } else {
    p->data = data;
    p->next = NULL;

    if (!first) {
      first = p;
    } else {
      last->next = p;
    }

    last = p;
    *signal = 1;
  }
}

void addFirst(struct Node *first, int data, int *signal) {
  struct Node *p;

  if (!p) {
    *signal = 0;
  } else {
    p->data = data;
    p->next = first;

    *signal = 1;
  }
}

void addFourth(struct Node *first, struct Node *last, int data, int *signal) {
  int counter;
  struct Node *aux, *p;

  if (size(first) < 3) {
    signal = 0;
  } else {
    aux = first;

    for (counter = 0; aux != NULL; counter++) {
      aux = aux->next;

      if (counter == 2) {
        p->data = data;
        p->next = aux->next;
        aux->next = p;
      }

      if (p->next == NULL) {
        last = p;
      }
    }

    *signal = 1;
  }
}

void addBeforeFifth(struct Node *first, int data, int *signal) {
  int counter = 0;
  struct Node *aux, *p;

  if (size(first) < 5) {
    signal = 0;
  } else {
    aux = first;

    for (counter = 0; aux != NULL; counter++) {
      aux = aux->next;

      if (counter == 3) {
        p->data = data;
        p->next = aux->next;
        aux->next = p;
      }
    }
  }
}
