/*
    P1514 [NOIP 2010 提高组] 引水入城

    对于第一行每个节点进行DFS或BFS，得到能流向最后一行的索引集合
    注意：若该题有解，即最后一行都可以建造，则这些集合元素最终会是连续的
    另外要注意，每次搜索前要先清空vis数组

    最后就是区间覆盖问题，将区间按照左端点升序排序，cur记录你当前希望覆盖的位置
    找到左端点小于等于cur的区间，更新cur为这些区间里右端点最大值+1，继续贪心去找即可。
*/
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 505

using namespace std;

struct Interval {
    int l, r;
};

void BFS(int, int);
bool cmp(Interval, Interval);

int n, m;
int a[MAX][MAX], flg[MAX], vis[MAX][MAX];
Interval intervals[MAX];
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int main(void) {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= m; i++) {
        intervals[i].l = 1e9;
        intervals[i].r = 0;
    }

    for(int i = 1; i <= m; i++) {
        memset(vis, 0, sizeof(vis));
        BFS(1, i);
    }

    int cnt = 0, flag = 0;
    for(int i = 1; i <= m; i++) {
        if(!flg[i]) {
            flag = 1;
            cnt++;
        }
    }

    if(flag) {
        cout << 0 << endl << cnt;
    } else {
        sort(intervals+1, intervals+m+1, cmp);
        int cur = 1, ans = 0, i = 1;
        while(cur <= m) {
            int max_r = 0;
            while(i <= m) {
                if(intervals[i].l > cur) break;
                max_r = max(max_r, intervals[i].r);
                i++;
            }
            cur = max_r + 1;
            ans++;
        }
        cout << 1 << endl << ans;
    }
    return 0;
}

bool cmp(Interval a, Interval b) {
    return a.l < b.l;
}
void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x,y});
    vis[x][y] = 1;

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int x1 = p.first, y1 = p.second;
        if(x1 == n) {
            flg[y1] = 1;
            intervals[y].l = min(intervals[y].l, y1);
            intervals[y].r = max(intervals[y].r, y1);
        }
        for(int i = 0; i < 4; i++) {
            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i];

            if(x2 < 1 || x2 > n || y2 < 1 || y2 > m) continue;
            if(!vis[x2][y2] && a[x1][y1] > a[x2][y2]) {
                q.push({x2,y2});
                vis[x2][y2] = 1;
            }
        }
    }
}
