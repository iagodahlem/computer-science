/**
 * Exercicios Revisao de Subrotinas - Estruturas de Dados 1 (Seg.)
 * 05/03/2017 - Iago Dahlem Lorensini
 *
 * 1-Escrever uma função que recebe um vetor de 30 notas de alunos e retorna a média destas novas.
 * 2-Escrever um procedimento que recebe um vetor de 30 registros de alunos e retorna que aluno tem a maior nota e a nota.
 * 3-Escreva uma função que recebe um vetor de 30 registros de alunos e retorna quantos alunos estão aprovados (considerando que média >=6,0 está aprovado).
 */

#include <stdio.h>

struct Aluno {
  int codAluno, semestre;
  float nota;
};

float media(float notas[30]);
float maiorNota(struct Aluno alunos[30]);
int totalAlunosAprovados(struct Aluno alunos[30]);

void main() {
  struct Aluno alunos[3] = {{ nota: 10.0 }, { nota: 4.0 }, { nota: 6.0 }};

  float maior = maiorNota(alunos);
  int total = totalAlunosAprovados(alunos);

  int i;
  for (i = 0; i < 3; i++) {
    printf("Nota..........................: %.2f\n", alunos[i].nota);
  }

  printf("Maior nota....................: %.2f\n", maior);
  printf("Total de alunos aprovados.....: %i\n", total);
}

float media(float notas[30]) {
  int i;
  float total = 0;

  for (i = 0; i < 30; i++) {
    total += notes[i];
  }

  return total / 30;
}

float maiorNota(struct Aluno alunos[30]) {
  int i;
  float maior = 0;

  for (i = 0; i < 30; i++) {
    if (alunos[i].nota > maior) maior = alunos[i].nota;
  }

  return maior;
}

int totalAlunosAprovados(struct Aluno alunos[30]) {
  int i, total = 0;
  float media = 6;

  for (i = 0; i < 30; i++) {
    if (alunos[i].nota >= media) total++;
  }

  return total;
}
