#include<iostream>  
#include<vector>
#include<algorithm>

/*
    luogu P2330 
    一道求最小生成树的题目 
    需要
        1.复习一下最小生成树的性质（附在后面) 
        2.熟悉用并查集实现的kruskal算法求MST  

        

给定一个 连通带权无向图
找一个 生成树，使得：

覆盖所有点

边数 = n−1

边权和最小

2️⃣ MST 的重要性质（必考）
🌟 性质 1：切分定理（Cut Property）

把点集分成两部分

跨越这两部分的 最小权边

一定属于某一棵 MST

👉 Kruskal / Prim 的理论基础

🌟 性质 2：环定理（Cycle Property）

在一个环中

最大权边一定不在 MST 中

👉 删除「最差的边」不影响最优性

🌟 性质 3：MST 不一定唯一

如果存在相同权值边

可能有多棵 MST

但最小权值和相同
*/
using namespace std; 

struct Edge{
    int u,v,w;
    bool operator < (const Edge& other) const {
        return w<other.w;
    }
};

class DSU{  // disjoint set union 
private: 
    vector<int> fa, sz;
public: 
    DSU(int n){
        fa.resize(n+1,0);
        sz.resize(n+1,1);
        for(int i=1; i<=n; i++){
            fa[i] = i;
        }
    }


    int find(int x){
        if(fa[x] == x){return x;}
        else{
            return fa[x] = find(fa[x]);
        }
    }

    bool unite(int x, int y){
        x = find(x); y = find(y);
        if(x == y){
            return false;
        }
        else{
            if(sz[x] < sz[y]){swap(x,y);}
            fa[y] = x;
            sz[x] += sz[y];
            return true;
        }

    }

};

int main(void){

    int n, m, u, v, w, s=0, wmax=0; 
    cin>>n>>m;
    vector<Edge> edges(m);
    for(int i=0; i<m; i++){
        cin>>edges[i].u >> edges[i].v >>edges[i].w;
    }
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    for(auto it = edges.begin(); it != edges.end(); it++){
        u = it->u; v = it->v; w = it->w;
        if(dsu.find(u) != dsu.find(v)){
            s++;
            dsu.unite(u, v);
            wmax = max(wmax, w);
        }
    }

    cout<<s<<" "<<wmax;
    

    return 0;

}