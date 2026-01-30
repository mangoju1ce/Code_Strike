/*
    洛谷p1068，双重排序，重点在cmp的撰写，比较简单
*/

#include <iostream>
#include <algorithm>
#define max 5005
using namespace std;

typedef struct node{
    int num;
    int score;
}Node;

bool cmp(Node x, Node y){
    if(x.score != y.score) return x.score > y.score;
    return x.num < y.num;
}

Node nodes[max];
int cnt[105];
int main(void) {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> nodes[i].num >> nodes[i].score;
    }
    sort(nodes, nodes+n, cmp);

    int k = (int)(m*1.5), score_line;
    score_line = nodes[k-1].score;

    int total = k;
    while(total < n && nodes[total].score == score_line){
        total++;
    }

    cout << score_line << " " << total << endl;
    for(int i = 0; i < total; i++) {
        cout << nodes[i].num << " " << nodes[i].score << endl;
    }
}