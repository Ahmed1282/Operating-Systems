#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>

void *LCM( void *arg ) 
{
	int max;
	int *array=(int*)arg;
    max = (array[0] > array[1]) ? array[0] : array[1];

    while (1) 
    {
        if ((max % array[0] == 0) && (max % array[1] == 0)) {
            printf("The LCM of %d and %d is %d.", array[0], array[1], max);
            break;
        }
        ++max;
    }
    pthread_exit ( ( void *) max) ;
}

void *HCF(void *arg)
{
    int *array=(int*)arg;
    int a, b, i, hcf;
    a = array[0];
    b = array[1];
    for(i = 1; i <= a || i <= b; i++) {
    if( a%i == 0 && b%i == 0 )
      hcf = i;
    }
    printf("HCF = %d", hcf);
}

void *prim_fac( void *arg ) 
{
    int *array=(int*)arg;
    int i, j, num, isPrime;
    num = array[0];
    printf("All Prime Factors of %d are: ", num);
    for(i=2; i<=num; i++)
    {
        if(num%i==0)
        {
            isPrime = 1;
            for(j=2; j<=i/2; j++)
            {
                if(i%j==0)
                {
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime==1)
            {
                printf("%d, ", i);
            }
        }
    }

    int i1, j1, num1, isPrime1;
    num1 = array[1];
    printf("\nAll Prime Factors of %d are: ", num1);
    for(i1=2; i1<=num1; i1++)
    {
        if(num1%i1==0)
        {
            isPrime1 = 1;
            for(j1=2; j1<=i1/2; j1++)
            {
                if(i1%j1==0)
                {
                    isPrime1 = 0;
                    break;
                }
            }
            if(isPrime1==1)
            {
                printf("%d, ", i1);
            }
        }
    }
}


int main() {
	int n1;
	int n2;
	int choice;
	printf("Enter the first number: ");
	scanf("%d",&n1);
	printf("Enter the second number: ");
	scanf("%d",&n2);
	
	int arr[2]={n1,n2};
	printf("\n1. LCM ");
	printf("\n2. HCF ");
	printf("\n3. prime factors of both. ");
	printf("\n\nEnter the operation: ");
	scanf("%d",&choice);
	
	pthread_t td1 , td2, td3;
	if(choice==1){
		void *t1;
		pthread_create (& td1 , NULL, LCM , arr) ;
		pthread_join (td1 , &t1) ;
	}
	else if(choice == 2){
		void *t2;
		pthread_create (& td2 , NULL, HCF , arr) ;
		pthread_join (td2 , &t2) ;
	}
	else if(choice == 3){
		void *t3;
		pthread_create (& td3 , NULL,prim_fac  , arr) ;
		pthread_join (td3 , &t3) ;
	}	
	exit( 0 ) ;
}	
