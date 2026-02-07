#include<iostream>
#include<cstring>
#include<vector>   
#include<queue>
using namespace std;

#define NMAX 1000
#define MMAX 1000




struct edge{
    int v, w, next;
};

class graph{
private:
    int head[NMAX+5] = {0},  total[NMAX+5] = {0} , inque[NMAX+5] = {0}, dist[NMAX+5], n = 0, m = 0;
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
            for(int i = head[mid]; i; i = cur.next){
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


};

graph::graph(int n)
{
    this->n = n;
}

graph::~graph()
{
}
