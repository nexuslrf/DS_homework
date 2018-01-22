#include<iostream>
 
using namespace std;
 
int main()
{
	int N;
	int height[1000], maxIndex[1000];
	long long int water = 0;
	int maxNum = 0, max = -1;
	int meaHeight;
	char m;
 
	cin >> N;
	// m = cin.get();
	// m = cin.get();
 
	for (int i = 0;i < N;i++)
	{
		cin >> height[i] ;//>> m;
		max = (max > height[i]) ? max : height[i];
	}
 
	for (int i = 0;i < N;i++)
	{
		if (height[i] == max)
		{
			maxIndex[maxNum] = i;
			maxNum++;
		}
	}
	
	meaHeight = height[0];
	for (int i = 1;i <= maxIndex[0];i++)
	{
		if (height[i] < meaHeight)
		{
			water += meaHeight - height[i];
		}
		else
		{
			meaHeight = height[i];
		}
	}
 
	meaHeight = height[N - 1];
	for (int i = N - 2;i >= maxIndex[maxNum - 1];i--)
	{
		if (height[i] < meaHeight)
		{
			water += meaHeight - height[i];
		}
		else
		{
			meaHeight = height[i];
		}
	}
 
	for (int i = maxIndex[0];i < maxIndex[maxNum - 1];i++)
	{
		water += (max - height[i]);
	}
 
	cout << water;
 
	return 0;
}
