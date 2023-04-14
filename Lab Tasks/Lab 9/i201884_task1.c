#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

void *tpalindrome();
void *T_odd();

int main(){

	pthread_t t1;
	
	pthread_create(&t1, NULL, tpalindrome, NULL);
	pthread_join(t1, NULL);	

    pthread_t t2;
	
	pthread_create(&t2, NULL, T_odd, NULL);
	pthread_join(t2, NULL);
	
	return 0;
}
void *tpalindrome()
{
 int n, reversed = 0, remainder, original;
    printf("Enter an integer: ");
    scanf("%d", &n);
    original = n;

    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    if (original == reversed)
        printf("%d is a palindrome.", original);
    else
        printf("%d is not a palindrome.", original);
}	

void *T_odd(){
	int odd=1;
	
	printf("\nOdd numbers:\n");
	
	while(odd<20){
		printf("%d\n",odd);
		odd=odd+2;
	}	
}
