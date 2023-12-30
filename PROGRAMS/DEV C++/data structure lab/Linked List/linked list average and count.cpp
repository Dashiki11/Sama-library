#include <iostream>
#include <cstdlib>
using namespace std;
struct node{
	int data;
struct node *next;
};

int is_empty( struct node *header)
{
	if(header==NULL)
		return 1; //TRUE
else 
return 0; //FALSE
}

struct node * newnode(double d)
{
	struct node *temp;
	temp=(struct node *) malloc(sizeof(node));
	temp->data =d;
	temp->next=NULL;
return temp;
}

struct node * insertFront(struct node *header, int d)
{
	struct node *temp;
	temp=newnode(d);
	temp->next =header;
header=temp;
return header;
}


struct node * insertBack(struct node *header, int d)
{
	struct node *temp, *headertemp;
	temp=newnode(d);
if(header==NULL)
{
header=temp;
return header;
		}
		headertemp=header;
		while(headertemp->next!=NULL)
headertemp =headertemp->next;
headertemp->next=temp;
		return header;
}

void insertAfter(struct node *afterNode, int d)
{
	struct node *temp;
	temp=newnode(d);
		temp->next=afterNode->next;
		afterNode->next=temp;
}

struct node * deleteFront(struct node *header)
{
	struct node *temp;
if(header==NULL)
	return header;
temp=header;
	header= header->next;
free(temp);
return header;
}

struct node * deleteBack(struct node *header)
{
	struct node *temp, *headertemp;
if(header==NULL)
return header;
		headertemp=header;
		while(headertemp->next->next!=NULL)
headertemp =headertemp->next;
		temp=headertemp->next;
headertemp->next=NULL;
free(temp);
		return header;
}

void deleteAfter(struct node *afterNode)
{
	struct node *temp;
	if(afterNode->next==NULL || afterNode==NULL)
		return;
		temp =afterNode->next;
		afterNode->next=temp->next;
		free(temp);
}

void DisplayList(struct node *header)
{       
    struct node *temp = header;
    
    if (header == NULL)
        cout << "List is empty" << endl;

    while (temp != NULL)
    {
        cout << " --> "<< temp->data<<"\t"; 
        temp=temp->next;
    }
    cout << endl<<endl;
}

float averagelist (struct node *header)
{
	struct node *temp = header;
	double s = 0.0;
	double a;
	int count = 0;
    
    if (header == NULL)
        cout << "List is empty" << endl;

    while (temp != NULL)
    { 
        s = s + temp->data;
        temp=temp->next;
        count++;
    }
    
    a= s/count;
    cout <<"average of linked list:"<<a <<endl;
}

int countA (struct node *header)
{       
    struct node *temp = header;
    int count = 0;
    char d;
    
    if (header == NULL)
        cout << "List is empty" << endl;

    while (temp != NULL)
    {
        if( temp->data == 'A')
		     count++;
		   temp=temp->next;
    }
    
    cout<<"there are "<<count<<" A's in the list"<<endl;
    cout << endl;
}

int main(void)
{
	struct node *header = NULL;
	
  /*header = insertBack(header,2);
  header = insertBack(header,4);
  header = insertBack(header,6);
  DisplayList(header);
  header = insertFront(header,1);
  DisplayList(header);
  insertAfter(header->next->next,5);
  DisplayList(header);
  header = deleteFront(header);
  DisplayList(header);
  header = deleteBack(header);
  DisplayList(header);
  deleteAfter(header->next);
  DisplayList(header);*/
  header = insertBack(header,1.5);
  header = insertBack(header,2.5);
  header = insertBack(header,3.5);
  header = insertBack(header,4.5);
  DisplayList(header);
  averagelist (header);
  /*header = insertBack(header,'A');
  header = insertBack(header,'B');
  header = insertBack(header,'A');
  header = insertBack(header,'C');
  header = insertBack(header,'D');
  DisplayList(header);
  countA (header); */
  

  return 0;	
}

