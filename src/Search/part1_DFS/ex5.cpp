/*
    P1378 油滴扩展

    N较小，考虑深搜遍历所有的油滴顺序组合，即全排列，注意回溯和更新每个点的最大可扩展半径
*/
#include <iostream>
#include <cmath>
#define MAX 10
#define pi 3.1415926

using namespace std;

struct Point {
    int x, y;
    double r;
};

void DFS(int ,double);
void init();
void update(int);

Point points[MAX];
int used[MAX];
int x, y, x2, y2, n;
double sum_s;
int main(void) {
    cin >> n;
    cin >> x >> y >> x2 >> y2;

    for(int i = 1; i <= n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    init();
    DFS(0, 0);
    cout << (int)(abs((x-x2)*(y-y2)) - sum_s + 0.5);
    return 0;
}

void init() {
    int x_min = min(x,x2), x_max = max(x,x2);
    int y_min = min(y,y2), y_max = max(y,y2);

    for(int i = 1; i <= n; i++) {
        int xr = min(points[i].x-x_min, x_max-points[i].x);
        int yr = min(points[i].y-y_min, y_max-points[i].y);
        points[i].r = min(xr, yr);
    }
}

void update(int index) {
    for(int i = 1; i <= n; i++) {
        if(i != index) {
            int dx = (points[index].x-points[i].x);
            int dy = (points[index].y-points[i].y);
            double d = sqrt(dx*dx + dy*dy);
            double r1 = points[index].r, r2 = points[i].r;
            if(d <= r1) {
                points[i].r = 0;
            } 
            if(d > r1 && d < r1+r2){
                points[i].r = d - r1;
            } 
        }
    }
}

void DFS(int cnt, double ans) {
    if(cnt == n) {
        sum_s = max(sum_s, ans);
        return;
    }
    
    for(int i = 1; i <= n; i++) {
        if(used[i]) continue;

        // 备份半径
        double backup[MAX];
        for(int j = 1; j <= n; j++)
            backup[j] = points[j].r;

        used[i] = 1;
        update(i);
        DFS(cnt+1, ans+pi*points[i].r*points[i].r);

        used[i] = 0;
        // 恢复半径
        for(int j = 1; j <= n; j++)
            points[j].r = backup[j];
    }
}