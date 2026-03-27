/*
    P1219 [USACO1.5] 八皇后 Checker Challenge

    DFS+回溯；每次在一行中选择满足条件的点，这里已经满足了行要求，只需满足列要求和斜要求，其中使用
    数组column来记录每一行选择的列号，yPlusx与ySubx数组来记录直线，每次检查是否存在满足条件的点，
    若存在，则选择，并继续选择下一行的点，直到n行选满；若不存在，则回溯；
*/
#include <iostream>
#define MAX 20

using namespace std;
void Queen_DFS(int);
bool isFit(int, int);

int column[MAX], yPlusx[MAX], ySubx[MAX];
int n, ans;
int main(void) {
    cin >> n;

    Queen_DFS(1);
    cout << ans;
    return 0;
}

bool isFit(int x, int  y) {
    for(int i = 1; i < x; i++) {
        if(column[i] == y) return false;
        if(yPlusx[i] == x+y) return false;
        if(ySubx[i] == y-x) return false;
    }
    return true;
}

void Queen_DFS(int x) {
    if(x == n+1) {
        ans++;
        if(ans <= 3) {
            for(int i = 1; i <= n; i++) cout << column[i] << " ";
            cout << endl;
        }
        return;
    }

    for(int y = 1; y <= n; y++) {
        if(isFit(x,y)) {
            column[x] = y;
            yPlusx[x] = y+x;
            ySubx[x] = y-x;
            Queen_DFS(x+1);
        }
    }

    column[x-1] = 0;
    yPlusx[x-1] = 0;
    ySubx[x-1] = 0;
    return;
}
