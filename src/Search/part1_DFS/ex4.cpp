/*
    P5440 【XR-2】奇迹

    很烦人的搜索题，没有一点剪枝的dfs无法通过最后三个测试点，加一点月份日期判断剪枝
    
    剪枝前：
    1
    --------
    55157
    time: 19351.5 ms
    剪枝后：
    1
    --------
    55157
    time: 1895.47 ms

    依旧无法通过第九个测试点，只能从素数判断这边下手。
*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

bool isPrime(int);
bool isDate(string);
void dfs(string ,int);

int ans;
int main(void) {
    int t;
    string str;
    
    //clock_t start = clock();
    cin >> t;
    while(t--) {
        cin >> str;
        ans = 0;
        dfs(str, 7);
        cout << ans << endl;
    }
    /*
    clock_t end = clock();
    cout << "time: "
         << (double)(end - start) / CLOCKS_PER_SEC * 1000
         << " ms" << endl;
    */
    return 0;
}

bool isPrime(int n) {
    if(n == 1) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;
    for(int i = 3; i*i <= n; i += 2) {
        if(n%i == 0) return false;
    }
    return true;
}

bool isDate(string s) {
    int year, month, day;
    year = stoi(s.substr(0,4));
    month = stoi(s.substr(4,2));
    day = stoi(s.substr(6,2));

    if(month < 1 || month > 12) return false;
    if(month == 4 || month == 6 || month == 9 || month == 11) {
        if(day >= 1 && day <= 30) return true;
    } else if(month == 2) {
        if((year%4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if(day >= 1 && day <= 29) return true;
        } else {
            if(day >= 1 && day <= 28) return true;
        }
    } else {
        if(day >= 1 && day <= 31) return true;
    }

    return false;
}

void dfs(string s, int pos) {
    //简单剪枝
    if(pos == 5){
        int d = stoi(s.substr(6,2));
        if(d < 1 || d > 31) return;
    }
    if(pos == 3){
        int m = stoi(s.substr(4,2));
        if(m < 1 || m > 12) return;
    }
    if(pos == -1) {
        int full = stoi(s);
        int md   = stoi(s.substr(4,4));
        int day  = stoi(s.substr(6,2));
        if(isDate(s) && isPrime(full) && isPrime(md) && isPrime(day)){
            if(stoi(s.substr(0,4)) != 0) //很坑人，题目限定了年份不能为0找半天了
            ans++;
        }
        return;
    }

    if(s[pos] == '-'){
        for(int i = 0; i <= 9; i++) {
            s[pos] = i+'0';
            dfs(s, pos-1);
        }
    } else {
        dfs(s, pos-1);
    }

}