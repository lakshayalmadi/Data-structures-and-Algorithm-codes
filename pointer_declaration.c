#include <stdio.h>
int main()
{
 int x=10, int1, int2, *pointer;
 pointer=&x;
 printf("%u address x \n", pointer);
 printf("%u address x \n", &x);
 printf("%u value x \n", *pointer);
 printf("%u address int1 \n", &int1);
 printf("%u address int2 \n", &int2);
 printf("%u address pointer ", &pointer);

}
