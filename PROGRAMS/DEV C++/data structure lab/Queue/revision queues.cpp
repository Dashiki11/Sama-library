#include <iostream>
using namespace std;
#define SZ 150
#define STACKSIZE 150

struct queue{
	int f;
	int r;
	int items[SZ];
};

void initQueue(struct queue *pq)
{
		pq->f = pq->r = SZ - 1;
}

int isFull(struct queue *pq)
{
	if(pq->f == pq->r)
		return 1;
	else
		return 0;
}

int isEmpty(struct queue *pq)
{
 	if(pq->r == pq->f)
		return 1;
	else
		return 0;
}

void insert(struct queue *pq, int x)
{
	if(pq->r== SZ-1)
		pq->r = 0;
	else
		(pq->r)++;
	if(pq->r == pq->f)
      {		
	    cout<<"Overflow: Queue is full"<<endl;
	    exit(1);
	  }
	else
	   pq->items[pq->r]=x;
}

int remove(struct queue *pq)
{
	if(isEmpty(pq))
	{
		cout<<"Underflow: Queue is empty"<<endl;
		exit(1);
	}
    else
       {
	    if(pq->f == SZ-1)
		   pq->f=0;
	    else
		   (pq->f)++;
		return pq->items[(pq->f)];
       }
}

void printqueue(struct queue *pq)
{
	int x;
	struct queue temp;
	initQueue(&temp);

	while(!isEmpty(pq))
	{
		x= remove(pq);
		cout<<x<<endl;
		insert(&temp, x);
	}
	while(!isEmpty(&temp))
	{
		x= remove(&temp);
		insert(pq, x);
	}
}

void copyqueue(struct queue *pq, struct queue *pq2)
{
	int x;
	struct queue temp;
	initQueue(&temp);

	while(!isEmpty(pq))
	{
		x= remove(pq);
		insert(&temp, x);
	}
	while(!isEmpty(&temp))
	{
		x= remove(&temp);
		insert(pq, x);
		insert(pq2,x);
	}
}

void modifyqueue(struct queue *pq, struct queue *pq2)
{
	int x,y;
	struct queue temp;
	initQueue(&temp);

	while(!isEmpty(pq))
	{
		x= remove(pq);
		insert(&temp, x);
	}
	while(!isEmpty(&temp))
	{
		x= remove(&temp);
		if(x >= 5)
		{
			y= 1;
		   insert(pq, x);
		   insert(pq2,y);
		}
		else
		{
		    y = 0;
		   insert(pq, x);
		   insert(pq2,y);
		}
	}
}

struct stack
{
  int top;
  int items[STACKSIZE];
};

void initializeStack(struct stack *ps)
{  ps->top = - 1; }

int isStackFull(struct stack *ps)
{
   if(ps->top == STACKSIZE-1) 
     return 1; 
   else 
     return 0; 
}

void push(struct stack *ps, int x)
{
   if(isStackFull(ps))		
   {
     cout<<"Overflow: Stack is full\n";
     exit(1);
   }
   ps->top++;
   ps->items[ps->top]=x;
}

int isStackEmty(struct stack *ps)
{
   if(ps->top == -1)
     return 1; 
   else
     return 0; 
}

int pop(struct stack *ps)
{
	if(isStackEmty(ps)==1)	
	{
		cout<<"Underflow: Stack is empty\n";
		exit(1);
	}
	return ps->items[(ps->top)--];
}



void reversequeue(struct queue *pq, struct queue *pq2)
{
	int x,y;
	struct queue temp;
	initQueue(&temp);
	struct stack temp2;
	initializeStack(&temp2);

	while(!isEmpty(pq))
	{
		x= remove(pq);
		insert(&temp, x);
		push(&temp2,x);
	}
	while(!isEmpty(&temp) && !isStackEmty(&temp2))
	{
		x= remove(&temp);
		insert(pq, x);
		y = pop(&temp2);
		insert(pq2,y);
	}
}


int main(void)
{
	struct queue pq;
	struct queue pq2, pq3;
	initQueue(&pq);
	initQueue(&pq2);
	initQueue(&pq3);
	insert(&pq,4);
	insert(&pq,5);
	insert(&pq,10);
	insert(&pq,15);
	cout<<"list of elements: "<<endl;
    printqueue(&pq);
    cout<<"In reverse order: "<<endl;
    reversequeue(&pq,&pq2);
    printqueue(&pq2);
    modifyqueue(&pq,&pq3);
    cout<<"After modification: "<<endl;
    printqueue(&pq3);

	system("PAUSE");
	return 0;
}
