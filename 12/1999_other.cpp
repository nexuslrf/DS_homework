#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m;
int map[100+5][100+5];
bool vis[100+5][100+5];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1}; 
int dp[6][6]={0};//dp[i][j] 表示 ibox和jbox 的距离 dp[5][i] 表示起点 到i box的距离
struct Point
{
    int x;
    int y;
    int id;
    int step; 
    Point(int i=0,int j =0):x(i),y(j){
        step = 0;
        id = 0; 
    }
};
Point start;//二哥的起点
Point boxes[5];//最多五个宝藏
int path[5];//枚举的线路
int len = 0; //宝藏的个数


void init(){
    cin>>n>>m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin>>map[i][j];
            if(map[i][j]==1){
                boxes[len].x = i;
                boxes[len].y = j;
                path[len] = len;
                len++;
            }
            if(map[i][j]==2){
                start.x = i;
                start.y = j;
                start.id = 2;
                start.step = 0; 
            }
        }
    } 
}


//
int bfs(Point s, Point e){

    queue<Point> q;
    memset(vis,false,sizeof(vis));
    s.step = 0;
    q.push(s);
    while(!q.empty()){
        Point cur = q.front();
        q.pop();
        vis[cur.x][cur.y] = true;
        Point next;
        for (int i = 0; i < 4; ++i)
        {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            if(next.x>=1 and next.x<=n and next.y>=1 and next.y<=m)
            {
                if(vis[next.x][next.y])
                    continue;
                next.id = map[next.x][next.y];
                vis[next.x][next.y] = true;
                if(next.id != -1){
                    next.step = cur.step + 1; 
                    if(next.x == e.x and next.y == e.y)//到达了终点
                        return next.step;
                    q.push(next);
                }
            }
        }

    }
    return -1; //找不到
}


int build(){
    //枚举取宝藏的顺序  从而形成路径 求出最小的一个即可 方案数最多 A55 = 120种
    //求一下C62的dp
    //生成dp
    for (int i = 0; i < len; ++i)
    {
        dp[5][i] = bfs(start,boxes[i]);
        if(dp[5][i]==-1)
            return -1;
    }

    for (int i = 0; i < len; ++i)
    {
        for (int j = i+1; j < len; ++j)
        {
            dp[i][j] = dp[j][i] = bfs(boxes[i],boxes[j]);
            if(dp[i][j]==-1)
                return -1;
        }
    }
    int ans = 1<<30;
    do{
        int dis = dp[5][path[0]];
        for (int i = 1; i < len; ++i)
        {
            dis += dp[path[i]][path[i-1]];
        }
        ans = min(ans,dis);
    }while(next_permutation(path,path+len));
    return ans;
}
int main(int argc, char const *argv[])
{ 
    freopen("1999.in","r",stdin);
    init();
    cout<<build()<<endl; 
    return 0;
}