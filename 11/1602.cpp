#include<iostream>
#include<cstdio>
using namespace std;
int num1[100000],num2[100000];
int n,m;
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
		scanf("%d",num1+i);
	for(int i=0;i<n;i++)
		scanf("%d",num2+i);
	int i=0,j=0;
	while(i<m&&j<n)
	{
		if(num1[i]<num2[j]) printf("%d ", num1[i++]);
		else printf("%d ", num2[j++]);
	}	
	while(i<m) printf("%d ", num1[i++]);
	while(j<n) printf("%d ", num2[j++]);
	return 0;
}