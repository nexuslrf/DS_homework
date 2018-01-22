#include <iostream>
#include <cstdio>
using namespace std;

//不相交集

class djs{

public:

    int Size;

    int *p;

    djs(int s){

        Size = s;

        p = new int[Size];

        for(int i = 0; i < Size; ++i) p[i] = -1;

    }

    ~djs(){delete[] p;}

    void Union(int r1, int r2){

        if(r1 == r2 ) return;

        p[r1]=r2;

    }

    int Find(int x){

        if (p[x]<0) return x;

        else return p[x]=Find(p[x]);





        int start = x, tmp;

        while(p[x] >= 0) x = p[x];

        while(start != x){

            tmp = p[start];

            p[start] = x;

            start = tmp;

        }

        return x;

    }

    void print(){

        for(int i = 0; i < Size; ++i)

            cout << i << " " << p[i] << endl;

    }

};



int w[10000][10000]={0};



//是否位于三角形左腰

bool zs(int x);



//是否位于三角形右腰

bool ys(int x);



//是否位于三角形底边

bool zyx(int x);



//位于第几行

int row(int x);



//找路径

void fp(int s);



int *pa, cnt = 0;

int N, M, A, B, P, Q, proot, n;

int *visit;

int *km;



djs puz(1000000);







//是否位于三角形左腰

bool zs(int x){

    for (int i = 0; i < N; ++i){

        if(x == km[i]-i)

            return true;

    }

    return false;

}



//是否位于三角形右腰

bool ys(int x){

    for (int i = 0; i < N; ++i){

        if(x == km[i])

            return true;

    }

    return false;

}



//是否位于三角形底边

bool zyx(int x){

    for (int i = 0; i < N; ++i){

        if(x == M-1-i)

            return true;

    }

    return false;

}



//位于第几行

int row(int x){

    for (int i = 0; i < N; ++i){

        if(km[i]-i<=x && x<=km[i])

            return i+1;

    }

    cout << "Error!" << endl;

}



int main(){
    freopen("1232.in","r",stdin);
    scanf("%d%d%d",&N,&A,&B);

    A--; B--;//转化为从0开始的序号



    //km[i]为第i+1行行尾序号

    km = new int[N];

    M = N*(N+1)/2;

    for(int i = 0; i < N; ++i){

        km[i] = (i+1)*(i+2)/2-1;

    }





    pa = new int[M];

    visit = new int[M];

    for(int i = 0; i < M; ++i){pa[i] = -1;}

    for(int i = 0; i < M; ++i){visit[i] = 0;}





    //砸墙

    while(1){

        if(puz.Find(A) == puz.Find(B) && puz.Find(A)!=-1)break;

        scanf("%d%d",&P,&Q);

        P--;

        proot = puz.Find(P);

        n = row(P);//n为P的行号

        switch(Q){

            case 0:     //砸左上

                        if(!zs(P)){puz.Union(proot, puz.Find(P-n)); }

                        w[P][P-n]=1;

                        w[P-n][P]=1;

                        break;

            case 1:     //砸右上

                        if(!ys(P)){puz.Union(proot, puz.Find(P-n+1)); }

                        w[P][P-n+1]=1;

                        w[P-n+1][P]=1;

                        break;

            case 2:     //砸左下

                        if(!zyx(P)){puz.Union(proot, puz.Find(P+n));}

                        w[P][P+n]=1;

                        w[P+n][P]=1;

                        break;

            case 3:     //砸右下

                        if(!zyx(P)){puz.Union(proot, puz.Find(P+n+1));}

                        w[P][P+n+1]=1;

                        w[P+n+1][P]=1;

                        break;

        }



    }

    fp(A);

    return 0;

}







int flag=1;

//找路径



void fp(int s)

{

    if (!flag) return;

    if (s==B){cout<<A+1<<' ';for (int i=0; i<cnt; ++i) cout<<pa[i]+1<<' ';flag=1;cout<<endl;return;}

    for (int i=0; i<M; ++i)

        if (w[s][i] && !visit[i])

        {

            visit[i]=1;

            pa[cnt++]=i;

            fp(i);

            cnt--;

            visit[i]=0;

        }

}