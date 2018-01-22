#include<iostream>
#include<iomanip>
using namespace std;
int  mat[150][150];
int main()
{
	int n,cnt=1;
	cin>>n;
	int up=0,down=n-1,left=0,right=n-1;
	int loc[2]={0,-1};
	for(int i=0;i<2*n-1;i++)
	{
		if(i%4==0)
		{
			up++;
			while(loc[1]<right)
			{
				loc[1]++;
				mat[loc[0]][loc[1]]=cnt;
				cnt++;
			}
		}
		if(i%4==1)
		{
			right--;
			while(loc[0]<down)
			{
				loc[0]++;
				mat[loc[0]][loc[1]]=cnt;
				cnt++;
			}
		}
		if(i%4==2)
		{
			down--;
			while(loc[1]>left)
			{
				loc[1]--;
				mat[loc[0]][loc[1]]=cnt;
				cnt++;
			}
		}
		if(i%4==3)
		{
			left++;
			while(loc[0]>up)
			{
				loc[0]--;
				mat[loc[0]][loc[1]]=cnt;
				cnt++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<setw(6)<<mat[i][j];
		cout<<endl;
	}
	return 0;
}
