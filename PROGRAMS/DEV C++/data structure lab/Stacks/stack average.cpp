#include <iostream>
using namespace std;
#define STACKSIZE 4
struct stack
{
  int top;
  int items[STACKSIZE];
};

void initializeStack(struct stack *);
int isStackFull(struct stack *);
void push(struct stack *, int);
int isStackEmty(struct stack *);
int pop(struct stack *);
void printStack(struct stack *);
void average(struct stack *, struct stack *, struct stack *);

int main(void)
{
	struct stack s1,s2,s3;
	initializeStack (&s1);
	initializeStack (&s2);
	initializeStack (&s3);
	push(&s1,20);
	push(&s1,5);
	push(&s1,15);
	push(&s1,10);
	push(&s2,5);
	push(&s2,2);
	push(&s2,7);
	push(&s2,6);
	cout<<"Stack1 elements:\n";
    printStack(&s1);
    
   	cout<<"Stack2 elements:\n";
    printStack(&s2);
    
    average(&s1, &s2, &s3);
    
   	cout<<"average of elements in the 2 stacks are:\n";
    printStack(&s3);
        
    system("PAUSE");
    return 0;
}

void average(struct stack *ps1, struct stack *ps2, struct stack *ps3)
{
     int x;
     struct stack temp;
     initializeStack(&temp);
     
     while (!isStackEmty(ps1) && !isStackEmty(ps2))
     {
       x = (pop(ps1)+pop(ps2))/2;
       push(&temp,x);
       
     }
     while (!isStackEmty(&temp))
     {
            x = pop(&temp);      
            push(ps3,x);
     }
}

void printStack(struct stack *ps)
{
     int x;
     struct stack temp;
     initializeStack(&temp);
     
     while (!isStackEmty(ps))
     {
       x = pop(ps);
       cout<<x<<endl;
       push(&temp,x);
     }
     while (!isStackEmty(&temp))
     {
            x = pop(&temp);
            push(ps,x);
     }
}

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

