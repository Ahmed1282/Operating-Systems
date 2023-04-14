// Code taken from: https://www.geeksforgeeks.org/merge-sort/ and https://www.geeksforgeeks.org/merge-sort-using-multi-threading/
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

using namespace std;

int *arr;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void printarr(int *arr, int size)
{
    cout << "The array is as follows:  " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int highestfactor(int num, int div)
{
    int divisor = 0;
    for (int i = div + 1; i < num; i++)
    {
        i % div == 0 ? divisor = i : divisor = divisor;
    }
    return divisor;
}

void *sortarr(void *arg)
{
    int *arr1 = (int *)arg;
    int *arr2 = new int[arr1[1] - arr1[0]];
    for (int i = arr1[0], ind1 = 0; i < arr1[1]; i++, ind1++)
    {
        arr2[ind1] = arr[i];
    }
    int arr_size1 = arr1[1] - arr1[0];
    mergeSort(arr2, 0, arr_size1 - 1);
    for (int i = arr1[0], ind1 = 0; i < arr1[1]; i++, ind1++)
    {
        arr[i] = arr2[ind1];
    }
    pthread_exit(NULL);
}

void merge(int low, int mid, int high)
{
    int *left = new int[mid - low + 1];
    int *right = new int[high - mid];
    int n1 = mid - low + 1, n2 = high - mid, i, j;
    for (i = 0; i < n1; i++)
    {
        left[i] = arr[i + low];
    }
    for (i = 0; i < n2; i++)
    {
        right[i] = arr[i + mid + 1];
    }
    int k = low;
    i = j = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {   
            arr[k++] = right[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}

int main()
{
    srand(time(NULL));
    int size = 0, cores = 4;
    cout << "Number of cores: " << cores << endl;
    cout << "LAN1 MAC: bc:e9:2f:fc:5c:ef" << endl;
    cout << "LAN2 MAC: f8:ac:65:d1:03:99" << endl;
    cout << "WIFI MAC: 08:C0:21:1E:27:F4" << endl << endl;
    cout << "Enter size of array: ";
    cin >> size;
    cout<<endl;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value for index " << i + 1  << " : ";
        cin >> arr[i];
    }
    cout<<endl;
    printarr(arr, size);
    cout << endl;
    pthread_t tid[cores];
    if (size % cores == 0)
    {
        cout << "The array is divided into chunks of: " << ((size / cores)) << endl;
        int ind[2] = {0, size / cores};
        for (int i = 0; i < cores; i++)
        {
            pthread_create(&tid[i], NULL, sortarr, (void *)ind);
            pthread_join(tid[i], NULL);

            ind[0] += size / cores;
            ind[1] += size / cores;
        }
    }
    else
    {
        int ind[2] = {0, (size / cores) + 1};

        for (int i = 0; i < cores - 1; i++)
        {
            pthread_create(&tid[i], NULL, sortarr, (void *)ind);
            pthread_join(tid[i], NULL);

            ind[0] += (size / cores) + 1;
            ind[1] += (size / cores) + 1;
            if (ind[0] >= highestfactor(size, cores) || ind[1] > (highestfactor(size, cores) + 1))
            {
                break;
            }
        }

        ind[0] = highestfactor(size, cores) + 1;
        ind[1] = size;

        pthread_create(&tid[cores - 1], NULL, sortarr, (void *)ind);
        pthread_join(tid[cores - 1], NULL);
    }
    printarr(arr, size);
}