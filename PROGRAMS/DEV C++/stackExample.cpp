#include<iostream>
#define  STACKSIZE 10

using namespace std;
struct stack{
	int items[50];
	int  top;
	};

void initStack(struct stack *ps)
{
		ps->top = - 1;
}

void top_of_the_stack (struct stack *ps);
void printstack (struct stack * ps);

int  is_empty(struct stack *ps)
{
		if(ps->top == -1)
			return 1; //stack is empty
		else
			return 0; //stack is not empty
}

int  is_full(struct stack *ps)
{
		if(ps->top == STACKSIZE-1)
			return 1; //stack is full
		else
			return 0; //stack is not full
}


void push(struct stack *ps, int x)
{
	if(is_full(ps))		//if(is_full(&(*ps))) 	//if (ps->top==STACKSIZE -1)
	{
		cout<<"Overflow: Stack is full"<<endl;
		exit(1);
	}

ps->top++;
ps->items[ps->top]=x;

}


int pop(struct stack *ps)
{
	if(is_empty(ps)==1)	//if(ps->top==-1)
	{
		cout<<"Underflow: Stack is empty"<<endl;
		exit(1);
	}
	return ps->items[(ps->top)--];
}



int main()
{
	
	stack s;
	initStack(&s);
	/*
	if( is_empty(&s))
		cout<<"Satck is empty";
	else
		cout<<"Stack is not empty";
*/

push(&s,20);
push(&s,10);

printstack(&s);
top_of_the_stack(&s);
cout<<pop(&s)<<" Deleted\n";

printstack(&s);

}


void top_of_the_stack (struct stack *ps)
{
	
		if( is_empty(ps))
		cout<<"Satck is empty";
	else
		cout<<ps->items[ps->top]<<endl;
	
}


void printstack (struct stack * ps)
{
	
		if( is_empty(ps))
		cout<<"Satck is empty"<<endl;
	else
	{
		
		for (int i = ps->top; i>=0;i--)
		{
			cout<<ps->items[i]<<endl;
			
		}
			
	}
		
		
}
