#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char* substring(const char* string, int start, int end) {
    int length = strlen(string);
    
    if (start < 0 || start >= length || end < start || end >= length) {
        return NULL; 
    }

    int sub_length = end - start + 1;

    char* substring = (char*)malloc((sub_length + 1) * sizeof(char));

    strncpy(substring, string + start, sub_length);

    substring[sub_length] = '\0';

    return substring;
}


int main(int argc, char const *argv[]){
  char line[100] = "(a, (213213, (233), (322)), (3213123,(2123),(2321)))";

   char * token = strtok(line, " ");

  token = strtok(NULL, "\n");
  //printf( " %s\n", token );

  int count_parenteses = 0;
  int i = 0;
  int y = 0;
  char* left_tree;
  char* right_tree;
  // Conta os parênteses à esquerda
  while (1) {
    if (token[i] == '(') {
      count_parenteses++;
    }
    if (token[i] == ')') {
      count_parenteses--;
    }
    i++;
    if (count_parenteses == 0 && y == 0) {
      left_tree = (char*)malloc(i + 1);
      strncpy(left_tree, token, i);
      left_tree[i] = '\0';
      y = i + 3;
      continue;
    }
    printf("i = %d | y = %d | i - y = %d\n", i, y, i-y);
    if(count_parenteses == 0 && y != 0 && i > y){

      right_tree = (char*)malloc((i - 1) * sizeof(char));
      strncpy(right_tree, token + y - 1, i - y + 1);

      right_tree[i] = '\0';
      break;
    }
  }

  printf("Left: %s\n", left_tree);
  printf("Right: %s\n", right_tree);

  //free
  return 0;
}
