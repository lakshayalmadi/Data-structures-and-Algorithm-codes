#include<stdio.h>
#include<stdlib.h>
s
truct BST

{
int key;
struct BST *ptroleftchild;
struct BST * ptrtorightchild;
};

struct BST * maketree(nwkey){

struct BST* prtonwnode = malloc(sizeof(struct BST));

prtonwnode->key = nwkey;

prtonwnode->ptroleftchild = NULL;

prtonwnode->ptrtorightchild = NULL;

return prtonwnode;

}
void printPostorder(struct BST* nodeoriginal)
{
if (nodeoriginal == NULL)
return;


printPostorder(nodeoriginal->ptroleftchild);


printPostorder(nodeoriginal->ptrtorightchild);


printf("%d ", nodeoriginal->key);
}


struct BST* insertionofnode(struct BST* nodeoriginal, int key)

{

if (nodeoriginal == NULL) return maketree(key);

if (key < nodeoriginal->key)

nodeoriginal->ptroleftchild = insertionofnode(nodeoriginal->ptroleftchild, key);

else if (key > nodeoriginal->key)

nodeoriginal->ptrtorightchild = insertionofnode(nodeoriginal->ptrtorightchild, key);


return nodeoriginal;

}

void inordertrav(struct BST* nodeoriginal){

if(nodeoriginal == NULL) return;

inordertrav(nodeoriginal->ptroleftchild);

printf("%d ->", nodeoriginal->key);

inordertrav(nodeoriginal->ptrtorightchild);

}
void printPreorder(struct BST* nodeoriginal)
{
if (nodeoriginal == NULL)
return;

printf("%d ", nodeoriginal->key);

printPreorder(nodeoriginal->ptroleftchild);

printPreorder(nodeoriginal->ptrtorightchild);
}
struct BST* minValueNode(struct BST* node)
{
struct BST* current = node;

while (current && current->ptroleftchild != NULL)
current = current->ptroleftchild;

return current;
}
struct BST* deleteNode(struct BST* nodeoriginal, int key)
{

if (nodeoriginal == NULL) return nodeoriginal;

if (key < nodeoriginal->key)
nodeoriginal->ptroleftchild = deleteNode(nodeoriginal->ptroleftchild, key);

else if (key > nodeoriginal->key)
nodeoriginal->ptrtorightchild = deleteNode(nodeoriginal->ptrtorightchild, key);


else
{

if (nodeoriginal->ptroleftchild == NULL)
{
struct BST* temp = nodeoriginal->ptrtorightchild;
free(nodeoriginal);
return temp;
}
else if (nodeoriginal->ptrtorightchild == NULL)
{
struct BST*temp = nodeoriginal->ptroleftchild;
free(nodeoriginal);
return temp;
}


struct BST* temp = minValueNode(nodeoriginal->ptrtorightchild);
nodeoriginal->key = temp->key;
nodeoriginal->ptrtorightchild = deleteNode(nodeoriginal->ptrtorightchild, temp->key);
}
return nodeoriginal;
}
int main(){

struct BST *nodeoriginal = NULL;
while(1){
int ch; //choice
int n;
printf("\t\t\t\t WELCOME TO THE BINARY SEARCH TREE\n");
printf("\n0.INSERT_FIRST_NODE\t1.INSERT\t2.PRINT_INORDER\t3.PRINT_POST_ORDER\t4.PRINT_PRE_ORDER\t5.DELETE_NODE\t6.EXIT\n");
printf("\nEnter your choice");
scanf("%d",&ch);
switch(ch){
case 0:
printf("\nEnter the first node value: ");
scanf("%d",&n);
nodeoriginal = insertionofnode(nodeoriginal, n);
break;
case 1:
printf("\nEnter the node value: ");
scanf("%d",&n);
insertionofnode(nodeoriginal, n);
break;
case 2:
inordertrav(nodeoriginal);
break;
case 3:
printPostorder(nodeoriginal);
break;
case 4:
printPreorder(nodeoriginal);
break;
case 5:
printf("\nEnter the node value to be deleted: ");
scanf("%d",&n);
deleteNode(nodeoriginal, n);
break;
case 6:
exit(0);
break;
}
}

}
