#include<cstdio>
using namespace std;
class Tstack
{
	int* elem;
	int maxSize;
	int top;
	public:
		Tstack(int size)
		{
			maxSize=size;
			elem=new int[size];
			top=-1;
		}
		~Tstack()
		{
			delete[] elem;
		}
		bool push(int n)
		{
			if(top+1==maxSize)
				return false;
			else
			{
				elem[++top]=n;
				return true;
			}
		}
		int gettop()
		{
			return elem[top];
		}
		bool isEmpty()
		{
			return top==-1;
		}
		int pop()
		{
			top--;
			return elem[top-1];
		}
};
bool judge(int* &x,int m,int n)
{
	Tstack park(m);
	int ci=0;
	for(int i=0;i<n;i++)
	{
		if(!park.isEmpty()&&park.gettop()==x[i])
			park.pop();
		else if(ci<n)
		{
			while(ci<n&&x[i]!=ci)
			{
				if(!park.push(ci++))
					return false;
			}
			ci++;
		}
		else
			return false;
	}
	return true;
	
}
int main()
{
	int t,n,m;
	scanf("%d",&t);
	int *ans=new int[t];
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&n,&m);
		int *x=new int[n];
		for(int j=0;j<n;j++)
			scanf("%d",&x[j]);
		ans[i]=judge(x,m,n); 
		delete[] x;
	}
	for(int i=0;i<t;i++)
	{
		if(ans[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
