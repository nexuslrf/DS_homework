#include<iostream>
using namespace std;
int main()
{
	int bank=0,exp,bal=0,flag=0;
	for(int i=0;i<12;i++)
	{
		cin>>exp;
		if(!flag)
		{
			bal=300+bal-exp;
			if(bal<0&&flag==0)
				flag=i+1;
			bank+=(bal/100)*100;
			bal%=100; 
		}
	}
	if(!flag)
		cout<<bal+bank/10*12;
	else
		cout<<'-'<<flag;
	return 0;
}
