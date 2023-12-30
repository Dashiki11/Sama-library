#include <iostream>
using namespace std;
 /*21912456*/
int main()
 {
 	int array[10], sum= 0; float avg;
 	for(int i=0;i<10; i++)
 	{
 		cout<<"Enter value"<<(i+1)<<";";
        cin>>array[i];
        sum += array[i];
	 }
	 avg = sum/10.0 ;
	 cout<<"average="<<avg;
	return 0;
}
