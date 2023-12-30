#include <iostream>
using namespace std;


struct node
{
	char data;
	struct node *next;
};

struct node *createnode(char v)
{
	struct node *t;
	t = new node;
	t -> data = v;
	t -> next = NULL;
	
	return t;
}

int Print(struct node *h)
{
	struct node *t;
	
	while(t -> next != NULL)
	{
		cout<<t -> data;
		t = t-> next;
	}
	cout<<t -> data;
}

void DisplayList(struct node *h) 
{
       if (h == NULL)
           cout << "List is empty" << endl;

       struct node *t = h;

      while (t !=NULL)
      {
         cout <<t ->data<<" -->";  
   		 t = t->next ;
    	}
         cout << endl ;
	
}

int sizeLL(struct node *h)
{
	int count = 0;
	if (h == NULL)
           cout << "List is empty" << endl;

       struct node *t = h;

      while (t !=NULL)
      {
      	 t = t->next ;
         count++;
    	}
         
         return count;
}

int CountA(struct node *h)
{
	
      int count = 0;
	if (h == NULL)
           cout << "List is empty" << endl;

       struct node *t = h;

      while (t !=NULL)
      {
      	if(t->data == 'A')
      	{
      	 count++;
        }
      	 t = t->next ;   
      }
         
         return count;
}

int main()
{
	struct node *h,*t, *n;
	h = createnode('A');
	t = h;
	
	n = createnode('B');
	t -> next = n;
	t = n;
	
		
	n = createnode('A');
	t -> next = n;
	t = n;
	
		
	n = createnode('C');
	t -> next = n;
	t = n;
	
	n = createnode('D');
	t -> next = n;
	t = n;
	
	DisplayList(h);
	cout<<"count = "<<sizeLL(h)<<endl;
	cout<<"number of A's = "<<CountA(h);
}




