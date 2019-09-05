#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main(void) {
  if (!fork()){
    printf("hi\n");
    fork();
    printf("hello");
  }else{ printf("bye\n");}
 

  return 0;
}