#include<cstdio>
using namespace std;
char *ans;
int indx;
void preorder(char *s,int n,int root,int mod=0)
{
	if(root>n)
		return;
	if(!mod)
	{
		printf("%c",s[root-1]);
		preorder(s,n,root*2);
		preorder(s,n,root*2+1);
	}
	else
	{
		ans[root-1]=s[indx];
		indx++;
		preorder(s,n,root*2,mod);
		preorder(s,n,root*2+1,mod);
	}
}
void inorder(char *s,int n,int root,int mod=0)
{
	if(root>n)
		return;
	if(!mod)
	{
		inorder(s,n,root*2);
		printf("%c", s[root-1]);
		inorder(s,n,root*2+1);
	}
	else
	{
		inorder(s,n,root*2,mod);
		ans[root-1]=s[indx];
		indx++;
		inorder(s,n,root*2+1,mod);
	}
}
void postorder(char *s,int n,int root,int mod=0)
{
	if(root>n)
		return;
	if(!mod)
	{
		postorder(s,n,root*2);
		postorder(s,n,root*2+1);
		printf("%c", s[root-1]);
	}
	else
	{
		postorder(s,n,root*2,mod);
		postorder(s,n,root*2+1,mod);
		ans[root-1]=s[indx];
		indx++;
	}
}
/*void getInfo(int n,int &height,int &re)
{
	height=0;
	int temp=n,p=1;
	while(temp)
	{
		height++;
		p<<=1;
		temp>>=1;
	}
	re=p-n-1;
}*/
int main()
{
	int t,n,mod;
	char s1[10],s2[10];
	char *input;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %s %s",&n,s1,s2);
		//printf("%d %d %s %s\n",t,n,s1,s2);
		input=new char[n+1];
		scanf("%s",input);
		if(s1[0]=='I')
		{
			if(s2[0]=='E')
			{
				inorder(input,n,1);
				printf("\n");
			}
			else
			{
				ans=new char[n+1];
				indx=0;
				inorder(input,n,1,1);
				ans[n]='\0';
				printf("%s\n", ans);
				delete[] ans;
			}
		}
		else if(s1[0]=='P'&&s1[1]=='R')
		{
			if(s2[0]=='E')
			{
				preorder(input,n,1);
				printf("\n");
			}
			else
			{
				ans=new char[n+1];
				indx=0;
				preorder(input,n,1,1);
				ans[n]='\0';
				printf("%s\n", ans);
				delete[] ans;
			}
		}
		else
		{
			if(s2[0]=='E')
			{
				postorder(input,n,1);
				printf("\n");
			}
			else
			{
				ans=new char[n+1];
				indx=0;
				postorder(input,n,1,1);
				ans[n]='\0';
				printf("%s\n", ans);
				delete[] ans;
			}
		}
		delete[] input;
	}
	return 0;
}