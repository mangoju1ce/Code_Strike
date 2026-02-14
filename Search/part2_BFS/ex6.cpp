/*
    P1162 填涂颜色
*/
#include <iostream>
#include <cstring>
#define MAX 35
using namespace std;

void inLoop_BFS(int x, int y);

int a[MAX][MAX], n;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int quene_x[1005], quene_y[1005];
int front, rear;

int main(void) {
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    //边界线上的0一定不在闭合圈内
    for(int i = 2; i <= n-1; i++) {
        for(int j = 2; j <= n-1; j++) {
            if(a[i][j] == 0) {
                inLoop_BFS(i,j);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void inLoop_BFS(int x, int y) {
    memset(quene_x, 0, sizeof(quene_x));
    memset(quene_y, 0, sizeof(quene_y));
    front = rear = 0;

    int vis[MAX][MAX] = {0};
    quene_x[rear] = x;
    quene_y[rear] = y;
    rear++;
    vis[x][y] = 1;

    while(front != rear) {
        int x1 = quene_x[front], y1 = quene_y[front];
        front++;
        for(int i = 0; i < 4; i++) {
            int x2 = x1 + dx[i], y2 = y1 + dy[i];

            if(x2 == 1 || x2 == n || y2 == 1 || y2 == n) {
                if(a[x2][y2] == 0) return;
                else continue;
            }

            if(!vis[x2][y2] && a[x2][y2] == 0) {
                vis[x2][y2] = 1;
                quene_x[rear] = x2;
                quene_y[rear] = y2;
                rear++;
            }
        }
    }

    if(front == rear) {
        for(int i = 0; i < rear; i++) {
            a[quene_x[i]][quene_y[i]] = 2;
        }
    }
}
