#include<cstdio>
#include<cstring>
using namespace std;
char tree[1001];
char preord[27],inord[27];
int len,maxs=0;
void insert(char root,int idxr,int s1,int s2,int e)
{
	if(maxs<idxr)
		maxs=idxr;
	tree[idxr]=root;
	int t=s2;
	while(inord[t]!=root)
		t++;
	if(s2<t)
		insert(preord[s1+1],idxr*2+1,s1+1,s2,t-1);
	if(t<e)
		insert(preord[s1+t-s2+1],idxr*2+2,s1+t-s2+1,t+1,e);
}
int main()
{
	scanf("%s",&preord);
	scanf("%s",&inord);
	char root=preord[0];
	len=strlen(preord);
	insert(root,0,0,0,len-1);
	for(int i=0;i<=maxs;i++)
	{
		if(tree[i])
			printf("%c ", tree[i]);
		else
			printf("NULL ");
	}
	return 0
}	

