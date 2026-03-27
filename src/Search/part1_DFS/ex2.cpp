/*
    P1019 [NOIP 2000 提高组] 单词接龙（疑似错题）

    这里尤其是第二个测试点
    2
    abababab
    abababc
    a

    题目中模糊不清，在题目描述末尾字样“另外相邻的两部分不能存在包含关系，例如 at 和 atide 间不能相连。”
    如果两个字符串相等算不算包含关系呢，在这里第二测试点里是不算包含关系的。

    第二测试点的最终答案是19，即最长龙是abababababababababc(第一个字符串开头，后接第一个字符串
    且删除重复部分"ab",后街第二个字符串，删除重复部分"ab"，所以这里还需注意合并字符串函数，并非
    找到最大前字符串末尾后字符串开头重复部分，而是要找到重复且最小)

    下面的代码可以通过题目全部测试点
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void word_DFS(string );
string mergeString(string ,string );

const int MAX = 20;
string s[MAX];
int ans, n, count_use[MAX];
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s, s+n);
    char ch;
    cin >> ch;
    for(int i = 0; i < n; i++) {
        if(s[i][0] == ch) {
            count_use[i]++;
            word_DFS(s[i]);
            count_use[i]--;
        }
    }
    cout << ans;
    return 0;
}

string mergeString(string a, string b) {
    int size_a = a.size(), size_b = b.size();
    int limit = min(size_a, size_b), rep_k = 0;
    
    for(int k = 1; k < limit; k++) {
        if(a.substr(size_a-k, k) == b.substr(0, k)){
            rep_k = k;
            break;//一旦找到重复，就break，保证删去部分最小
        }
    }

    return a+b.substr(rep_k);
}

void word_DFS(string str) {
    ans = max(ans, (int)str.size());

    char ch = str[str.size()-1];
    for(int i = 0; i < n; i++) {
        if(count_use[i] < 2) {
            string merged = mergeString(str, s[i]);
            
            if(merged.size() < str.size()+s[i].size())//用来判断是否存在重复部分
            {
                //cout << merged << endl;
                count_use[i]++;
                word_DFS(merged);
                count_use[i]--;
            } 
        }
    }

}