/*
Lucas Pereira dos Santos
Tiago Catoia
Bruno Mascioli
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
  char item;
  struct _Node *left;
  struct _Node *right;
} Node;

typedef struct {
  Node *root;
} t_binary_tree;

Node *createNode(char item) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr, "Erro ao alocar memória.\n");
    exit(1);
  }
  newNode->item = item;
  newNode->left = newNode->right = NULL;
  return newNode;
}

t_binary_tree *create_tree(Node* root, char node_as_string[]) {
  //(a, (b,(),()), (c,(),()))
  if (strcmp(node_as_string, "()" == 0)) {
    return NULL;
  }

  // raiz = a;
  // tree_left = (b,(),());
  // tree_right = (c,(),());
  
  char tree_left[];
  char tree_right[];

  if(strcmp(tree_left, "()") != 0){
    char elem_left = b;
  }
  
  if(strcmp(tree_rigth, "()") != 0){
    char elem_right = c;
  }

  char elem = node_as_string[1];
  Node* root = createNode(elem);
  Node* root->left = createNode(elem_left);
  Node* root->right = createNode(elem_right);
  
  create_tree(root->left, tree_left);
  create_tree(root->right, tree_rigth);

}

void print(Node *root) {}

void in(Node *root) {
  if (root == NULL) {
    printf("A árvore ainda não foi criada!\n");
    return;
  }
  in(root->left);
  printf("%d ", root->item);
  in(root->right);
}

void pre(Node *root) {
  if (root == NULL) {
    printf("A árvore ainda não foi criada!\n");
    return;
  }
  printf("%d ", root->item);
  pre(root->left);
  pre(root->right);
}

void pos(Node *root) {
  if (root == NULL) {
    printf("A árvore ainda não foi criada!\n");
    return;
  }
  pos(root->left);
  pos(root->right);
  printf("%d ", root->item);
}

int main(int argc, char const *argv[]) {
  t_binary_tree *tree = (t_binary_tree *)malloc(sizeof(t_binary_tree));
  tree->root = NULL;

  char line[100];
  fgets(line, 100, stdin);
  while (strcmp(line, "exit") != 0) {
    char *token = strtok(line, " ");

    if (strcmp(token, "create") == 0) {
      token = strtok(NULL, "\n");
      printf("%s\n", token);
      tree = create(tree->root, token);
    } else if (strcmp(line, "print") == 0) {
      print(tree->root);
    } else if (strcmp(line, "in") == 0) {
      in(tree->root);
    } else if (strcmp(line, "pre") == 0) {
      pre(tree->root);
    } else if (strcmp(line, "pos") == 0) {
      pos(tree->root);
    }
    fscanf(stdin, "%s", line);
  }
  return 0;
}
// (A, (B, (), ()))