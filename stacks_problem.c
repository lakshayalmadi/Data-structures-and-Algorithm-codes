#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int max(int a, int b, int c)
{
if(a>b && a>c)
{
return a;
}
else

{
if(c<b)
{
return b;
}
else
{
return c;
}
}
}
int min(int a, int b, int c)
{
if(a<b && a<c)
{
return a;
}
else

{
if(c<b)
{
return c;
}
else
{
return b;
}
}
}
int main() {
int a,b,c,i;
int minimum=4; 
int maximum;
cin>>a>>b>>c;
int d[a],e[b],f[c];
long long int x=0,y=0,z=0;
for(i=0;i<a;i++)
    {       cin>>d[i];
    x=x+d[i];   }
for(i=0;i<b;i++)
   { cin>>e[i];
    y=y+e[i]; }
for(i=0;i<c;i++)
    { cin>>f[i];
    z=z+f[i]; }
minimum = min(a, b, c);
maximum=-10000;
int final[3*minimum];
for(i=0;i<minimum;i++)
{
	maximum=max(d[i],e[i],f[i]);
  final[i*3]  = d[i];
  final[i*3+1]= e[i];
  final[i*3+2]= f[i];
  
}
cout<<maximum  ;
for(i=0;i<3*minimum;i++)
{
	cout<<final[i]  ;
}
}
