#include<stdlib.h>
#include<stdio.h>
#define size 50
char s[size];
int top=-1;
void push(char ele)
{
s[++top]=ele;
}
char pop()
{
return s[top--];
}
int prec(char ele)
{
if(ele=='(')
return 0;
if(ele=='+'||ele=='-')
return 1;
if(ele=='^')
return 3;
else
return 2;
}
void postfix(char exp[20])
{int i=0;
char postfix[20];
int ctr=0;
push('(');
char ch=exp[0];
while(exp[i]!='\0')
{
ch=exp[i];
if(ch=='(')
{push('(');
i++;
}
else if(ch==')')
{
while(s[top]!='(')
{
postfix[ctr++]=pop();
}
pop();
i++;
}
else if(ch=='*'||ch=='-'||ch=='+'||ch=='/'||ch=='^')
{
while(prec(s[top])>=prec(ch))
{postfix[ctr++]=pop();}
push(ch);
i++;
}
else
{
postfix[ctr++]=ch;
i++;
}
}
postfix[ctr]='\0';
for(int i=0;i<ctr;i++)
{
printf("%c",postfix[i]);
}
}
int main()
{
char infix[20];
printf("enter the infix expression");
gets(infix);
postfix(infix);
return 0;
}
