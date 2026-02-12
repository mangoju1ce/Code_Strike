/*
    P3599 Koishi Loves Construction
    构造一个1~n的数列，使得前缀和/积满足新数列new[i] = sum[i] mod n元素不重复

    输入：X = 1、2其中1表前缀和，2表前缀积，T表示测试组数

    对于前缀和数组，首先数字n只能放在第一位，若a[i] = n(i != 1),则会出现矛盾
    sum[i] mod n == sum[i-1] mod n; 故而a[1]=sum[1] mod n = 0是确定的，那么考虑sum[n] = n*(n+1)/2
    当n为奇数时，sum[n] mod n = 0 不符合题意；（特例是1，n = 1时成立）
    当n为偶数时，构造取模后的数列为交错型 0，1，-1，2，-2，...n-1, -(n-1)
    对应数列为 n，1，n-2，3，n-4，5，n-6，即遍历i取0~n-1，当i为偶数时，a[i] = n-i,奇数时，a[i] = i
    
    对于前缀积数组，首先数字n只能放在最后一位，另外考虑一个和数n = p*q，由于p，q < n，故一定不成立
    于是n只能取质数，但这里存在特例1，4，其中4 = 2*2也是特例
    对于质数情况，对于sum[i] = (a1*a2*...ai)mod n有递推式sum[i] = (sum[i-1]*ai) mod n
    这里考虑sum[i] = i,即i = ((i-1)*ai) mod n,则a[i] = i * (i-1)^(-1) mod n 其中(i-1)^(-1)表示
    在模n的情况下i-1的逆元，对于以此求解1~n在模n（其中n为质数）条件下的逆元
    记在模n条件下i的逆元为 C[i] = ( n - n/i * C[n mod i] ) mod n，可以简单证明


    7~10 未通过
*/
#include <iostream>
#define MAX 100005

using namespace std;

void solve1(int);
void solve2(int);
bool isPrime(int);

int c[MAX];
int main(void) {
    int x , t, n;
    cin >> x >> t;

    if(x == 1) {
        for(int i = 0; i < t; i++) {
            cin >> n;
            solve1(n);
        }
    }
    if(x == 2) {
        for(int i = 0; i < t; i++) {
            cin >> n;
            solve2(n);
        }
    }
    return 0;
}

void solve1(int n) {
    if(n == 1) {
        cout << 2 << " " << 1 << endl;
        return ;
    }
    if(n % 2 == 1) {
        cout << 0 << endl;
        return ;
    }

    cout << 2 << " ";
    for(int j = 0; j < n; j++) {
        if(j % 2 == 0) cout << n-j << " ";
        else cout << j << " ";
    }
    cout << endl;
}

void solve2(int n) {
    if(n == 1) {
        cout << 2 << " " << 1 << endl;
        return ;
    }
    if(n == 4) {
        cout << 2 << " "<< 1 << " " << 3 << " " << 2 << " " << 4 << endl;
        return ;
    }
    if(!isPrime(n)) {
        cout << 0 << endl;
        return ;
    }

    c[0] = 1;
    c[1] = 1;
    for(int j = 2; j < n; j++) {
        c[j] = (n - 1LL*(n/j)*c[n%j]%n) % n;//这个位置在数字比较大的时候可能出现乘积爆了int
        c[j] = (c[j] + n) % n;//防止负数
    }

    cout << 2 << " " << 1 << " ";
    for(int j = 2; j < n; j++) {
        cout << (1LL *c[j-1]*j)%n << " ";//这里同理
    }
    cout << n << endl;
}

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if (n % 2 == 0) return false;
    for(int i = 3; i*i <= n; i+=2) {
        if(!(n%i)) return false;
    }
    return true;
}