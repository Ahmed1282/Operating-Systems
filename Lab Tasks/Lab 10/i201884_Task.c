#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


 int x;
 int y;
 int array[10];
 pthread_t td1 , td2, td3;
 

void *input(void *arg)
{
   
    printf("Enter the first number: ");
    scanf("%d",&x);
    printf("Enter the second number: ");
    scanf("%d",&y);
    pthread_exit(NULL);

}


void *prompt(void *arg)
{
 
 int join1 = pthread_join(td1,NULL);
for (int i=0; i<10; i++)

{ srand(time(0));
 sleep(1);
 array[i] = (rand()%(y-x+1)+x);
}

for (int i=0; i<10; i++)

{ 
  printf("%d \n", array[i]);
}

 pthread_exit(NULL);

}










void *function3(void *arg)
{
 
int join2 = pthread_join(td2,NULL);
int size = sizeof(array) / sizeof(array[0]);
	mergeSort(array, 0, size - 1);
	printf("AFTER SORT\n");
	for (int i = 0; i < 10; i++) {
		printf("%d\n", array[i]);
	}
    int sum = 0;
	for (int x = 0; x < 10; x++) {
		sum = sum + array[x];
	}
	printf("The sum is = %d\n", sum);
	pthread_exit(0);
		 


}




void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}











int main(){

        pthread_create (& td1 , NULL, input , NULL);
        pthread_create (& td2 , NULL, prompt , NULL);
        pthread_create (& td3 , NULL, function3 , NULL);
        int join3 = pthread_join(td3,NULL);
        

return 0;

}
