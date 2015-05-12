#include <mpi.h>
#include <stdio.h>
#define N 3
int main(int argc, char* argv[]) {
  MPI_Init(&argc, &argv);
  int my_rank, comm_sz;
  int a, b, c, tmpA;
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

  // create two matrix
  int A[3][3] = {{1, 3, 3},
                 {1, 0, 0},
                 {1, 2, 2}};
  int B[3][3] = {{0, 0, 2},
                 {7, 5, 0},
                 {2, 1, 1}};
  int C[3][3] = {0};
  printf("caonima\n");
  //get data
  printf("fu\n");
  a = A[my_rank / N][my_rank % N];
  printf("fuck %d in %d", a, my_rank);

    //Broadcast
  for (int k = 0; k < N; ++k) {
      tmpA = a;
      MPI_Bcast(&tmpA, 1, MPI_INT, my_rank, MPI_COMM_WORLD);
      MPI_Recv(&tmpA, 1, MPI_INT, my_rank, my_rank, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        printf("fuckhere\n");
        //Multiply
        C[i][j] = tmpA * B[i][j];
        //Roll
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        //Roll
        B[i][j] = B[(i+1) % N][j];
      }
    }
  }
  //print the answer
  if (my_rank == 0) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (j) printf(" ");
        printf("%d", C[i][j]);
      }
      printf("\n");
    }
  }
  MPI_Finalize();
  return 0;
}
