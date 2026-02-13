/*
    洛谷p1309，常规思路，每轮次进行一次排序，这里编号从1开始，要注意使用sort时也从1开始！
    时间复杂度：O(r * nlogn) ,最后三个测试点全部TLE
    
    使用归并算法进行优化，初始时用sort排序，每次胜者组和败者组依旧按序，只需归并即可。
    时间复杂度：O(r * n + nlogn)，即O(min{r*n , nlogn})
*/

#include <iostream>
#include <algorithm>
#define max 200005
using namespace std;

struct Node {
    int num;
    int score;
    int power;
};

bool cmp(Node x, Node y) {
    if(x.score != y.score) return x.score > y.score;
    return x.num < y.num;
}

Node nodes[max], win[max/2], lose[max/2];
int main(void) {
    int n, r, q;
    cin >> n >> r >> q;

    for(int i = 1; i <= 2*n; i++) {
        nodes[i].num = i;
        cin >> nodes[i].score;
    }
    for(int i = 1; i <= 2*n; i++) {
        cin >> nodes[i].power;
    }

    sort(nodes+1, nodes+2*n+1, cmp);
    for(int i = 0; i < r; i++) {
        int size1 = 0, size2 = 0;
        for(int j = 1; j < 2*n; j += 2) {
            if(nodes[j].power > nodes[j+1].power){
                nodes[j].score++;
                win[size1++] = nodes[j];
                lose[size2++] = nodes[j+1];
            } else{
                nodes[j+1].score++;
                win[size1++] = nodes[j+1];
                lose[size2++] = nodes[j];
            }
        }
        
        int index1 = 0, index2 = 0, index = 1;
        while(index1 < size1 && index2 < size2){
            if(win[index1].score > lose[index2].score ||
            win[index1].score == lose[index2].score && win[index1].num < lose[index2].num){
                nodes[index++] = win[index1++];        
            } else {
                nodes[index++] = lose[index2++];
            }
        }
        while(index1 < size1) {
            nodes[index++] = win[index1++];
        }
        while(index2 < size2) {
            nodes[index++] = lose[index2++];
        }
    }
    cout << nodes[q].num;
}