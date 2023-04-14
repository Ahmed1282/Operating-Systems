#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<pthread.h>

int size = 0;

void* fun1(void* ptr) {
	int* a = (int*) ptr;
	int flag = 0, sum = 0;
	for (int x = 0; x < size; x++) {
		flag = 0;
		if (a[x] == 0 || a[x] == 1) {
		    flag = 1;
		}
		for (int i = 2; i <= (a[x]/2); ++i) {
		    	if (a[x] % i == 0) {
		   	   flag = 1;
		      	   break;
		    	}
		}
		if (flag == 0) {
	    		sum = sum + a[x];
		}
	}
	pthread_exit((void*)sum);
}

void* fun2(void* ptr) {
	int a = (int*) ptr;
	while (a >= 300) {
		a = a / 300;
	}
	pthread_exit((void*)a);
}

int main() {
	pthread_t t1, t2;
	printf("Enter size of array: ");
	scanf("%d", &size);
	int arr[size];
	for (int i = 0; i < size; i++) {
		printf("Enter element %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	pthread_create(&t1, NULL, fun1, (void*)arr);
	void* status;	
	pthread_join(t1, &status);
	printf("Sum: %d\n", (int)status);	
	pthread_create(&t2, NULL, fun2, (void*)status);
	void* status2;	
	pthread_join(t2, &status2);
	printf("Val: %d\n", (int)status2);
	int sumTwo = (int)status + (int)status2;
	int r, sum = 0, temp;    
	temp = sumTwo;    
	while(sumTwo > 0)    
	{    
		r = sumTwo % 10;    
		sum = (sum * 10) + r;    
		sumTwo = sumTwo/10;    
	}    
	if(temp == sum) {   
		printf("Palindrome Number!\n");
	}    
	else {    
		printf("Not Palindrome!\n");
	}   
	pthread_exit(NULL);
	return 0;
}
