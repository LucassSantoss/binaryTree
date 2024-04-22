#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char line[100] = "(a, (b, (), ()), (c,(),()))";
    // (A, (B, (), ()))

   char * token = strtok(line, " ");

  printf( " %s\n", token );
  token = strtok(NULL, "\n");
  printf( " %s\n", token );

  int count_parenteses = 0;
  while (count_parenteses !)
   
  
  return 0;
}
