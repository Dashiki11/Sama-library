# include <iostream>
using namespace std;

int max(int a, int b)
{
	if (a>b)
    {
    	return a;
	}				  	   
    else if(a<b)
 	{
 		 return b;
	}  
 	   
	else 
	   cout<<"the numbers are equal";				   
	   
}

int main(void)
{
	int a,b;
	cout<<"Enter 2 numbers: ";
	cin>>a>>b;
	cout<<"the Max number is  "<<max(a,b);
	
	return 0;
}
