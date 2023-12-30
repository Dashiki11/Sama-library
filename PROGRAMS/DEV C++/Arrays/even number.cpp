#include <iostream>
using namespace std;
/*21912456*/
int main()
 {
 	int array[10]= {20,7,18,2,10,3,8,11,6,9};

    cout<<"the even number are: ";
 	for(int i=0;i<10; i++)
 	{
 	    if(array[i] % 2 == 0)
 	    {
 	       cout<< array[i]<<" ";
 	    }
	 }

	return 0;
}
