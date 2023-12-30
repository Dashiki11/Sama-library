#include <iostream>
#include <conio.h>

#define STACKSIZE 50

using namespace std;
struct stack
{
	int itmes[STACKSIZE];
	int top;
};

void initStack(struct stack *sp)
{
	sp->top= -1;
}

int is_empty(struct stack *sp)
{
	if(sp->top==-1)
	   return 1;
	else
	   return 0;
	
}

int is_full(struct stack *sp)
{
	if (sp->top==STACKSIZE-1)
	   return 1;
	else
	  return 0;
}


void push(struct stack *sp,int x)
{
	
	if(!is_full(sp))
	{
		   sp->top++;
		   sp->itmes[sp->top]=x;
		
	}else
	{
		cout<<"Stack if full\n";
	}
	
	   
}

int pop(struct stack *sp)
{
	
	if(is_empty(sp))
	{
		cout<<"Stack is empty";
		exit(1);
	}
	else{
		return sp->itmes[(sp->top)--];
	}
}

//Task 1 Print top of stack
void top_of_the_stack (struct stack *sp)
{
	if(!is_empty(sp))
		cout<<"Top of Stack " <<sp->itmes[sp->top]<<endl;
	else
	{
		cout<<"\nStack is empty\n";
		
	}
}

//Task 2 Print all stack

void printstack (struct stack *sp)
{
	//Create temprary stack
	stack tmp;
	//Initiate tmp stack
	initStack(&tmp);
	cout<<"--START PRINT STACK--"<<endl;
	
	while(!is_empty(sp))
	{
		int x = pop(sp);
		
		cout<<x<<endl;
		push(&tmp,x);
		
	}
	
	//Send items back to old stack;
	
	while(!is_empty(&tmp))
	{
		push(sp,pop(&tmp));
	}
	
	
}

int main()
{
	stack s;
	initStack(&s);

	char equation[50],temp;
	int i=0,valid=1;

cout<<"Please enter the equation:";
	gets (equation);
	getch();

	while (equation[i]!='\0')
	{
		if (equation[i]=='(' || equation[i]=='[' || equation[i]=='{')
			push(&s,equation[i]);
		if(equation[i]==')' || equation[i]==']' || equation[i]=='}')
		{
			if(is_empty(&s)==1)
				valid = 0;
			char temp = pop(&s);

			if( equation[i]==')' && temp!='(')
				valid = 0;
			if( equation[i]==']' && temp!='[')
				valid = 0;
			if( equation[i]=='}' && temp!='{')
				valid = 0;
		}

		++i;
	}

    if(is_empty(&s)==0)
		valid = 0;


	if(valid==1)
		cout<<"\nEquation is correct!";
	else
		cout<<"\nEquation is INcorrect!";

	
}



