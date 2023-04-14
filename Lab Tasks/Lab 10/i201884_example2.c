#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *thread_function1 ( void *arg ) ;
void *thread_function2( void *arg) ;
char message1[ ]=" iam thread 1 " ; 
char message2[ ] =" iam thread 2 " ;
pthread_t tid1 , tid2 ;

int main ( ) {
pthread_create (& tid1 ,NULL, thread_function1 , ( void *) message1 ) ;
pthread_create (& tid2 ,NULL, thread_function2 , ( void *) message2 ) ;

pthread_detach ( tid1 ) ;
int joinret ;
joinret =pthread_join ( tid1 ,NULL) ;
// when j o i n s u c c e s s f u l l
if ( joinret==0)
printf ( "join was successfull : The main thread was waiting for thread 1\n" ) ;
else
printf ( " Join failed : The main thread is not waiting for thread 1\n" ) ;
pthread_join ( tid2 ,NULL) ;
printf ( "The main received exit status from tid2 , now exiting , bye !\n" ) ;
pthread_exit (NULL) ;
}
void *thread_function1 ( void *arg ) {

sleep ( 2 ) ;
printf ( " thread_function 1 is running . Argument was %s\n" , ( char *) arg ) ;
sleep(5) ;
printf ( " thread 1 awaked from sleep , and exiting now\n" ) ;
pthread_exit (NULL) ;
}
void *thread_function2 ( void *arg ) {
sleep (1) ;
int joinret ;
joinret =pthread_join ( tid1 ,NULL) ;
if (joinret ==0) // when j o i n s u c c e s s f u l l
printf ( " join was success full: The thread 2 was waiting for thread 1\n" ) ;
else
printf ( " join failed : The thread 2 is not waiting for thread 1\n" ) ;
printf ( " thread_function 2 is running . Argument was %s\n" , ( char *) arg ) ;
printf( " thread 2 is exiting now\n" ) ;
pthread_exit (NULL) ;
}
