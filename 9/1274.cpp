#include <iostream>
#include <cstdio>
using namespace std;
int a[103],b[103],step[100][103],ans[300],lens[100];
char x[300],y[300];
int strlen(char *s)
{
	int i=0;
	while(s[i])
		i++;
	return i;
}
int main()
{
	scanf("%s%s",x,y);
	int lenA=strlen(x),lenB=strlen(y),lenC=0;
	for(int i=0;i<lenA;i++)
		a[i]=x[lenA-1-i]-'0';
	for(int i=0;i<lenB;i++)
		b[i]=y[lenB-1-i]-'0';
	while(a[lenA-1]==0&&lenA>1) lenA--;
	while(b[lenB-1]==0&&lenB>1) lenB--;
	int cnt=0,up,temp;
	for(int i=0;i<lenB;i++)
	{
		if(b[i]==0)
		{
			lens[i]=0;
			continue;
		}
		lens[i]=lenA; up=0;
		for(int j=0;j<lenA;j++)
		{
			temp=a[j]*b[i]+up;
			step[i][j]=temp%10;
			up=temp/10;
		}
		if(up)
		{
			step[i][lenA]+=up;
			lens[i]++;
		}
		int k=0,up=0;
		while(k<lens[i])
		{
			temp=ans[k+i]+step[i][k]+up;
			ans[k+i]=temp%10;
			up=temp/10;
			k++;
		}
		lenC=max(lenC,k+i);
		if(up)
		{
			ans[k+i]+=up;
			lenC=max(lenC,k+i+1);
		}
		cnt++;
		// cout<<endl;
	}
	for(int i=0;i<lenC-lenA;i++) printf(" ");
	for(int i=lenA-1;i>=0;i--) printf("%d", a[i]);
	printf("\n");
	for(int i=0;i<lenC-lenB;i++) printf(" ");
	for(int i=lenB-1;i>=0;i--) printf("%d", b[i]);
	printf("\n");
	for(int i=0;i<lenC;i++) printf("-");
	printf("\n");
	if(cnt>1)
	{
		for(int i=0;i<lenB;i++)
		{
			if(lens[i])
			{
				for(int j=0;j<lenC-lens[i]-i;j++) printf(" ");
				for(int j=lens[i]-1;j>=0;j--) printf("%d", step[i][j]);
					printf("\n");
			}
		}
		for(int i=0;i<lenC;i++) printf("-");
		printf("\n");
	}
	for(int i=lenC-1;i>=0;i--)
			printf("%d", ans[i]);
	printf("\n");
}