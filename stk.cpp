#include <stdio.h>
#include <iostream>
#include <cstring>
#include<stack>

using namespace std;

struct Stack{
	int top=-1;
	int capacity;
	int *array;
};

struct Stack* createStack(int cap)
{
	struct Stack* stk=(struct Stack*) malloc(sizeof(struct Stack));
	stk->top=-1;
	stk->capacity=cap;
	stk->array=(int*)malloc(cap*sizeof(int));
	return stk;
}

int isFull(struct Stack* _stack)
{
	return _stack->top==_stack->capacity-1;
}

int isEmpty(struct Stack* _stack)
{
	return _stack->top==-1;
}

void push(struct Stack* _stack,int item)
{
	if(isFull(_stack)) return;
	_stack->array[++_stack->top]=item;
}

int pop(struct Stack* _stack)
{
	return _stack->array[_stack->top--];
}

int peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

void reverse(char str[])
{
	struct Stack* stk = createStack(20);
	int n = strlen(str);
	for(int i=0;i<strlen(str);i++)
	{
		push(stk,str[i]);
	}
	for(int j=0;j<strlen(str);j++)
	{
		str[j]=pop(stk);
	}
}

void findNextGrt(int array[],int n)
{
	struct Stack* _stk = createStack(20);
	push(_stk,array[0]);
	for(int i=1;i<n;i++)
	{
		int next=array[i];
		if(!isEmpty(_stk))
		{
			int element=pop(_stk);
			while(element<next)
			{
				cout<<"Element is "<<element<<"::NEXT GRT IS::"<<next<<endl;
				if(isEmpty(_stk))break;
				element=pop(_stk);
			}
			if(element>next)
			{
				push(_stk,element);
			}
			push(_stk,next);
		}
	}
	while(!isEmpty(_stk))
	{
		int final=pop(_stk);
		int next=-1;
		cout<<"Element is "<<final<<"::NEXT GRT IS::"<<next<<endl;
	}
}

void reverseStack(struct Stack* dep)
{
	if(!isEmpty(dep))
	{
		int item = pop(dep);
		reverseStack(dep);
		push(dep,item);
	}
}

void printStack(struct Stack* depe)
{
	while(!isEmpty(depe))
	{
		cout<<peek(depe)<<endl;
		pop(depe);
	}
}

void realSorting(struct Stack* depo,int item)
{
	if(isEmpty(depo)|| (item>peek(depo)))
	{
		push(depo,item);
		return;
	}

	int item2=pop(depo);
	realSorting(depo,item);

	push(depo,item2);
}

void sortStack(struct Stack* deep)
{
	if(!isEmpty(deep))
	{
		int item=pop(deep);
		sortStack(deep);
		realSorting(deep,item);
	}
}

createSpan(int price[],int n,int span[])
{
	span[0]=1;
	struct Stack* stk = createStack(20);
	push(stk,0);
	for(int i=0;i<n;i++)
	{
		while(!isEmpty(stk) && price[peek(stk)]<=price[i])
		{
			pop(stk);
		}
		span[i]=(isEmpty(stk))?(i+1):(i-peek(stk));
		push(stk,i);
	}
		
}

void towerOfHanoi(int n,char sou,char des,char aux)
{
	if(n==0){
		return;
	}
	towerOfHanoi(n-1,sou,aux,des);
	cout<<"Move from disk::"<<n<<":: from tower ::"<<sou<<":: to tower ::"<<des<<endl;
	towerOfHanoi(n-1,aux,des,sou);
}

void maxHistogramArea(int hist[], int n)
{
	stack<int> s;
	int max_area=0;
	int tp;
	int area_with_top;
	int i=0;
	while(i<n)
	{
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);
		else
		{
			tp=s.top();
			s.pop();
			area_with_top=hist[tp]*(s.empty() ? i : (i - s.top() - 1));
			if (max_area < area_with_top)
                max_area = area_with_top;
		}
	}
	while(s.empty()==false)
	{
		tp=s.top();
		s.pop();
		area_with_top=hist[tp]*(s.empty() ? i : (i - s.top() - 1));
		if (max_area < area_with_top)
			max_area = area_with_top;
	}
	cout<<"MAX AREA IS ::"<<max_area<<endl;
}

int main()
{
	struct Stack* deep = createStack(100);
	push(deep,10);
	push(deep,230);
	push(deep,40);
	push(deep,180);	
//	pop(deep);
	cout<<peek(deep)<<endl;
	
	char abc[]="Deepesh";
	reverse(abc);
	cout<<"Deepesh reversed is - "<<abc<<endl;
	int prob[]={11,5,13,2,89,3};
	int n = sizeof(prob)/sizeof(prob[0]);
	findNextGrt(prob,n);
	cout<<"----------------------REVERSE STACK---------"<<endl;
	reverseStack(deep);
	sortStack(deep);
	cout<<"Sorted Stack::"<<endl;
	
	printStack(deep);
	int price[]={100, 80, 60, 70, 60, 75, 85};
	
	int n1 = sizeof(price)/sizeof(price[0]);
	int span[n1];
	createSpan(price,n1,span);
	cout<<"N1::"<<n1<<endl;
	for(int i=0;i<n1;i++)
	{
		cout<<"SPAN::::"<<span[i]<<endl;
	}
	towerOfHanoi(4,'S','D','A');
	int hist[] = {6, 2, 5, 4, 5, 1, 6};
    	int n2 = sizeof(hist)/sizeof(hist[0]);
	maxHistogramArea(hist,n2);
	return 0;
}
