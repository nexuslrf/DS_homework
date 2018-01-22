#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> a;
	int m,n;
	cin>>m>>n;
	while(m!=0||(!a.empty()))
	{
		if(m==0)
		{
			m=a.top();
			a.pop();
			n++;
		}
		else if(n==0)
		{
			m--;
			n=1;
		}
		else
		{
			a.push(m-1);
			n--;		
		}
	}
	cout<<n+1;
	return 0;
 } 
