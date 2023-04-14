#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

#include <unistd.h>

int var=10;

 

pthread_mutex_t mutx;


void *fun1(void*args)

{

pthread_mutex_lock(&mutx);

int x = var;

x++;

sleep(1);

var = x;

pthread_mutex_unlock(&mutx);

pthread_mutex_destroy(&mutx);

printf("%d\n", var);

}

void *fun2(void* args)

{

pthread_mutex_lock(&mutx);

int y = var;

y++;

sleep(1);

var = y;

pthread_mutex_unlock(&mutx);

pthread_mutex_destroy(&mutx);

printf("%d\n", var);

}

int main()

{

    pthread_t td1 , td2;

    pthread_mutex_init(&mutx,NULL);

     pthread_create (& td1 , NULL, fun1 , NULL);

        pthread_create (& td2 , NULL, fun2 , NULL);

    pthread_exit(NULL);

        //int join3 = pthread_join(td1,NULL);



return 0;

}