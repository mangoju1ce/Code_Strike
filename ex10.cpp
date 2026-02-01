/*
    p1902 刺杀大使
    求最大伤害的最小值，二分答案+bfs/dfs图搜索，洛谷第10测试点，bfs 193ms，dfs 157ms
*/
#include <iostream>
#include <cstring>
#define MAX 1005
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
using namespace std;

bool bfs_check(int);
bool dfs_check(int, int, int);

int a[MAX][MAX], vis[MAX][MAX], n, m;
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
int main(void) {
    cin >> n >> m;

    int maxCost = 0, minCost = 1000;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            maxCost = max(a[i][j], maxCost);
            minCost = min(a[i][j], minCost);
        }
    }

    int l = minCost, r = maxCost, ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;
        memset(vis, 0, sizeof(vis));
        if(dfs_check(0, 0, mid)){
            r = mid-1;
            ans = mid;
        } else l = mid+1;
    }

    cout << ans;
    return 0;
}

bool bfs_check(int mid){
    int sx = 0, sy = 0;

    int quene[MAX*MAX][2], front = 0, rear = 0;
    quene[rear][0] = sx;
    quene[rear][1] = sy;
    rear++;
    vis[sx][sy] = 1;

    while(front != rear){
        int x1 = quene[front][0], y1 = quene[front][1];
        front++;

        for(int i = 0; i < 4; i++) {
            int x2 = x1+dx[i], y2 = y1+dy[i];
            if(x2 >= 0 && x2 <= n-1 && y2 >= 0 && y2 <= m-1){
                if(!vis[x2][y2] && a[x2][y2]<=mid){
                    if(x2 == n-1) return true;

                    quene[rear][0] = x2;
                    quene[rear][1] = y2;
                    rear++;
                    vis[x2][y2] = 1;
                }
            }
        }
    }
    return false;
}

bool dfs_check(int x,int y, int mid) {
    if(x == n-1) return true;
    vis[x][y] = 1;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx <= n-1 && ny >= 0 && ny <= m-1) {
            if(!vis[nx][ny] && a[nx][ny] <= mid) {
                if(dfs_check(nx, ny, mid)) return true;
            }
        }
    }
    return false;
}