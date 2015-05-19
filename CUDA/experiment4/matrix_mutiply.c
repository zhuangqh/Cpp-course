#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
int N, M;
int *matrix;
int *vector;
int *ans;
int *Index;
void* compute(void *);
int main() {
  int i, j;
  scanf("%d%d", &N, &M);
  matrix = (int *)malloc(sizeof(int) * N * M);
  vector = (int *)malloc(sizeof(int) * M);
  ans = (int *)malloc(sizeof(int) * N);
  Index = (int *)malloc(sizeof(int) * N);
  //initialize the array of index and answer
  memset(ans, 0, sizeof(*ans));
  for (i = 0; i < N; ++i)
    Index[i] = i;
  //read data
  for (i = 0; i < N; ++i) {
    for (j = 0; j < M; ++j) {
      scanf("%d", matrix + i * N + j);
    }
  }
  for (i = 0; i < M; ++i)
    scanf("%d", vector + i);
  //handle data
  pthread_t *tids = (pthread_t *)malloc(sizeof(pthread_t) * N);
  for (i = 0; i < N; ++i) {
    pthread_create(&tids[i], NULL, compute, &Index[i]);
  }
  //wait others
  for (i = 0; i < N; ++i)
    pthread_join(tids[i], NULL);

  //print the answer
  printf("The answer of the mutiplication is\n");
  for (i = 0; i < N; ++i)
    printf("%d\n", ans[i]);
  return 0;
}
void* compute(void* arg) {
  const int index = *(int *)arg;
  int i;
  for (i = 0; i < M; ++i) {
    ans[index] += matrix[index * N + i] * vector[i];
  }
  pthread_exit(NULL);
}
