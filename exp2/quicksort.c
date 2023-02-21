#include <stdio.h>
#include<stdlib.h>
#include<time.h>


void quicksort(int number[],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
         i++;
         while(number[j]>number[pivot])
         j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
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
    quicksort(data,0,size-1);
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
