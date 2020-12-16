#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char key[10];
  struct node *left, *right;
};

struct node *newNode(char item[]) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  strcpy(temp->key,item);
  temp->left = temp->right = NULL;
  return temp;
}

struct node *insert(struct node *node, char key[]) {

  if (node == NULL) return newNode(key);

  if (strcmp(key,node->key)<0)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%s -> ", root->key);
    inorder(root->right);
  }
}

char* search(struct node *root, char key[]) {
	if(root == NULL) 
	    return NULL;
	if(strcmp(key,root->key)==0) 
	    return root->key;
	if(strcmp(key,root->key)<0)
	    return search(root->left,key);
	if(strcmp(key,root->key)>0)
	    return search(root->right,key);
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

struct node *deleteNode(struct node *root, char key[]) {

  if (root == NULL) return root;

  if (strcmp(key,root->key)<0)
    root->left = deleteNode(root->left, key);
  else if (strcmp(key,root->key)>0)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } 
    else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *temp = minValueNode(root->right);
    strcpy(root->key,temp->key);
    root->right = deleteNode(root->right, temp->key);
  }

  return root;
}

int main() {
  struct node *root = NULL;

  root = insert(root, "Dhanush");
  root = insert(root, "Bala");
  root = insert(root, "Elumalai");
  root = insert(root, "Arun");
  root = insert(root, "Bhuvanesh");
  root = insert(root, "Himanshu");
  root = insert(root, "Garima");
  root = insert(root, "Indrajit");
  root = insert(root, "Faisal");
  root = insert(root, "James");

  printf("Inorder traversal: ");
  inorder(root);

  root = insert(root, "Harish");
  root = insert(root, "Ajay");

  printf("Inorder traversal: ");
  inorder(root);

  root = deleteNode(root, "Bhuvanesh");
  root = deleteNode(root, "Arun");
  root = deleteNode(root, "Indrajit");
  root = deleteNode(root, "Himanshu");

  printf("Inorder traversal: ");
  inorder(root);

  search(root, "Harish");
  search(root, "Ajay");

  getchar();
  return 0;
}
