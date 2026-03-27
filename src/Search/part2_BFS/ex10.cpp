/*
    P1126 机器人搬重物

    这题有方向，那么答案就应该用三维数组存储，每次出队一个点，以此左转右转和前进
    注意：1、方向别弄错，题目中给出了坐标系
         2、注意机器人是个小球，代表着边界是去不了的！
*/
#include <iostream> 
#include <climits>
#include <queue>
#define MAX 55

using namespace std;

struct Node {
    int x, y, orientation;
};

void BFS(int ,int ,int);

int n, m;
int obstacle[MAX][MAX], cost[MAX][MAX][4];
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

int main(void) {
    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        obstacle[i][0] = 1;
        obstacle[i][m] = 1;
    }
    for(int j = 0; j <= m; j++) {
        obstacle[0][j] = 1;
        obstacle[n][j] = 1;
    }

    int t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> t;
            if(t == 1) {
                obstacle[i-1][j-1] = 1;
                obstacle[i-1][j] = 1;
                obstacle[i][j-1] = 1;
                obstacle[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i <= n; i++) 
        for(int j = 0; j <= m; j++) 
            for(int k = 0; k <= 3; k++)
                cost[i][j][k] = INT_MAX;

    int x, y, orientation, end_x, end_y;
    cin >> x >> y >> end_x >> end_y;
    char ch;
    cin >> ch;
    switch(ch) {
        case 'N':
            orientation = 0;
            break;
        case 'E':
            orientation = 1;
            break;
        case 'S':
            orientation = 2;
            break;
        case 'W':
            orientation = 3;
            break;
    }
    BFS(x, y, orientation);

    if(obstacle[end_x][end_y]) {
        cout << -1;
    }
    else {
        int ans = INT_MAX;
        for(int i = 0; i < 4; i++) {
            ans = min(ans, cost[end_x][end_y][i]);
        }
        if(ans == INT_MAX) cout << -1;
        else cout << ans;
    }
    return 0;
}

void BFS(int x, int y, int orientation) {
    queue<Node> q;
    q.push({x,y,orientation});
    cost[x][y][orientation] = 0;

    while(!q.empty()) {
        Node node = q.front();
        q.pop();
        int x1 = node.x, y1 = node.y, ori = node.orientation;

        int new_ori = 0;
        //左转
        new_ori = (ori+3)%4;
        if(cost[x1][y1][new_ori] == INT_MAX) {
            q.push({x1,y1,new_ori});
            cost[x1][y1][new_ori] = cost[x1][y1][ori] + 1; 
        } 
        //右转
        new_ori = (ori+1)%4;
        if(cost[x1][y1][new_ori] == INT_MAX) {
            q.push({x1,y1,new_ori});
            cost[x1][y1][new_ori] = cost[x1][y1][ori] + 1; 
        } 

        for(int i = 1; i <= 3; i++) {
            int x2, y2;
            x2 = x1 + dx[ori]*i;
            y2 = y1 + dy[ori]*i;
            
            if(x2 <= 0 || x2 >= n || y2 <= 0 || y2 >= m || obstacle[x2][y2]) break;
            if(cost[x2][y2][ori] == INT_MAX) {
                q.push({x2,y2,ori});
                cost[x2][y2][ori] = cost[x1][y1][ori] + 1; 
            } 
        }
    }
}