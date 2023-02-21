#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int main()
{  
   //to generate 1000000 random numbers
    /*int numbers[100000];
    for(int i=0;i<100000;i++)
    {
       
         numbers[i]=rand()%100000;
         printf("%d \n",numbers[i]);      
    }*/
   
   FILE* ptr;
 
    // file in reading mode
    ptr = fopen("input.txt", "r");
 
    if (NULL == ptr)
    {
        printf("file can't be opened \n");
    }
   
    int block=1;
    int size=100;
    while(block<=1000)
    {
      int data[size];
      for(int i=0;i<size;i++)
     {
        fscanf(ptr,"%d ",&data[i]);
        //printf("%d ",data[i]);
     }
     
     clock_t t;
     t = clock();
     mergeSort(data,0,size-1);
    /* if(block<3)  //this prints sorted first 2 blocks only
     {
       printf("\n\nafter sorting block %d:\n",block);
        for(int i=0;i<size;i++)
        {
          printf("%d \n",data[i]);
        }
     }*/
       
   
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n%f",time_taken);
   
    size=size+100;
    block++;
    fseek(ptr,0,SEEK_SET); //moving cursor again to start pointer of txt file
       
    }
   
    // fclose(ptr);
       
}
