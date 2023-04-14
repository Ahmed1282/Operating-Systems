#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int tamount=0;
pthread_mutex_t mutex1 ;
pthread_t tid1 , tid2 , tid3 , tid4;

void *deposit1 ( void *arg ) {
int x=tamount;
pthread_mutex_lock ( &mutex1 ) ;
x+=11;
sleep(1);
tamount+=x;
printf("deposit %d\n",tamount);
pthread_mutex_unlock ( &mutex1 ) ;
pthread_exit(NULL);
}

void *deposit2( void *arg) {
int y=tamount;
pthread_mutex_lock ( &mutex1 ) ;
y+=11;
sleep(1);
tamount+=y;
printf("deposit %d\n",tamount);
pthread_mutex_unlock ( &mutex1 ) ;
pthread_exit(NULL);
}

void *withdraw1( void *arg) {
int y=tamount;
pthread_mutex_lock ( &mutex1 ) ;
y-=10;
sleep(1);
if(tamount>10)
tamount=-y;
printf("withdraw %d\n",tamount);
pthread_mutex_unlock ( &mutex1 ) ;
pthread_exit(NULL);
}

void *withdraw2( void *arg) {
int y=tamount;
pthread_mutex_lock ( &mutex1 ) ;
y-=10;
sleep(1);
if(tamount>10)
tamount=-y;
printf("withdraw %d\n",tamount);
pthread_mutex_unlock ( &mutex1 ) ;
pthread_exit(NULL);
}

int main(){
pthread_mutex_init (&mutex1 ,NULL) ;
pthread_create (& tid1 ,NULL, deposit1 , NULL );
pthread_create (& tid2 ,NULL, deposit2 , NULL );
pthread_create (& tid3 ,NULL, withdraw1 , NULL );
pthread_create (& tid4 ,NULL, withdraw2 , NULL );
/*printf( " Thread 1 ID : %ld \n" , tid1 ) ;
printf( " Thread 2 ID : %ld \n" , tid2 ) ;*/
pthread_join ( tid1 , NULL) ;
pthread_join ( tid2 , NULL) ;
pthread_join ( tid3 , NULL) ;
pthread_join ( tid4 , NULL) ;
pthread_mutex_destroy(&mutex1 ) ;
pthread_exit (NULL) ;
exit(0) ;


}