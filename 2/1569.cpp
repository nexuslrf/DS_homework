#include<iostream>
using namespace std;
int lowbit(int n)
{
	return n&-n;
}
class treeArry
{
	int size;
	int* elem;
	int tail;
	public:
		treeArry(int n):size(n)
		{
			elem=new int[n+1];
			elem[0]=0;
			tail=0;
		}
		~treeArry()
		{
			delete[] elem;
		}
		void push_back(int n)
		{
			++tail;
			if(lowbit(tail)==1)
				elem[tail]=n;
			else
			{
				int t=lowbit(tail),p=tail-1;
				elem[tail]=n;
				while(t>1&&t-lowbit(p)>=1)
				{
					//printf("%d",p);
					elem[tail]+=elem[p];
					t-=lowbit(p);
					p-=lowbit(p);
				}
			}
			//printf("%d ",elem[tail]);
		}
		void update(int x,int y)
		{
			while(x<=tail)
			{
				elem[x]+=y;
				x+=lowbit(x);
			}
		}
		int sum(int k)
		{
			int t=0;
			while(k>0)
			{
			//	printf("%d#%d ",t,k);
				t+=elem[k];
				k-=lowbit(k);
				
			}
			return t;
		}
};
int main()
{
	int n,temp,ans[100000];
	cin>>n;
	treeArry tree(n);
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		tree.push_back(temp);
	}
	//printf("zz\n");
	char command[10];
	int x,y,indx=0;
	while(true)
	{
		cin>>command;
		if(command[0]=='e')
			break;
		cin>>x>>y;
		switch(command[0])
		{
			case'q': ans[indx++]=tree.sum(y)-tree.sum(x-1);break;
			case'i': tree.update(x,y);break;
			case'd': tree.update(x,-1*y);break;
		}
	}
	for(int i=0;i<indx;i++)
		cout<<ans[i]<<endl;
	return 0;
}
