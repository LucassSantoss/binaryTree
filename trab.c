/*
Lucas Pereira dos Santos
Tiago Catoia
Bruno Mascioli
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 10

typedef struct _Node {
  char item;
  struct _Node* left;
  struct _Node* right;
} Node;

typedef struct {
  Node* root;
} t_binary_tree;

Node* createNode(char item) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr, "Erro ao alocar mem�ria.\n");
    exit(1);
  }
  newNode->item = item;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void slice_tree(char line[], char** left_tree, char** right_tree) {
    char* token = strtok(line, " ");

    token = strtok(NULL, "\n");

    int count_parenteses = 0;
    int i = 0;
    int y = 0;

    while (1) {
        if (token[i] == '(') 
            count_parenteses++;
        if (token[i] == ')') 
            count_parenteses--;
        i++;
        if (count_parenteses == 0 && y == 0) {
            *left_tree = (char*)malloc(i + 1);
            strncpy(*left_tree, token, i);
            (*left_tree)[i] = '\0';
            y = i + 2; 
            continue;
        }
        
        if (count_parenteses == 0 && y != 0 && i > y) {
            *right_tree = (char*)malloc((i - y + 1) * sizeof(char));
            strncpy(*right_tree, token + y, i - y);
            (*right_tree)[i - y] = '\0';
            break;
        }
    }
}


Node* create_tree(Node* root, char tree_as_string[]) {
  if (strcmp(tree_as_string, "()") == 0) return NULL;
  
  char* left_tree = NULL;
  char* right_tree = NULL;
  char root_elem = tree_as_string[1];

  root = createNode(root_elem);
  slice_tree(tree_as_string, &left_tree, &right_tree);

  if(strcmp(left_tree, "()") != 0){
    root->left = create_tree(root->left, left_tree); 
    free(left_tree); 
  }

  if(strcmp(right_tree, "()") != 0){
    root->right = create_tree(root->right, right_tree);
    free(right_tree);
  }

  return root;
}


void print_tree(Node* root, int space) {
  if(root == NULL) return;

  space += COUNT;

  print_tree(root->right, space);

  printf("\n");
  int i;
  for(i = COUNT; i < space; i++){
    printf(" ");
  }
  printf("%c\n", root->item);

  print_tree(root->left, space);
}

void in(Node* root) {
  if (root == NULL) return;
  in(root->left);
  printf("%c ", root->item);
  in(root->right);
}

void pre(Node* root) {
  if (root == NULL)  return;
  printf("%c ", root->item);
  pre(root->left);
  pre(root->right);
}

void post(Node* root) {
  if (root == NULL) return;
  post(root->left);
  post(root->right);
  printf("%c ", root->item);
}

void destroy(Node* node) {
  if (node == NULL) return;
  destroy(node->left);
  destroy(node->right);
  free(node);
}

int main(int argc, char const *argv[]) {
  t_binary_tree* tree = (t_binary_tree*) malloc(sizeof(t_binary_tree));
  tree->root = NULL;

  char line[1000];
  do {
    fgets(line, 1000, stdin);
    char* token = strtok(line, " ");
    if (strcmp(token, "create") == 0) {
      token = strtok(NULL, "\n");
      tree->root = create_tree(tree->root, token);
    } else if (strcmp(line, "print\n") == 0) {
      print_tree(tree->root, 0);
    } else if (strcmp(line, "in\n") == 0) {
      in(tree->root);
      printf("\n");
    } else if (strcmp(line, "pre\n") == 0) {
      pre(tree->root);
      printf("\n");
    } else if (strcmp(line, "post\n") == 0) {
      post(tree->root);
      printf("\n");
    }
  } while (strcmp(line, "exit\n") != 0);

  destroy(tree->root);
  return 0;
}
