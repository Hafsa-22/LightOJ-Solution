#include<bits/stdc++.h>
#define fi(n, m) for(int i=n; i<=m; i++)
#define fd(n, m) for(int i=n; i>=m; i--)
using namespace std;
vector<int>adj[109], cost[109];
int dis[109], n;

struct node{
    int u, w;
    node(int a, int b){
        u=a, w=b;
    }
    bool operator < (const node & p)const{
        return p.w<w;
    }
};

void dijkstra(int s){
    priority_queue<node>pq;
    for(int i=0;i<=n;i++)
    dis[i]=1000001;
    dis[s]=0;
    pq.push(node(s, 0));
    while(!pq.empty()){
        node top=pq.top();
        pq.pop();
        int u=top.u;

        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            int w = cost[u][i];
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.push(node(v, dis[v]));
            }
        }
    }
}

int main(){
    int t, c=1, e, u, v, w;
    cin>>t;
    while(t--){
        cin>>n>>e;
        while(e--){
            cin>>u>>v>>w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        dijkstra(1);
        cout<<"Case "<<c++<<": ";
        if(dis[n]==1000001)
          cout<<"Impossible"<<endl;
        else
            cout<<dis[n]<<endl;
        for(int i=0;i<=n;i++){
            adj[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
