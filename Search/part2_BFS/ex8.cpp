/*
    P3956 [NOIP 2017 普及组] 棋盘
*/
#include <iostream>
#include <climits>
#include <cstring>
#define MAX 105

using namespace std;

void BFS(int x, int y);

int a[MAX][MAX], flg[MAX][MAX], cost[MAX][MAX];
int dx[12] = {1,-1,0,0,1,1,-1,-1,2,0,-2,0};
int dy[12] = {0,0,1,-1,1,-1,1,-1,0,2,0,-2};
int qx[MAX*MAX], qy[MAX*MAX];
int n, m;

int main(void) {
    cin >> m >> n;
    int x, y, c;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> c;
        a[x][y] = c+1; //1表示红，2表黄，0表无色
    }

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            cost[i][j] = INT_MAX;
    cost[1][1] = 0;
    BFS(1,1);

    if(cost[m][m] == INT_MAX) {
        if(cost[m][m-1] || cost[m-1][m]) {
            cout << min(cost[m][m-1], cost[m-1][m])+2;
        }
        else cout << -1;
    }
    else cout << cost[m][m];
    return 0;
}

void BFS(int x, int y) {
    int front = 0, rear = 0;
    qx[rear] = x;
    qy[rear] = y;
    rear++;
    flg[x][y] = 1;

    while(front != rear) {
        int x1 = qx[front], y1 = qy[front];
        front++;

        for(int i = 0; i < 4; i++) {
            int x2 = x1 + dx[i], y2 = y1 + dy[i];
            if(x2 < 1 || x2 > m || y2 < 1 || y2 > m || a[x2][y2] == 0) continue;
            
            if(!flg[x2][y2]) {
                qx[rear] = x2;
                qy[rear] = y2;
                rear++;
                flg[x2][y2] = 1;
            }
            if(a[x1][y1] != a[x2][y2]) 
                cost[x2][y2] = min(cost[x2][y2], cost[x1][y1]+1);
            else
                cost[x2][y2] = min(cost[x2][y2], cost[x1][y1]);
        }

        for(int i = 4; i < 12; i++) {
            int x2 = x1 + dx[i], y2 = y1 + dy[i];
            if(x2 < 1 || x2 > m || y2 < 1 || y2 > m || a[x2][y2] == 0) continue;

            if(!flg[x2][y2]) {
                qx[rear] = x2;
                qy[rear] = y2;
                rear++;
                flg[x2][y2] = 1;
            }
            if(a[x1][y1] != a[x2][y2]) 
                cost[x2][y2] = min(cost[x2][y2], cost[x1][y1]+3);
            else
                cost[x2][y2] = min(cost[x2][y2], cost[x1][y1]+2);
        }
    }
}