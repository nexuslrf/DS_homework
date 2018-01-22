#include<cstdio>
using namespace std;
struct Node
{
	int val;
	Node *son;
	Node *bro;
	Node(int x)
	{
		val=x;
		son=NULL;
		bro=NULL;
	}                                                                                                           
};
class BernoliTree
{
	Node **roots;
	int maxSize;
	int currentSize;
	void clear(Node *root)
	{
		if(!root)
			return;
		clear(root->son);
		clear(root->bro);
		delete root;
	}
	Node* merge(Node *a,Node *b,int r)
	{
		Node *root,*p,*q;
		if(a->val<b->val)
		{
			root=a;
			p=b;
		}
		else
		{
			root=b;
			p=a;
		}
		if(r==0)
		{
			root->son=p;
		}
		else
		{
			q=root->son;
			for(int i=0;i<r-1;i++)
				q=q->bro;
			q->bro=p;
		}
		return root;
	}
public:
	BernoliTree(int n=10)
	{
		maxSize=n;
		currentSize=0;
		roots=new Node*[n];
		for(int i=0;i<n;i++)
			roots[i]=NULL;
	}
	~BernoliTree()
	{
		for(int i=0;i<maxSize;i++)
		{
			if(roots[i])
				clear(roots[i]);
		}
		delete[] roots;
	}
	void push(int x)
	{
		Node *temp=new Node(x);
		int i=0;
		if(!roots[0])
			roots[0]=temp;
		else
		{
			do
			{
				temp=merge(temp,roots[i],i);
				roots[i]=NULL;
				i++;
			}while(roots[i]);
			roots[i]=temp;
		}
		currentSize++;
		//printf("%d\n", currentSize);
	}
	int getMin()
	{
		int c=currentSize,i=0,mini=2147483647;
		int ans;
		while(c)
		{
			if(roots[i])
			{
				if(roots[i]->val<mini)
				{
					mini=roots[i]->val;
					ans=i;
				}
				c-=(1<<i);
			}
			i++;
		}
		//printf("%d\n", ans);
		return ans;
	}
	int Min()
	{
		int i=getMin();
		return roots[i]->val;
	}
	void pop()
	{
		int pos=getMin();
		currentSize--;
		if(pos==0)
		{
			delete roots[0];
			roots[0]=NULL;
			return;
		}
		Node **temp=new Node*[pos];
		Node *p;
		temp[0]=roots[pos]->son;
		for(int i=1;i<pos;i++)
		{
			temp[i]=temp[i-1]->bro;
			temp[i-1]->bro=NULL;
		}
		delete roots[pos];
		roots[pos]=NULL;
		for(int i=0;i<pos;i++)
		{
			p=temp[i];
			int j=i;
			while(roots[j])
			{
				p=merge(p,roots[j],j);
				roots[j]=NULL;
				j++;
			}
			roots[j]=p;
		}
		delete[] temp;
	}
};
int main()
{
	int m;
	scanf("%d",&m);
	BernoliTree tree(m);
	char s[8];
	int x;
	for(int i=0;i<m;i++)
	{
		scanf("%s",s);
		switch(s[0])
		{
			case 'i':scanf("%d",&x);tree.push(x);break;
			case 'd':tree.pop();break;
			case 'm':printf("%d\n", tree.Min());
		}
	}
	return 0;
}