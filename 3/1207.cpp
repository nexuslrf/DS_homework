#include<cstdio>
#include<iostream>
using namespace std;
struct Car
{
	int time;
	Car *next;
};
class queque
{
	Car *head,*tail;
	public:
		queque()
		{
			head=NULL;
			tail=NULL;
		}
		~queque()
		{
			Car *p=head;
			while(p)
			{
				head=head->next;
				delete p;
				p=head;
			}
		}
		void push(int y)
		{
			Car *tmp=new Car;
			tmp->time=y;
			tmp->next=NULL;
			if(!tail)
			{
				head=tmp;
			}
			else
				tail->next=tmp;
			tail=tmp;
		}
		void pop()
		{
			Car *tmp=head;
			head=head->next;
			delete tmp;
		}
		int time()
		{
			return head->time;
		}
};
int main()
{
	int n;
	scanf("%d",&n);
	int id,temp,ac=0,bc=0,waita=0,waitb=0,tick=0;
	queque x,y;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&id,&temp);		
		if(!id) 
		{
			x.push(temp);
			ac++;
		}
		else
		{
			y.push(temp);
			bc++;
		}
	 } 
	int n1=ac,n2=bc;
	temp=x.time()<y.time()?x.time():y.time();
	tick=(temp/10)*10;
	int p=0,con=0;
	while(ac>0&&bc>0)
	{
		bool flag=1;
	//	printf("%d %d %d %d %d %d %d\n",ac,bc,tick,con,p,x.time(),y.time());
		if(x.time()<=tick&&p<8)
		{
			waita+=(tick-x.time());
			x.pop();
			ac--;
			con++;
			p++;
			flag=0;
		}
		else if(p==8)
		{
			if(y.time()<=tick)
			{ 
				waitb+=(tick-y.time());
				y.pop();
				bc--;
				con++;
				flag=0;
			}
			else if(x.time()<=tick)
			{
				waita+=(tick-x.time());
				x.pop();
				ac--;
				con++;
				p=0;
				flag=0;
			}
		}
		else if(y.time()<=tick)
		{
			waitb+=(tick-y.time());
			y.pop();
			bc--;
			con++;
			flag=0;
		}
		if(flag||con==10)
		{
			con=0;
			tick+=10; 
			p=0;
		}
	}
	while(ac!=0)
	{
		bool flag=1;
		if(x.time()<=tick)
		{ 
			waita+=(tick-x.time());
			x.pop();
			ac--; 
			con++;
			flag=0;
		}
		if(flag||con==10)
		{
			con=0;
			tick+=10; 
		}		
	}
	while(bc!=0)
	{
		bool flag=1;
		if(y.time()<=tick)
		{ 
			waitb+=(tick-y.time());
			y.pop();
			bc--; 
			con++;
			flag=0;
		}
		if(flag||con==10)
		{
			con=0;
			tick+=10; 
		}
	}
	printf("%.3f %.3f",waita*1.0/n1,waitb*1.0/n2);
 } 
