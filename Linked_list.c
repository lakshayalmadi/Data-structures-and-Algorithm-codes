#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Node {
  int item;
  char name[50];
  int registrationNumber;
  int age;
  int phoneNumber;
//   static int ageConstraint=5;
  struct Node* next;
  
};

void insertAtEnd(struct Node** ref, int data,char name[50],int reg,int age) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  strcpy(new_node->name,name);

  new_node->age=age;
  new_node->registrationNumber=reg;
  
  struct Node* last = *ref;

  new_node->item = data;
  new_node->next = NULL;

  if (*ref == NULL) {
    *ref = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

void deleteNode(struct Node** ref, int key) {
  struct Node *temp = *ref, *prev;

  if (temp != NULL && temp->item == key) {
    *ref = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->item != key) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) return;

  prev->next = temp->next;

  free(temp);
}

void printList(struct Node* node) {
  while (node->next != NULL) {
    printf("%d.%s -> ",node->item, node->name);
    node = node->next;
  }
printf("%d.%s \n",node->item, node->name);

}
int checkList(struct Node* head){
    int arr[100]={0};
    struct Node*temp=head;
    int max_age=0;
    while(temp!=NULL){
        arr[temp->age]++;
        if(max_age<temp->age)max_age=temp->age;
        temp=temp->next;
    }
    for(int i=0;i<max_age;i++){
        if(arr[i]>5)return 0;
    }
    return 1;
}
int main() {
  struct Node* head = NULL;

  insertAtEnd(&head, 1,"mohan",10171,18);
  if(!checkList(head)){
          printf(" %s ","List cannot contain more students with the same age\n");
  }
  insertAtEnd(&head, 2,"lakshay",10172,18);
    if(!checkList(head)){
          printf(" %s ","List cannot contain more students with the same age\n");
  }
  insertAtEnd(&head, 3,"varun",10173,18);
    if(!checkList(head)){
          printf(" %s ","List cannot contain more students with the same age\n");
  }
  insertAtEnd(&head, 4,"adi",10174,18);
    if(!checkList(head)){
          printf(" %s ","List cannot contain more students with the same age\n");
  }
  insertAtEnd(&head, 5,"tony",10175,18);
  if(!checkList(head)){
          printf(" %s ","List cannot contain more students with the same age\n");
  }
    insertAtEnd(&head, 6,"handy",10176,18);
  if(!checkList(head)){
          printf(" %s ","List cannot contain more students with the same age\n");
          deleteNode(&head,6);
  }
  printf("Linked list: ");
  printList(head);

  printf("\nAfter deleting an element: ");
  deleteNode(&head, 3);
  printList(head);
}
