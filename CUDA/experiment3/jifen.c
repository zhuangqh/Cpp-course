#include <stdio.h>
#include <mpi.h>
void Get_input(int my_rank, int comm_sz, double* a_p, double* b_p,
               int* n_p);
double func(double x);
double Trap(double , double , int, double);
int main(int argc, char* argv[]) {
  MPI_Init(&argc, &argv);
  int my_rank, comm_sz, n, local_n;
  double a, b;
  double local = 0.0, total = 0.0;
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

  //get data
  Get_input(my_rank, comm_sz, &a, &b, &n);

  double local_a, local_b, h;

  //compute the area
  h = (b - a) / n;
  local_n = n / comm_sz;
  local_a = a + my_rank * local_n * h;
  local_b = local_a + local_n * h;
  local = Trap(local_a, local_b, local_n, h);

  MPI_Reduce(&local, &total, 1, MPI_DOUBLE, MPI_SUM, 0,
             MPI_COMM_WORLD);

  //output the answer
  if (my_rank == 0) {
    printf("With n = %d trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.15e\n",
           a, b, total);
  }
  MPI_Finalize();
  return 0;
}
void Get_input(int my_rank, int comm_sz, double* a_p, double* b_p,
               int* n_p) {
  int dest;
  if (my_rank == 0) {
    printf("Enter a, b and n\n");
    scanf("%lf%lf%d", a_p, b_p, n_p);
    for (dest = 1; dest < comm_sz; ++dest) {
      MPI_Send(a_p, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD);
      MPI_Send(b_p, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD);
      MPI_Send(n_p, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
    }
  } else {
    MPI_Recv(a_p, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(b_p, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(n_p, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
}
double func(double x) {
  return x * x;
}
double Trap(double local_a, double local_b, int local_n, double h) {
  int i;
  double ans = 0.0;
  for (i = 0; i < local_n; ++i) {
    ans += h * (func(local_a + i*h) + func(local_a + (i+1)*h)) / 2.0;
  }
  return ans;
}
