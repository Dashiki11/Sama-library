#include<iostream>

using namespace std;

void printarray(int arr[])
{
	for(int i=0;i<16;i++)
	   cout<<arr[i]<<" ";
	   
	   cout<<endl;
}

void selectionSort(int a[], int size)
{
  int i, j, min, temp;

  for (i = 0; i < size - 1; i++)
  {
    min = i;
    for (j = i+1; j < size; j++)
      if (a[j] < a[min]) 
      
         min = j;
         
	     int temp = a[i] ;  //or you substitute this 3 lines with 
         a[i] = a[min];     //     swap(a[i], a[min]);
         a[min] = temp;     //

  }
}


int main()  
{
	int arr[]= {3 , 6 , 23 , 15 , 12 , 8 , 55 , 43 , 57 , 90 , 13 , 4 , 25 , 72 , 1 , 21} ;
	
	printarray(arr);
	
	selectionSort(arr,16);
	
		printarray(arr);
	
}



