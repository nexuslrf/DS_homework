#include<cstdio>
#include<iostream>
using namespace std;
struct pos
{
	int x;
	int y;
};
class queue
{
	pos *elem;
	int maxSize;
	int front,rear;
	void doubleSpace();
public:
	 queue(int init=10)
	 {
	 	maxSize=init;
	 	elem=new pos[init];
	 	front=rear=0;
	 }
	~ queue()
	{
		delete elem;
	}
	void enQueue(int a,int b)
	{
		if((rear+1)%maxSize==front)
			doubleSpace();
		rear=(rear+1)%maxSize;
		elem[rear].x=a;
		elem[rear].y=b;
	}
	void deQueue()
	{
		front=(front+1)%maxSize;
	}
	void getpos(int &a,int &b)
	{
		front=(front+1)%maxSize;
		a=elem[front].x;
		b=elem[front].y;
	}
	bool isEmpty()
	{
		return front==rear;
	}
};
void queue::doubleSpace()
{
	pos *temp=new pos[2*maxSize];
	for(int i=1;i<maxSize;i++)
	{
		temp[i]=elem[(i+front)%maxSize];
	}
	front=0;
	rear=maxSize-1;
	maxSize*=2;
	delete[] elem;
	elem=temp;
}
int mat[101][101];
int main()
{
	int n,cnt=0;
	queue list;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
			if(mat[i][j]==1)
			{
				list.enQueue(i,j);
				cnt++;
			}
		}
	int round=0,x,y,temp=0;
	while(!list.isEmpty())
	{
		list.getpos(x,y);
		cnt--;
		if(x-1>=0&&mat[x-1][y]==0)
		{
			mat[x-1][y]=1;
			list.enQueue(x-1,y);
			temp++;
		}
		if(x+1<n&&mat[x+1][y]==0)
		{
			mat[x+1][y]=1;
			list.enQueue(x+1,y);
			temp++;
		}
		if(y-1>=0&&mat[x][y-1]==0)
		{
			mat[x][y-1]=1;
			list.enQueue(x,y-1);
			temp++;
		}
		if(y+1<n&&mat[x][y+1]==0)
		{
			mat[x][y+1]=1;
			list.enQueue(x,y+1);
			temp++;
		}
		if(!cnt)
		{
			round++;
			cnt=temp;
			temp=0;
			/*
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					cout<<mat[i][j]<<" ";
				cout<<endl;
			}
			cout<<endl;*/
		}
	}
	round--;
	printf("%d",round);
	return 0;
}