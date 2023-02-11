#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[],int n)
{
   
    for(int i=0;i<n-1;i++)
    {  
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
       
        swap(&arr[minIndex],&arr[i]);
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
     selectionSort(data,size);
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
