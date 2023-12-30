#include <iostream>
#define QUEUE_SIZE 150
using namespace std;

struct LinearQueue
{
    int front;
    int rear;
    int items[QUEUE_SIZE];
};

void initializeQueue(struct LinearQueue *);
void copyQueue (struct LinearQueue *,struct LinearQueue *);
int isQueuefull(struct LinearQueue *);
void insert(struct LinearQueue *, int);
int isQueueEmpty(struct LinearQueue *);
int remove(struct LinearQueue *);
void printQueue (struct LinearQueue *);

int main()
{
    struct LinearQueue lq, q2;
	initializeQueue(&lq);
	initializeQueue(&q2);
	insert(&lq,8);
	insert(&lq,7);
    insert(&lq,6);
    insert(&lq,5);
   	insert(&lq,4);

    cout<<"QUEUE1 elements befort copying are: \n"; 
    printQueue (&lq);  
	
	cout<<"QUEUE2 elements before copying are: \n"; 
	printQueue (&q2);
	 
	copyQueue (&lq, &q2);
	 
	cout<<"QUEUE1l elements after copying are: \n";
    printQueue (&lq);
    
    cout<<"QUEUE2 elements after copying are:\n"; 
	printQueue(&q2);

    
    system("PAUSE");
    return 0;
}

void initializeQueue(struct LinearQueue *l)
{
    l->front = 0; l->rear = -1;
}
int isQueueEmpty(struct LinearQueue *l)
{
    if (l->rear < l->front) return 1;
    else return 0;
}

int remove(struct LinearQueue *l)
{
    int x;
    if (isQueueEmpty(l))
	{   cout<<"Underflow: Queue is empty"<<endl; 
        exit(1);
    }
	else
	{
        x = l->items[l->front++];
        return x;
    }
}

int isQueuefull(struct LinearQueue *l)
{
    if (l->rear == QUEUE_SIZE - 1) return 1;
    else return 0;
}

void insert(struct LinearQueue *l, int x)
{
    if (isQueuefull(l))
    {
       cout<<"Overflow: Queue is full"<<endl;
       exit(1);
    }
    else
   	   l->items[++l->rear]=x;
}

void copyQueue (struct LinearQueue *l,struct LinearQueue *q2)

{

  int x;
  struct LinearQueue temp;
  initializeQueue (&temp);
  while (!isQueueEmpty (l))
{
   x = remove (l); 
   insert(&temp,x);
}
   while (!isQueueEmpty (&temp))
{
    x = remove(&temp); 
	insert(l,x);
	insert(q2,x);
}

}
void printQueue (struct LinearQueue *l)
{
  int x;
  struct LinearQueue temp;
  initializeQueue (&temp); 
  while (!isQueueEmpty(l))
  {
    x = remove (l); 
    cout<<x<<endl; 
    insert(&temp,x);
  }
  while (!isQueueEmpty(&temp))
  {
    x = remove(&temp);
    insert (l,x);
  }
}
