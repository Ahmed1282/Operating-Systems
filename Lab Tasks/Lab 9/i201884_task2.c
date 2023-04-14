#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h> 

void *T_fileopen(void *args){
	
	int f1;
	
	f1 = open("lab9.txt",O_CREAT,0777);
	close(f1);
	
}

void *T_filewrite(void *args){
	
	int f2;
	char a[6];
	
	printf("Enter: ");
        scanf("%s", a);
	
	f2 = open("lab9.txt", O_WRONLY,0777);
	write(f2,a,sizeof(a));
	close(f2);
}
	


int main(){
	
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, T_fileopen, NULL);
	pthread_join(t1, NULL);
	
	
	pthread_create(&t2, NULL, T_filewrite, NULL);
	pthread_join(t2, NULL);
	
	return 0;
}
