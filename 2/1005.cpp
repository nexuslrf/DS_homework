#include<iostream>
using namespace std;
int ans[20];
int mat[9][9];
bool judge(int a[][9])
{
	int flag[3][10]={};
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(flag[0][a[i][j]]!=i+1)
				flag[0][a[i][j]]=i+1;
			else
				return false;
		}
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(flag[1][a[j][i]]!=i+1)
				flag[1][a[j][i]]=i+1;
			else
				return false;
		}
	}
	int cnt=1;
	for(int i=0;i<9;i+=3)
	{
		for(int j=0;j<9;j+=3)
		{
			for(int k=i;k<i+3;k++)
				for(int l=j;l<j+3;l++)
				{
					if(flag[2][a[k][l]]!=cnt)
						flag[2][a[k][l]]=cnt;
					else
						return false;
				}
			cnt++;
		}
	}
	return true;
}
int main()

{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<9;j++)
			for(int k=0;k<9;k++)
				cin>>mat[j][k];
		ans[i]=judge(mat); 
	}
	for(int i=0;i<n;i++)
	{
		if(ans[i])
			cout<<"Right"<<endl;
		else
			cout<<"Wrong"<<endl;
	}
	return 0;
} 
