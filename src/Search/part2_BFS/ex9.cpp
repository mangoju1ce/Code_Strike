/*
    P1032 [NOIP 2002 提高组] 字串变换（疑似错题)

    注意1、每次字符变换可能包括多个变换，例如abcabc使用变换abc--d，可能变成dabc、dd
    2、最后一个测试点应该包含了a-b与b-a的变换，所以每次入队都要记录，防止反复入队的重复
*/
#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

bool BFS();
string s1, s2, a[10], b[10];
int num;
int main(void) {
    cin >> s1 >> s2;

    string x, y;
    while(cin >> x >> y) {
        a[num] = x;
        b[num] = y;
        num++;
    }

    if(!BFS()) cout << "NO ANSWER!";
}

bool BFS() {
    queue<pair<string, int>> q;
    set<string> vis;

    q.push({s1,0});
    vis.insert(s1);
    while(!q.empty()) {
        pair<string,int> p = q.front();
        q.pop();

        string s = p.first;
        int cnt = p.second;

        if(cnt > 10) continue;
    
        if(s == s2) {
            cout << cnt;
            return true;
        }

        for(int i = 0; i < num; i++) {
            int pos = s.find(a[i]), step = 1;
            while(pos != string::npos){
                string str = s.substr(0, pos) + b[i] + s.substr(pos+a[i].size());
                if(!vis.count(str)){
                    vis.insert(str);
                    q.push({str, cnt+1});
                }
                pos = s.find(a[i], pos+1);
            }
        }

    }
    return false;
}