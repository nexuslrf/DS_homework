#include<cstdio>
#include<iostream>
using namespace std;
int note[100001]={};
int main()
{
	int n,m,mhp=0;
	scanf("%d",&n);
	int *Hps=new int[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",Hps+i);
		mhp=max(mhp,Hps[i]);
	}
	int *dpA=new int[mhp+1],*dpS=new int[mhp+1];
	dpS[0]=0;dpA[0]=0;
	scanf("%d",&m);
	//skill *listA=new skill[m],*listS=new skill[m];
	char name[31],tag[10];
	int mps,d,na=0,ns=0;
	for(int i=0;i<m;i++) 
	{
		scanf("%s%d%s%d",name,&mps,tag,&d);
		if(d==0) continue;
		if(tag[0]=='S')
		{
			int k=1;
			for(int j=1;j<=mhp;j++)
			{
				if(ns==0)
				{
					if(j<k*d) dpS[j]=k*mps;
					if(j==k*d) dpS[j]=k++*mps;
				}
				else
				{
					if(j<=d) dpS[j]=min(dpS[j],mps);
					else
						dpS[j]=min(dpS[j],dpS[j-d]+mps);
				}
			}
			ns++;
		}
		else
		{
			int k=1;
			for(int j=1;j<=mhp;j++)
			{
				if(na==0)
				{
					if(j<k*d) {dpA[j]=k*mps;note[j]=k*d;}
					if(j==k*d) {dpA[j]=k*mps;note[j]=k++*d;}
				}
				else
				{
					if(j<=d) 
					{
						if(dpA[j]>mps) {dpA[j]=mps;note[j]=d;}
						if(dpA[j]==mps) note[j]=max(note[j],d);
					}
					else
					{
						if(dpA[j]>dpA[j-d]+mps)
						{
							dpA[j]=dpA[j-d]+mps;
							note[j]=note[j-d]+d;
						}
						else if(dpA[j]==dpA[j-d]+mps) note[j]=max(note[j],note[j-d]+d);
					}
				}
			}
			na++;
		}
	}
	// for(int i=0;i<=mhp;i++) cout<<dpA[i]<<" ";
	// 	cout<<endl;
	// for(int i=0;i<=mhp;i++) cout<<dpS[i]<<" ";
	// 	cout<<endl;
	// for(int i=0;i<=mhp;i++) cout<<note[i]<<" ";
	// 	cout<<endl;
	int ans=2147483647;
	if(na)
	for(int i=0;i<=mhp;i++)
	{
		int sum=dpA[i];
		for(int j=0;j<n;j++)
		{	
			if(Hps[j]>note[i])
				sum+=dpS[Hps[j]-note[i]];
		}
		ans=min(ans,sum);
	}
	else 
	{
		int sum=0;
		for(int j=0;j<n;j++)
		{
			sum+=dpS[Hps[j]];
		}
		ans=sum;
	}
	printf("%d", ans);
	delete[] Hps,dpA,dpS;
	return 0;
}

// 61
// 16749
// 54643
// 59454
// 69380
// 22697
// 71164
// 59304
// 8844
// 47996
// 8770
// 86546
// 53899
// 65910
// 94016
// 68758
// 9847
// 64298
// 75219
// 66633
// 16781
// 55063
// 52969
// 48742
// 3820
// 48756
// 84227
// 96114
// 57160
// 27576
// 81666
// 13235
// 25305
// 23541
// 94729
// 8975
// 37125
// 94225
// 21990
// 5244
// 55888
// 19159
// 52253
// 13523
// 50035
// 83273
// 75606
// 61550
// 3523
// 10107
// 79117
// 65618
// 52327
// 11665
// 95634
// 24921
// 92708
// 70340
// 88715
// 26720
// 97035
// 88735
// 59
// # 23 A 1866
// # 37 A 2858
// # 2 S 6601
// # 89 A 8118
// # 45 S 528
// # 12 S 4775
// # 41 A 9175
// # 93 S 5693
// # 43 S 1677
// # 91 S 8509
// # 78 A 8634
// # 17 A 868
// # 19 A 5924
// # 1 S 25
// # 76 S 8416
// # 22 A 8429
// # 25 A 313
// # 38 S 9764
// # 76 S 8177
// # 89 A 7288
// # 96 S 4607
// # 94 A 5004
// # 34 S 5815
// # 50 S 3764
// # 38 A 493
// # 54 A 810
// # 9 S 3251
// # 47 A 2095
// # 84 A 5560
// # 32 S 151
// # 96 A 7857
// # 46 A 6262
// # 11 S 2878
// # 6 S 4512
// # 65 A 5997
// # 12 S 5450
// # 17 A 3416
// # 5 A 245
// # 16 S 2095
// # 43 S 799
// # 6 S 5048
// # 55 S 7010
// # 82 S 5934
// # 8 A 1028
// # 33 A 3072
// # 78 A 174
// # 82 A 6745
// # 40 S 5236
// # 19 A 5586
// # 64 A 554
// # 12 S 6428
// # 95 A 2879
// # 42 S 4633
// # 32 A 7164
// # 10 A 1860
// # 79 A 7295
// # 85 A 4590
// # 23 S 5544
// # 4 A 2408
// # 36 A 4997
// # 87 A 6864
