#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

int var=10;

 pthread_t td1 , td2;

void *fun1(void*args)

{

int join1 = pthread_join(td1,NULL);

int x = var;

x++;

var = x;

printf("%d\n", var);

}

void *fun2(void* args)

{

int y = var;

y++;

var = y;

printf("%d\n", var);

}

int main()

{

     pthread_create (& td1 , NULL, fun1 , NULL);

        pthread_create (& td2 , NULL, fun2 , NULL);

        int join3 = pthread_join(td1,NULL);



return 0;

}