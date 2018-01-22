#include <iostream>
#include <stdio.h>
using namespace std;
int abs(int num)
{
    if(num<0) return 0-num;
    else return num;
}
struct Node
{
    int x;
    int y;
    int start;
    int end;
    Node() {x=-1;y=-1;start=-1;end=-1;}
};

Node arr[100010];
class heap
{
    int pos;
    public:
    heap() {pos=-1;}
    void push(Node obj)
    {
        pos++;
        arr[pos]=obj;
        int p=pos;
        while(p>0)
        {
            if(obj.end<arr[(p-1)/2].end)
            {
                arr[p]=arr[(p-1)/2];
                p=(p-1)/2;
            }
            else break;
        }
        arr[p]=obj;
    }
    Node pop()
    {
        Node obj=arr[0];
        arr[0]=arr[pos];
        Node tmp=arr[0];
        pos--;
        int p=0;
        int child=p*2+1;
        while(child<=pos)
        {
            if(child!=pos and arr[child].end>arr[child+1].end) child++;
            if(arr[child].end<tmp.end)
            {
                arr[p]=arr[child];
                p=child;
                child=p*2+1;
            }
            else break;
        }
        arr[p]=tmp;
        return obj;
    }
    bool isEmpty(){return pos==-1;}
    void clear(){pos=-1;}
};
int t[100][100];
int dis[100][100];
int cost[100][100];
int main()
{
    freopen("2106.in","r",stdin);
    int N,M;
    cin>>N>>M;
    int i,j,k;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            scanf("%d",&dis[i][j]);
            t[i][j]=-1;
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    int xx,xy,yx,yy,zx,zy;
    cin>>xx>>xy>>yx>>yy>>zx>>zy;
    xx--;xy--;yx--;yy--;zx--;zy--;
    int XY=-1,YX=-1,XZ=-1,ZX=-1,YZ=-1,ZY=-1;
    heap H;
    Node tmp;
    tmp.x=xx;
    tmp.y=xy;
    tmp.start=0;
    tmp.end=cost[xx][xy];
    H.push(tmp);
    t[tmp.x][tmp.y]=0;
    Node obj;
    while(!H.isEmpty())
    {
        if(XY!=-1 and XZ !=-1) break;
        tmp=H.pop();
        if(tmp.x==yx and tmp.y==yy)
        {
            if(XY==-1) XY=tmp.start;
            else XY=max(XY,tmp.start);
        }
        if(tmp.x==zx and tmp.y==zy)
        {
            if(XZ==-1) XZ=tmp.start;
            else XZ=min(XZ,tmp.start);
        }
        if(tmp.start==t[tmp.x][tmp.y] )
        {
            for(k=1;k<=min(200,dis[tmp.x][tmp.y]);k++)
            for(i=-k;i<=k;i++)
            {
                j=k-abs(i);
                if(tmp.x+i<N and tmp.x+i>=0 and tmp.y-j>=0)
                {
                    if(t[tmp.x+i][tmp.y-j]==-1 or t[tmp.x+i][tmp.y-j]>tmp.end)
                    {
                        obj.x=tmp.x+i;
                        obj.y=tmp.y-j;
                        obj.start=tmp.end;
                        obj.end=obj.start+cost[obj.x][obj.y];
                        t[obj.x][obj.y]=obj.start;
                        H.push(obj);
                    }
                }
                if(tmp.x+i<N and tmp.x+i>=0 and tmp.y+j<M)
                {
                    if(t[tmp.x+i][tmp.y+j]==-1 or t[tmp.x+i][tmp.y+j]>tmp.end)
                    {
                        obj.x=tmp.x+i;
                        obj.y=tmp.y+j;
                        obj.start=tmp.end;
                        obj.end=obj.start+cost[obj.x][obj.y];
                        t[obj.x][obj.y]=obj.start;
                        H.push(obj);
                    }
                }
            }
        }
    }
    H.clear();
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            t[i][j]=-1;
        }
    }
    tmp.x=yx;
    tmp.y=yy;
    tmp.start=0;
    tmp.end=cost[yx][yy];
    H.push(tmp);
    t[tmp.x][tmp.y]=0;
    while(!H.isEmpty())
    {
        if(YX!=-1 and YZ !=-1) break;
        tmp=H.pop();
        if(tmp.x==xx and tmp.y==xy)
        {
            if(YX==-1) YX=tmp.start;
            else YX=max(YX,tmp.start);
        }
        if(tmp.x==zx and tmp.y==zy)
        {
            if(YZ==-1) YZ=tmp.start;
            else YZ=min(YZ,tmp.start);
        }
        if(tmp.start==t[tmp.x][tmp.y] )
        {
            for(k=1;k<=min(200,dis[tmp.x][tmp.y]);k++)
            for(i=-k;i<=k;i++)
            {
                j=k-abs(i);
                if(tmp.x+i<N and tmp.x+i>=0 and tmp.y-j>=0)
                {
                    if(t[tmp.x+i][tmp.y-j]==-1 or t[tmp.x+i][tmp.y-j]>tmp.end)
                    {
                        obj.x=tmp.x+i;
                        obj.y=tmp.y-j;
                        obj.start=tmp.end;
                        obj.end=obj.start+cost[obj.x][obj.y];
                        t[obj.x][obj.y]=obj.start;
                        H.push(obj);
                    }
                }
                if(tmp.x+i<N and tmp.x+i>=0 and tmp.y+j<M)
                {
                    if(t[tmp.x+i][tmp.y+j]==-1 or t[tmp.x+i][tmp.y+j]>tmp.end)
                    {
                        obj.x=tmp.x+i;
                        obj.y=tmp.y+j;
                        obj.start=tmp.end;
                        obj.end=obj.start+cost[obj.x][obj.y];
                        t[obj.x][obj.y]=obj.start;
                        H.push(obj);
                    }
                }
            }
        }
    }
    H.clear();
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            t[i][j]=-1;
        }
    }
    tmp.x=zx;
    tmp.y=zy;
    tmp.start=0;
    tmp.end=cost[zx][zy];
    H.push(tmp);
    t[tmp.x][tmp.y]=0;
    while(!H.isEmpty())
    {
        if(ZX!=-1 and ZY !=-1) break;
        tmp=H.pop();
        if(tmp.x==xx and tmp.y==xy)
        {
            if(ZX==-1) ZX=tmp.start;
            else ZX=max(ZX,tmp.start);
        }
        if(tmp.x==yx and tmp.y==yy)
        {
            if(ZY==-1) ZY=tmp.start;
            else ZY=min(ZY,tmp.start);
        }
        if(tmp.start==t[tmp.x][tmp.y] )
        {
            for(k=1;k<=min(200,dis[tmp.x][tmp.y]);k++)
            for(i=-k;i<=k;i++)
            {
                j=k-abs(i);
                if(tmp.x+i<N and tmp.x+i>=0 and tmp.y-j>=0)
                {
                    if(t[tmp.x+i][tmp.y-j]==-1 or t[tmp.x+i][tmp.y-j]>tmp.end)
                    {
                        obj.x=tmp.x+i;
                        obj.y=tmp.y-j;
                        obj.start=tmp.end;
                        obj.end=obj.start+cost[obj.x][obj.y];
                        t[obj.x][obj.y]=obj.start;
                        H.push(obj);
                    }
                }
                if(tmp.x+i<N and tmp.x+i>=0 and tmp.y+j<M)
                {
                    if(t[tmp.x+i][tmp.y+j]==-1 or t[tmp.x+i][tmp.y+j]>tmp.end)
                    {
                        obj.x=tmp.x+i;
                        obj.y=tmp.y+j;
                        obj.start=tmp.end;
                        obj.end=obj.start+cost[obj.x][obj.y];
                        t[obj.x][obj.y]=obj.start;
                        H.push(obj);
                    }
                }
            }
        }
    }
    int X,Y,Z;
    if(YX==-1 or ZX==-1) X=-1;
    else X=YX+ZX;
    if(XY==-1 or ZY==-1) Y=-1;
    else Y=XY+ZY;
    if(XZ==-1 or YZ==-1) Z=-1;
    else Z=XZ+YZ;
    char c;
    int m=-1;
    if(X!=-1){m=X;c='X';}
    if(Y!=-1 and (m==-1 or m>Y)){m=Y;c='Y';}
    if(Z!=-1 and (m==-1 or m>Z)) {m=Z;c='Z';}
    if(m==-1) cout<<"NO";
    else
    {
        cout<<c<<endl<<m;
    }
    return 0;
}
