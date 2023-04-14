#include <iostream>
#include <pthread.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <cmath>
#include <thread>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

pthread_t tid[9];
int A[3][3], B[3][3], AB[3][3];

void *multi(void *arg)
{
    int* array = (int *) arg;
    AB[array[0]][array[1]] = (A[array[0]][0] * B[0][array[1]]) + (A[array[0]][1] * B[1][array[1]]) + (A[array[0]][2] * B[2][array[1]]);
    pthread_exit(NULL);
}

int main()
{
    int max = 3;
    int ind[2] = {0,0};
    cout << "Matrix A" << endl;
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            cout << "Enter [" << i + 1 << "][" << j + 1 << "] : ";
            cin >> A[i][j];
            A[i][j] = j;
        }
    }

    cout<<endl;
    cout << "Matrix B" << endl;
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            cout << "Enter [" << i + 1 << "][" << j + 1 << "] : ";
            cin >> B[i][j];
        }
    }

    cout<<endl;
    for (int i = 0, k = 0; i < max; i++)
    {
        for(int j = 0; j < max; j++, k++)
        {
            ind[0] = i;
            ind[1] = j;
            
            pthread_create(&tid[k], NULL, multi, (void *) ind);
            pthread_join(tid[k], NULL);
        }
    }
    cout<<endl;
    cout << "Matrix AB" << endl;
    for (int i = 0; i < max; i++)
    {
        cout << "| ";
        for (int j = 0; j < max; j++)
        {
            cout << AB[i][j] << " ";
        }
        cout << "|" << endl;
    }
    pthread_exit(NULL);
}