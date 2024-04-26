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

void slice_tree(char line[], char** left_tree, char** right_tree) {

  char* token = strtok(line, " ");

  token = strtok(NULL, "\n");

  int count_parenteses = 0;
  int i = 0;
  int y = 0;

  while (1) {
    if (token[i] == '(') {
      count_parenteses++;
    }
    if (token[i] == ')') {
      count_parenteses--;
    }
    i++;
    if (count_parenteses == 0 && y == 0) {
      *left_tree = (char*)malloc(i + 1);
      strncpy(*left_tree, token, i);
      (*left_tree)[i] = '\0';
      y = i + 3;
      continue;
    }
    if(count_parenteses == 0 && y != 0 && i > y){
      *right_tree = (char*)malloc((i - 1) * sizeof(char));
      strncpy(*right_tree, token + y - 1, i - y + 1);
      (*right_tree)[i] = '\0';
      break;
    }
  }
}

t_binary_tree *create_tree(Node* root, char node_as_string[]) {
  if (strcmp(node_as_string, "()") == 0) {
    return NULL;
  }

  char* left_tree = NULL;
  char* right_tree = NULL;

  slice_tree(node_as_string, &left_tree, &right_tree);
  printf("Left: %s\n", left_tree);
  printf("Right: %s\n", right_tree);

  char left_elem = left_tree[1];
  char right_elem = right_tree[1];
  char root_elem = node_as_string[1];
  root = createNode(root_elem);

  root->left = createNode(left_elem);
  root->right = createNode(right_elem);
  
  create_tree(root->left, left_tree); 
  create_tree(root->right, right_tree);
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
      tree = create_tree(tree->root, token);
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

// (a, (b, (k, (), ()), (j, (), ())), (c, (f, (), ()), (g, (), ())))