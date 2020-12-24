#include<stdio.h>
// #include<process.h>
#include<stdlib.h>
#define MAX 10
int top=-1,stack[MAX];
void push();
void pop();
void display();
void main()
{
int ch;
while(1) //infinite loop, will end when choice will be 4
{
printf("1.Push 2.Pop 3.Display 4.Exit");
printf("\n\nEnter your choice(1-4)");
scanf("%d",&ch);
if(ch==1)
{
push();
}
else if(ch==2)
pop();
else if(ch==3)
display();
else
break;
}
}
void push()
{
int val;
if(top==MAX-1)
{
printf("\nStack is full!!");
}
else
{
printf("\nEnter element to push:");
scanf("%d",&val);
top=top+1;
stack[top]=val;
}
}
void pop()
{
if(top==-1)
{
printf("\nStack is empty!!");
}
else
{
printf("\nDeleted element is %d",stack[top]);
top=top-1;
}
}
void display()
{
int i;
if(top==-1)
{
printf("\nStack is empty");
}
else
{
printf("\nStack is...\n");
for(i=top;i>=0;--i)
printf("%d\n",stack[i]);
}
}
