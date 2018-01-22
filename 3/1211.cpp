#include<cstdio>
//#include<iostream>
using namespace std;
struct Node
{
	int val;
	int d;
	Node* next;
};
class stack
{
	int len;
	Node* top;
public:
	stack(){top=NULL;len=0;}
	~stack()
	{
		Node *temp=top;
		while(temp)
		{
			top=temp->next;
			delete temp;
			temp=top;
		}
	}
	void push(int x)
	{
		Node *temp=new Node;
		temp->val=x;
		temp->d=0;
		temp->next=top;
		top=temp;
		len++;
	}
	bool isEmpty()
	{
		return top==NULL;
	}
	int pop()
	{
		int x=top->val;
		Node* temp=top;
		top=top->next;
		len--;
		delete temp;
		return x;
	}
	int getlen()
	{
		return len;
	}
	int getD()
	{
		int t=top->d++;
		return t;
	}
	int gettop()
	{
		return top->val;
	}
};
 int main()
 {
 	int n;
 	scanf("%d",&n);
 	int *p=new int[n+1];
 	int *q=new int[n+1];
 	int *flag=new int[n+1];
 	stack trunk;
 //	BiTree tree;
 	for(int i=0;i<=n;i++)
 		flag[i]=0;
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%d %d",&p[i],&q[i]);
 		flag[p[i]]=1;
 		flag[q[i]]=1;
	}
	int height=1;
	int nt=n;
	while(nt/2)
	{
		height++;
		nt/=2;
	}
	int root;
	for(int i=1;i<=n;i++)
	{
 		if(!flag[i])
 		{
 			root=i;
 			break;
		 }
 	}
 	int i=2,d=0,prev=height+1,judge=1;
 	trunk.push(root);
 	while(!trunk.isEmpty()&&judge)
 	{
		d=trunk.getD();
		//cout<<trunk.getlen()<<" "<<d<<" "<<root<<endl;
		if(d==0)
			root=p[root];
		else if(d==1)
			root=q[root];
		else
		{
			trunk.pop();
			if(trunk.isEmpty())
				break;
			root=trunk.gettop();
			continue;
		}
 		if(!root)
 		{
 			//cout<<'p'<<prev<<endl;
 			if(prev>=trunk.getlen())
 				prev=trunk.getlen();
 			else
 			{
 				judge=0;
 				break;
 			}
 			if (prev>height||prev<height-1)
 			{
 				judge=0;
 				break;
 			}
 			root=trunk.gettop();
 		}
 		else
 			trunk.push(root);
 	}
 	if(judge)
 		printf("Y");
 	else
 		printf("N");
 	delete p,q;
 	return 0;
} 
