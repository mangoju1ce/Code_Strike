/*
    P1443 马的遍历
*/
#include <iostream>
#define MAX 405

using namespace std;

void BFS(int x, int y);

int flg[MAX][MAX], ans[MAX][MAX];
int n, m;
int dx[8] = {2, 1, 2, 1, -2, -1, -2, -1}, dy[8] = {1, 2, -1, -2, 1, 2, -1, -2};
int qx[MAX*MAX], qy[MAX*MAX];

int main(void) {
    cin >> n >> m;
    int x, y;
    cin >> x >> y;

    BFS(x, y);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(ans[i][j] == 0 && !(i == x && j == y)) cout << -1 << " "; 
            else cout << ans[i][j] << " ";
        }
        cout << endl;
    }
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
        for(int i = 0; i < 8; i++) {
            int x2 = x1 + dx[i], y2 = y1 + dy[i];
            if(x2 < 1 || x2 > n || y2 < 1 || y2 > m) continue;
            if(!flg[x2][y2]){
                qx[rear] = x2;
                qy[rear] = y2;
                rear++;
                flg[x2][y2] = 1;
                ans[x2][y2] = ans[x1][y1] + 1;
            }  
        }
    }
}