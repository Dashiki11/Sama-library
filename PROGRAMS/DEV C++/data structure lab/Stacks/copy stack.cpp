#include <iostream>
using namespace std;
#define STACKSIZE 4
struct stack
{
  int top;
  int items[STACKSIZE];
};

//if your funtions in the Program are in disorder, initialize it like this for it to work.
/*void initializeStack(struct stack *);
int isStackFull(struct stack *);
void push(struct stack *, int);
int isStackEmty(struct stack *);
int pop(struct stack *);
void printStack(struct stack *);
void copyStack(struct stack *, struct stack *);*/


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

void copyStack(struct stack *ps1, struct stack *ps2)
{
     int x;
     struct stack temp;
     initializeStack(&temp);
     
     while (!isStackEmty(ps1))
     {
       x = pop(ps1);
       push(&temp,x);
     }
     while (!isStackEmty(&temp))
     {
            x = pop(&temp);
            push(ps1,x);
            push(ps2,x);
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

int main(void)
{
	struct stack s1,s2;
	initializeStack (&s1);
	initializeStack (&s2);
	push(&s1,2);
	push(&s1,5);
	push(&s1,4);
	push(&s1,3);
	cout<<"Stack1 elements before copying are:\n";
    printStack(&s1);
    
   	cout<<"Stack2 elements before copying are:\n";
    printStack(&s2);
    
    copyStack(&s1, &s2);
    
   	cout<<"Stack1 elements after copying are:\n";
    printStack(&s1);
 
   	cout<<"Stack2 elements after copying are:\n";
    printStack(&s2);
        
    system("PAUSE");
    return 0;
}

