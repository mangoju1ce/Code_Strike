/*
    p1314 聪明的检察官
    寻找最好的w，显然二分答案即可。若每次对每个w遍历m个区间，时间复杂度O(m*n*log(maxWeight))
    显然最坏情况下时间复杂度过大，考虑采用前缀和数组优化，对于每一个选中的w在[l,r]区间内质量
    大于w的个数可以用cnt[r]-cnt[l-1]，价格value[r]-value[l-1],那么对于每一个选中的w，就进行一个
    前缀和数组求解，和一次m个区间的询问，故时间复杂度为O(log(maxWeight)*(m+n))
*/
#include <iostream>
#include <climits>
#define MAX 200005
#define MAXW 1000000
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
#define llabs(a) ((a>=0)?(a):(-(a)))//这个位置：后面的-a要多重括号(-(a))否则带入sum-s会造成问题

using namespace std;

//前缀和数组
long long cnt[MAX], value[MAX];
int l[MAX], r[MAX], w[MAX], v[MAX];
int main(void) {
    int n, m;
    long long s;
    cin >> n >> m >> s;

    int maxWeight = 0, minWeight = MAXW;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        maxWeight = max(w[i], maxWeight);
        minWeight = min(w[i], minWeight);
    }

    for(int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
    }

    int left = minWeight, right = maxWeight;
    long long ans = LLONG_MAX;
    while(left <= right) {
        int mid = (left+right)/2;

        //计算前缀和数组
        cnt[0] = 0;
        value[0] = 0;
        for(int i = 1; i <= n; i++) {
            cnt[i] = cnt[i-1];
            value[i] = value[i-1];

            if(w[i] >= mid){
                cnt[i] += 1;
                value[i] += v[i];
            }
        }
        
        long long sum = 0;
        for(int i = 0; i < m; i++) {
            long long c = cnt[r[i]] - cnt[l[i]-1];
            long long val = value[r[i]] - value[l[i]-1];
            sum += c * val;
        }

        long long dif = llabs(sum-s);
        ans = min(dif, ans);

        if(sum <= s) right = mid-1;
        else left = mid+1;
    }

    cout << ans;
    return 0;
}
