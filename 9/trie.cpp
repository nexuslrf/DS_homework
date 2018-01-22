#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
	Node *chd[2];
	bool flag;
	Node(){
		chd[0]=chd[1]=NULL;
		flag=0;
	}
};
int cnt=0,ans=0;
void insert(Node *t,int x)
{
	int temp=0;
	int idx=30;
	Node *p=t;
	while(idx>=0)
	{
		int bi=(x&(1<<idx))?1:0;
		//cout<<bi<<endl;
		if(cnt)
		{
			if(p->chd[!bi])
			{
				temp+=(1<<idx);
				p=p->chd[!bi];
			}
			else
				p=p->chd[bi];
		}

		if(t->chd[bi])
			t=t->chd[bi];
		else
		{
			t->chd[bi]=new Node;
			t=t->chd[bi];
		}
		idx--;
	}
	if(temp>ans) ans=temp;
	cnt++;
}
int main()
{
	int n;
	int a[100000];
	cin>>n;
	Node *root=new Node;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		insert(root,a[i]);
	}
	int ans2=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int temp=a[i]^a[j];
			if(temp>ans2) ans2=temp;
		}
	}
	cout<<ans<<endl<<ans2;
}