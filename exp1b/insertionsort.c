#include <math.h>
#include <stdio.h>
#include<time.h>
 
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
       
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
/*void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}*/

int main()
{
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
     insertionSort(data,size);
     if(block<3)  //this prints sorted first 2 blocks only
     {
       printf("\n\nafter sorting block %d:\n",block);
        for(int i=0;i<size;i++)
        {
          printf("%d \n",data[i]);
        }
     }
       
   
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nRuntime for block number %d : %f\n",block,time_taken);
   
    size=size+100;
    block++;
    fseek(ptr,0,SEEK_SET); //moving cursor again to start pointer of txt file
       
    }
   
     fclose(ptr);
       


}
