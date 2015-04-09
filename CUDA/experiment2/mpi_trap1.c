if (my_rank != 0) {
  MPI_Send(&local_int, 1, MPI_DOUBLE, 0, 0,
           MPI_COMM_WORLD);
} else {
  total_int = local_int;
  for (source = 1; source < comm_sz; source++) {
    MPI_Recv(&local_int, 1, MPI_DOUBLE, source, 0,
             MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    total_int += local_int;
  }
}
if (my_rank == 0) {
  printf("With n = %d trapezoids, our estimate\n", n);
  printf("of the integral from %f to %f = %.15e\n",
       a, b, total_int);
}
