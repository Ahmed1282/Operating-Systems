# include<stdio.h>
# include<stdlib.h>
# include<pthread.h>
void * thread_function ( void *arg ) ;
char message [ ] = " iam thread 1 " ;

int main ( ) {
pthread_t tid ;
pthread_create (&tid ,NULL, thread_function , ( void *) message ) ;
//In 2nd run make f o l l o w i n g s t a t e m e n t comment t h e n s e e
pthread_detach (tid) ;
int joinret;
joinret=pthread_join(tid ,NULL) ;
if(joinret==0) //when j o i n s u c c e s s f u l l
printf( "join was success full : The main thread was waiting for thread 1\n" ) ;
else
printf( "Join failed: The main thread is not waiting for thread 1\n ") ;
printf("The main thread finished, bye!\n");
pthread_exit (NULL) ;
}
void* thread_function ( void *arg){
sleep(2);
printf("thread_function is running.Argument was\"%s\"\n",(char *)arg);
printf("thread 1 awaked from sleep , and exiting now\n" ) ;
pthread_exit (NULL) ;
}
