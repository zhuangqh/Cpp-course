#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  pid_t pid1 = fork();
  printf("**1**\n");
  if (pid1 == 0) {
    pid_t pid2 = fork();
    printf("**2**\n");
  } else {
    printf("**3**\n");
  }
  return 0;
}
