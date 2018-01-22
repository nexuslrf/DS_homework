#include<iostream>
#include<cstring>
using namespace std;
void factorize(int n,int* &temp)
{
	int i=2,a[25],b[25];
	int cnt1=0,cnt2=0;
	while(i*i<n)
	{
		if(n%i==0)
		{
			a[cnt1++]=i;
			b[cnt2++]=n/i;
		}
		i++;
	}
	if(i*i==n)
	{
		a[cnt1++]=i;
	}
	temp[0]=cnt1+cnt2+1;
	for(i=0;i<cnt1;i++)
		temp[i+1]=a[i];
	for(i=0;i<cnt2;i++)
		temp[i+cnt1+1]=b[cnt2-1-i];
	temp[temp[0]]=n;
	return;
}
int main()
{
	int *num=new int [50];
	char Cltxt[101];
	char Ectxt[101];
	char Try[101];
	cin.getline(Cltxt,100);
	cin.getline(Ectxt,100);
	int n=strlen(Cltxt);
	factorize(n,num);
//	for(int i=1;i<=num[0];i++)
//		cout<<num[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=num[0];i++)
	{
		//int seg=n/num[i];
		int indx=0;
		for(int j=0;j<num[i];j++)
		{
			for(int k=0;k<n;k+=num[i])
			{
				Try[indx++]=Cltxt[k+j];
			}
		}
		Try[indx]='\0';
		if(strcmp(Ectxt,Try)==0)
		{
			cout<<num[i];
			return 0; 
		} 
	}
	cout<<"No Solution";
	return 0;
}
