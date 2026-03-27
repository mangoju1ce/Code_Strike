#include <bits/stdc++.h>
using namespace std;

const int MAX = 3000005;

struct Interval {
    int x, y;
};

bool cmp(Interval a, Interval b) {
    return a.y < b.y;
}

Interval intervals[MAX];
int dp[MAX];        // dp[i]: 以 i 结尾的最优
int pre[MAX];       // pre[i]: 0~i 的最大值

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> intervals[i].x >> intervals[i].y;
    }

    sort(intervals, intervals + n, cmp);

    int idx = 0;
    int max_y = 0;

    for(int i = 0; i < n; i++) {
        int x = intervals[i].x;
        int y = intervals[i].y;

        // 先把 pre 填到 y
        while(idx < y) {
            pre[idx] = (idx == 0 ? dp[0] : max(pre[idx-1], dp[idx]));
            idx++;
        }

        int best = (x > 0 ? pre[x-1] : 0);

        dp[y] = max(dp[y], best + (y - x + 1));

        max_y = max(max_y, y);
    }

    // 最后补全 pre
    while(idx <= max_y) {
        pre[idx] = (idx == 0 ? dp[0] : max(pre[idx-1], dp[idx]));
        idx++;
    }

    cout << pre[max_y];

    return 0;
}