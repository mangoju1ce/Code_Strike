/*
    洛谷p8300 inspector
    题目冗长，概括下来可以分为输入和询问两部分，常规思路每次输入时记录，同时记录每个位置是否存在公司
    每次询问从[a,b]遍历存款最多的公司，并给出相应所需输出。这里需要注意，题目没给a，b的大小关系，可能
    存在a > b的情况，在本题种的意思相当于区间[b,a]，只需将a，b调换即可。该思路的时间复杂度为O(m*n)
    常规思路最后三个测试点TLE。

    对于查询时间T时某公司的余额 y = Z*(T-t)+S，其中t表示该公司进入的时间，做个变换得y = Z*T+S-Z*t
    令Z = k，S-Z*t = b，y = kx+b，则所求即在规定区间[a,b]内的直线集合中，取x = T时的最大值。
    对于多条直线，里面是可能存在无用直线的，即无论x取何值时，取最大值的直线都不是它
    考虑三条直线，L1:y = x + 10, L2: y = 2x + 6, L3: y = 3x;作图可知当x<3时，直线L1取最大值，当
    x>3时直线L3取最大值，此时发现L2即为无用直线，是可以不录入的。
    下面推广到一般情况：L1: y = k1*x+b1, L2: y = k2*x+b2, L3: y = k3*x+b3，其中k1<k2<k3,
    则L1与L2交点，x1 = (b1-b2)/(k2-k1), L2与L3交点，x2 = (b2-b3)/(k3-k2)，当x1>x2时，L2是无用的
    （画图很容易看出，有待更严谨的数学证明）
    当要维护大小大于3的直线集合时，比较简单的思路是将直线按斜率从小到大排序，当录入一条直线时，向左更新
    到无法删除再向右更新到无法删除即可。会发现留下的直线对于取最大值的”统治区间“是有序的（从小到大）
    查询环节使用二分查找即可，而对于该题有区间[a,b]的限定，所以如果全局进行直线集合维护的话，可能存在
    找到的直线不在区间范围内。所以需要对区间[1,n]进行分块处理。块大小设置为sqrt(n)，每个块维护一组直线
    集合，当要查找区间[a,b]范围内最大值时，取两边和中间整块的最大值即可。
*/
#include <stdio.h>
#include <stdlib.h>
#define max_size 100005
#define block_size 320

typedef struct line{
    int k, b, num;
}Line;
Line lines[max_size/block_size + 5][block_size + 5];

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXK 100005  

typedef struct company{
    int day;
    int profit;
    int balance;
} Company;

int flg[MAXK];
int read();
int main(void) {
    int N = read(), M = read();
    Company *companys = (Company*)calloc(MAXK, sizeof(Company));
    memset(flg, 0, sizeof(flg));

    int f, t, k, z, s, a, b;

    while (M--) {
        f = read();
        if (f == 1) {
            t = read();
            k = read();
            z = read();
            s = read();
            if (k >= 0 && k < MAXK) {
                flg[k] = 1;
                companys[k].day = t;
                companys[k].profit = z;
                companys[k].balance = s;
            }

        } else {
            t = read();
            a = read();
            b = read();
            if (a > b) { int tmp = a; a = b; b = tmp; }
            if (b < 0 || a >= MAXK) {
                printf("nema\n");
                continue;
            }
            if (a < 0) a = 0;
            if (b >= MAXK) b = MAXK - 1;

            long long maxProfit = -1;  // 初始为 -1 代表没找到
            long long best = 0;
            for (int i = a; i <= b; i++) {
                if (!flg[i]) continue;
                long long val = (long long)(t - companys[i].day)*companys[i].profit+companys[i].balance;
                if (maxProfit == -1 || val > best) {
                    best = val;
                    maxProfit = val;
                }
            }

            if (maxProfit == -1) {
                printf("nema\n");
            } else {
                printf("%lld\n", best);
            }
        }
    }

    free(companys);
    return 0;
}

int read() {
    int x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(ch>='0'&&ch<='9'){
        x = x << 1 + x << 3 + ch ^ 48;
        //x = x * 10 + ch -'0';其中48是'0'，0x30；作用相当于ch-'0'
        ch = getchar();
    }
    return x * f;
}
*/