/*
    P1216 [IOI 1994 / USACO1.5] 数字三角形 Number Triangles
    从下往上推即可, dp表达式a[i][j] += max(a[i+1][j], a[i+1][j+1]);
*/
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int a[MAX][MAX];
int main(void) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = n-1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            a[i][j] += max(a[i+1][j], a[i+1][j+1]);
        }
    }
    cout << a[1][1];
    return 0; 
}