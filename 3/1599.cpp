#include<cstdio>
using namespace std;
struct Brackets
{
	char type;
	Brackets *next;
	Brackets(char c)
	{
		type=c;
	}
};
bool match(char a,char b)
{
	if(a=='('&&b==')')
		return true;
	else if(a=='['&&b==']')
		return true;
	else if(a=='{'&&b=='}')
		return true;
	else
		return false;
}
class stack
{
	Brackets *top;
public:
	stack()
	{
		top=NULL;
	}
	~stack()
	{
		Brackets *temp=top;
		while(top)
		{
			top=top->next;
			delete temp;
			temp=top;
		}
	}
	void push(char x)
	{
		Brackets* temp=new Brackets(x);
		temp->type=x;
		temp->next=top;
		top=temp;
	}
	void pop()
	{
		Brackets *temp=top;
		top=top->next;
		delete temp;
	}
	char getTop()
	{
		return top->type;
	}
	bool isEmpty()
	{
		return top==NULL;
	}
	bool judge()
	{
		stack opera;
		bool flag=true;
		Brackets *temp=top;
		char c;
		while(flag&&temp)
		{
			c=temp->type;
			//printf("@ %c\n", c);
			temp=temp->next;
			if(c==')'||c==']'||c=='}')
				opera.push(c);
			else
			{
				if(!opera.isEmpty())
				{
					if(match(c,opera.getTop()))
					{
						//printf("%c\n", opera.getTop());
						opera.pop();

					}
					else
						flag=0;
				}
				else
					flag=0;
			}
		}
		if(!flag)
			return false;
		if(opera.isEmpty())
			return true;
	}
};
int main()
{
	stack store;
	int n,k;
	char c[3];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%s",c);
			store.push(c[0]);
		}
		if(k==2)
		{
			if(!store.isEmpty())
			{
				store.pop();
			}
		}
		if(k==3)
			if(!store.isEmpty())
				printf("%c\n",store.getTop());
		if(k==4)
			if(store.judge())
				printf("YES\n");
			else
				printf("NO\n");	
	}
	return 0;
}