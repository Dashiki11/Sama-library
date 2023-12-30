#include<iostream>

using namespace std;

void printarray(int arr[])
{
	for(int i=0;i<16;i++)
	   cout<<arr[i]<<" ";
	   
	   cout<<endl;
}

void bubble_sort(int list[],int size)
 { 
	int temp;
	int i,j;
	for (i = 1; i<size; i++)             // i indicates the pass number 
        {
              for (j =0; j<size - i; j++)
              {                                                                  
                      if (list [ j ] > list [ j+1 ] ) // swap must be made
                      {                          
                             temp =list [j+1];
                             list [j+1]= list [j];
                             list [j]= temp;
                      }          
               }
        }
 }

int main()  
{
	int arr[]= {3 , 6 , 23 , 15 , 12 , 8 , 55 , 43 , 57 , 90 , 13 , 4 , 25 , 72 , 1 , 21} ;
	
	printarray(arr);
	
	bubble_sort(arr,16);
	
		printarray(arr);
	
}

