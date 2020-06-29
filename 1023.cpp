#include<bits/stdc++.h>
#define rep(i,b,e) for(register int i=(b);i<(e);++i)
#define dep(i,b,e) for(register int i=(b);i>=(e);--i)
#define LL long long
#define inf 0x7fffffff
#define il inline

using namespace std;

struct edge{
    int from,w;
    edge(int f,int w):from(f),w(w){};
};
const int N=500+3;
int T,M,E,n,u,v,w,s,t;
int cost[N];
vector<edge> g[N];
int f[N][101];
short inq[N];
il int add(const int &a,const int &b){
    if(a==inf||b==inf) return inf;
    else return a+b;
}
int dp(int i,int j){
    if(f[i][j]>=0) return f[i][j];
    f[i][j]=inf;
    if(j<cost[i]) return f[i][j];
    if(i==s){
        f[i][j]=0;return f[i][j];
    }
    inq[i]=1;
    for(edge &e:g[i]){
        if(inq[e.from]) continue;
        f[i][j]=min(f[i][j],add(dp(e.from,j-cost[i]),e.w));
    }
    inq[i]=0;return f[i][j];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>E>>s>>t>>M;
        rep(i,1,n+1) cin>>cost[i];cost[s]=0;
        while(E--){
            cin>>u>>v>>w;
            g[v].push_back(edge(u,w));
            g[u].push_back(edge(v,w));
        }
        memset(inq,0,sizeof(inq));
        memset(f,-1,sizeof(f));
        if(dp(t,M)<inf) cout<<dp(t,M)<<endl;
        else cout<<-1<<endl;
        rep(i,1,n+1) g[i].clear();
    }
    //system("pause");
    return 0;
}
