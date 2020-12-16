#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
int data, id;
char name[100];
struct node *previous;
struct node *next;
};
struct node *head, *tail = NULL;
void addNode (int data, char name[100], int id){
struct node *newNode = (struct node *) malloc (sizeof (struct node));
newNode->data = data;
strcpy (newNode->name, name);
newNode->id = id;
if (head == NULL)
{
head = tail = newNode;
head->previous = NULL;
tail->next = NULL;
}
else
{
tail->next = newNode; 

newNode->previous = tail;
tail = newNode;
tail->next = NULL;
}
}
void sortList ()
{
struct node *current = NULL, *index = NULL;
int temp;
if (head == NULL)
{
return;
}
else
{
for (current = head; current->next != NULL; current = current->next)
{
for (index = current->next; index != NULL; index = index->next)
{
if (current->data < index->data)
{
temp = current->data; current->data = index->data; index->data = temp;
}
}
}
}
}
void display ()
{
int count = 1;
struct node *current = head; 
if (head == NULL)
{
printf ("List is empty\n"); return;
}
while (current != NULL)
{
printf ("year-%d, name-%s, id-%d \n", current->data, current->name, current->id);
count += 1;
current = current->next;
}
printf ("\n");
}
int main ()
{
int i, n, j, m, k; char arr[100];
printf ("enter the number of students :");
scanf ("%d", &n);
m = n - 10;
if (n <= 10)
{
for (i = 0; i < n; i++)
{
printf ("enter year:");
scanf ("%d", &j);
printf ("enter name:");
scanf ("%s", &arr);
printf ("enter id:");
scanf ("%d", &k);
addNode (j, arr, k);
}
}

else
{
for (i = 0; i < 10; i++)
{
printf ("enter year:");
scanf ("%d", &j);
printf ("enter name:");
scanf ("%s", &arr);
printf ("enter id:");
scanf ("%d", &k);
addNode (j, arr, k);
}
for (i = 0; i < m; i++)
{
printf ("enter year:");
scanf ("%d", &j);
}
}
sortList ();
printf ("Sorted list: \n");
display ();
return 0;
}
