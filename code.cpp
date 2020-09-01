//  just like conversion of infix to postfix
//  in this we have to reverse the string and make the postfix of that
//   rembering one thing
//    ****in postfix the operator of same precedence will pop
    // but here the same precedence operater are pushed in stack
#include<iostream>
#include<string>
using namespace std;
class stack{
public:
	char data;
	stack *next;
	stack(char data)
	{
		this->data=data;
		this->next=NULL;
	}
};
stack *final=NULL;
stack *top1=NULL;
int order(char S)// this function is used for checking preceding order of a operator 
{
	if(S=='^')
	{
		return 3;
	}
	else if(S=='*' || S=='/')
	{
		return 2;
	}
	else if(S=='+' || S=='-')
	{
		return 1;
	}
	return -1;
}
stack* push(stack *head,char data)
{
	stack *top;
	top=head;
	if(top==NULL)
	{
		top=new stack(data);
	}
	else
	{
		stack *temp=top;
		top=new stack(data);
		top->next=temp;
	}
	return top;
}
stack* pop(stack *top)
{
	top->data;
	top=top->next;
	return top;
}
int main()
{
	string s;
	cout<<"ENTER YOUR EXPRESSION:-";
	cin>>s;
	cout<<"PREFIX EXPRESSION:-\n";
	final=push(final,')');
	top1=push(top1,')');
	int i;
	for(i=s.length()-1;i>=0;i--)//  reverse 
	{
		if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' )// checking operand
		{
			final=push(final,s[i]);// storing operand in another stack
		}
		else if(s[i]==')')
		{
			top1=push(top1,s[i]);
		}
		else if(s[i]=='(')
		{
			while(top1->data!=')')
			{
				final=push(final,top1->data);
				top1=pop(top1);
			}
			top1=pop(top1);
		}
		else
		{
			while(top1->data!=')' && order(s[i])<order(top1->data) )
			{
				final=push(final,top1->data);
				top1=pop(top1);
			}
			top1=push(top1,s[i]);
		}
	}
	while(top1->data!=')')// pushing remening element
	{
		final=push(final,top1->data);
				top1=pop(top1);	
	}
	while(final->data!=')')// poping all emenent from final expression stack
	{
		cout<<final->data;
		final=pop(final);
	}
}
