#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

struct data{
	char name[20];
	int age,expe;
	char product[20];
};

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int main(){
	struct data arr[10];
	for(int i=0;i<10;i++){
		scanf("%s %d %d %s",&arr[i].name,&arr[i].age,&arr[i].expe,&arr[i].product);
	}
	for (int i = 0; i < 10; i++){
       for (int j = 0; j < 10-i; j++) { 
           if (arr[j].expe > arr[j+1].expe){
              swap(&arr[j], &arr[j+1]); 
           }
       }
	}
	for(int i=0;i<10;i++){
		for(int j=i+1;j<10;j++){
			if(strcmp(arr[i].product,arr[j].product)==0){
				printf("These  sales representatives have common products :\n");
				printf("%s %d %d %s\n",arr[i].name,arr[i].age,arr[i].expe,arr[i].product);
				printf("%s %d %d %s\n",arr[i].name,arr[i].age,arr[i].expe,arr[i].product);
			}
		}
	}

	getchar();
	return 0;
