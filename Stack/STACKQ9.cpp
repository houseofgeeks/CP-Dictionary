#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
char stack[MAX];
float stk[MAX];
int top=-1;
void push(char x);
char pop();
int pr(char x);
int Vcheck(char Ex[]);

int main()
{
	int f=0,i,count=0,k,j=0;
	char exp[50],op,ch,post[50];
	float temp,op1,op2;
	printf("\nEnter the expression : ");
	gets(exp);
	if (Vcheck(exp))
	       {
		printf("\n Valid");
		f=1;
		}
	else
		printf("\n Invalid");

		      if (f==1)
		      {
			for(i=0;exp[i]!='\0';i++)
			{
				ch=exp[i];
				if(isalpha(ch))
					post[j++]=ch;
				else if (ch=='(')
					stack[++top]=ch;
				else if (ch==')')
				{
					while (stack[top]!='(')
					post[j++]=stack[top--];
					top--;
				}

				else
				{
					for(k=top;(k>-1 && stack[k]!='(' && pr(ch)<=pr(stack[k]));k--)
					{
						post[j++]=stack[top--];
				}
					stack[++top]=ch;
				}
			}
		while(top>-1)
		post[j++]=stack[top--];
		post[j]='\0';
		printf("\nPostfix string is:\n");
		puts(post);
		//evaluation
		top=-1;
		for(i=0;post[i]!='\0';i++)
		{
			ch=post[i];
			if(isalpha(ch))
			{
				printf("\nRead value of %c ",ch);
				scanf("%f",&temp);
				stk[++top]=temp;
			}
			else
			{
				op1=stk[top--];
				op2=stk[top--];
				switch(ch)
				{
					case '+':
						stk[++top]=op2+op1;
						break;
					case '-':
						stk[++top]=op2-op1;
						break;
					case '*':
						stk[++top]=op2*op1;
						break;
					case '/':
						stk[++top]=op2/op1;
						break;
				}
			}
		}
		printf("\n Evaluation of postfix exp is: %f",stk[top--]);
	return 0;}
}
int pr(char x)
{
	if(x=='^')
	return 9;
	else if(x=='*' || x=='/')
	return 7;
	else if(x=='+' || x=='-')
	return 5;
}
void push(char x)
{
	if(top<MAX-1)
	{
	top++;
	stack[top]=x;
	}
	else
	printf("\nStack Overflow");
}
char pop()
{
	char x;
	if(top==(-1))
	{
		printf("\nStack Underflow");
	       //	x=-9;
	}
	else
	{
		x=stack[top];
		top--;
	}
	return x;
}

//void main()
//{}

int Vcheck(char Ex[])
{
	int i,orr=0, op=0;
	char ch;

	for(i=0;Ex[i]!='\0';i++)
	{
      ch=Ex[i];
	  if (isalpha(ch))
	  orr++;
	  else
	  op++;
	  if (orr<op || orr>(op+1))
	  break;
	}
	if (orr==(op+1) && Ex[i]=='\0')
		return (1);
	else
		return (0);
}
