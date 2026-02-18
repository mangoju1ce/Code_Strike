/*
    P3956 [NOIP 2017 普及组] 棋盘

    基础移动：上下左右四个方位
    魔法移动：右上，右下，左上，左下，右二，左二，上二，下二

    BFS搜索，每次考虑十二个方位，如果没有颜色或者出界，则代表不能到达
    flg数组存储当前位置是否在队列中，cost数组存储到达当前位置的最小代价，初始化cost INT_MAX
    每次出队一个点，注意出队后要令flg为0，对于该点能到达的每个点，每次更新cost，若有更新，且
    该点当时不在队列中，则入队。
    另外要注意可能存在坐标(m,m)位置没有颜色的情况，此时要考虑它的上面和左边是否有颜色

    几次错误的注意点：
    1、该题如果使用BFS来搜索要注意，每个点并非只入队一次，若一个点之前入队了，之后又因其他点
    更新了cost，那么该点应该重新入队以更新该点能到达的其他点
    2、左边(m,m)无颜色时，考虑上左两点的判定应该使用cost数组而不是a数组，如上左两点有颜色但
    无法到达，即从来没有更新过cost，那么cost就是INT_MAX，如果使用a数组来判定，可能导致输出了
    INT_MAX+2
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
        if(cost[m][m-1] != INT_MAX || cost[m-1][m] != INT_MAX) {
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

    flg[x][y] = 1;  // 表示在队列中

    while(front != rear) {
        int x1 = qx[front], y1 = qy[front];
        front++;

        flg[x1][y1] = 0;   // 出队

        for(int i = 0; i < 12; i++) {

            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i];

            if(x2 < 1 || x2 > m || y2 < 1 || y2 > m) continue;
            if(a[x2][y2] == 0) continue;

            int w;

            if(i < 4) {  // 普通走
                if(a[x1][y1] != a[x2][y2]) w = 1;
                else w = 0;
            } else {     // 魔法走
                if(a[x1][y1] != a[x2][y2]) w = 3;
                else w = 2;
            }

            if(cost[x2][y2] > cost[x1][y1] + w) {

                cost[x2][y2] = cost[x1][y1] + w;

                if(!flg[x2][y2]) {
                    qx[rear] = x2;
                    qy[rear] = y2;
                    rear++;
                    flg[x2][y2] = 1;
                }
            }
        }
    }
}
