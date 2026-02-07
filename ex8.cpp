#include <iostream> 
#include<iostream>
#include<cstring>
#include<vector>   
#include<queue>
using namespace std;

#define NMAX 5000
#define MMAX 10000



/*
luogu P5960 差分约束 

两个要点  
    1.把差分约束的不等式组转换成图里面的最短路（一个小技巧）  
    2.求最短路的算法（关键）  

    下面用了SPFA算法 实际上就是bellman-ford的队列优化版本  
    主要思想有几个：
        1.松弛 用松弛的方法逐步求最短路，其实是一个类似dp的过程   
        2.队列优化 用队列优化bellman-ford 不需要重复松弛所有边，而是注意到只有更新过最短路的节点有可能产生新的最短路，用这些可能节点来松弛就好  
        
    具体代码实现里面 邻接表的链表实现，负环的判定 都是有点技巧的 写的有点昏头，值得多练习几次。

*/


struct edge{
    int v, w, next;
};

class graph{
private:
    int head[NMAX+5] = {0},  total[NMAX+5] = {0} , inque[NMAX+5] = {0},  n = 0, m = 0;
    long long dist[NMAX +5];
    edge edges[MMAX+5]; 

    /* data */
public:
    graph(int n);
    ~graph();
    bool addedge(int u, int v, int w){
        if(u>n || v>n ){return false;}
        edges[++m] = {v, w, head[u]};
        head[u] = m;
        return true;
    }

    bool spfa(int u){
        memset(dist, 63, sizeof(dist));
        memset(total, 0, sizeof(total));
        memset(inque, 0, sizeof(inque));
        queue<int> q;
        dist[u] = 0; inque[u] = 1,total[u] = 1;
        q.push(u);


        while(!q.empty()){        //lets relax the distance
            edge cur;
            int mid = q.front();
            inque[mid] = 0;
            q.pop();
            for(int i = head[mid]; i; i = edges[i].next){
                cur = edges[i];
                if(cur.w + dist[mid] < dist[cur.v]){  // u->mid ->cur.v is shorter than dist(u,v)
                    dist[cur.v] = dist[mid] + cur.w;
                    if(inque[cur.v] == 0){
                        q.push(cur.v);
                        inque[cur.v] = 1;
                        if((++total[cur.v]) >= n){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    long long * getdist(void){
        return dist;
    }


};

graph::graph(int n)
{
    this->n = n;
}

graph::~graph()
{
}


int main(void){
    int n, m;
    cin >> n >> m;
    graph g = graph(n+1);
    for (int i = 2; i <= n+1; i++){
        g.addedge(1,i,0);
    }
    for (int i = 1; i <= m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        g.addedge(u+1, v+1, w);
    }
    if (!g.spfa(1)){
        cout << "NO" << endl;
    }
    else
        for (int i = 1; i <= n; i++) cout << g.getdist()[i+1] << ' ';
    return 0;
}