#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>

using namespace std;
enum {max_number = 110};
const long long inf = numeric_limits<long long>::max();

long long d[max_number];
bool inq[max_number];
int p[max_number];
queue<int> q;
struct Edge {
    int super, sub, flow, cap, cost;

};
vector<Edge> edges_vector;
vector<int> g[max_number];
void add_edge(int super, int sub, int cap, int cost) {
    edges_vector.push_back((Edge){super, sub, 0, cap, cost});
    edges_vector.push_back((Edge){sub, super, 0, 0, -cost});
    int m = edges_vector.size();
    g[super].push_back(m - 2);
    g[sub].push_back(m - 1);
    return;
}
struct MCMF {
    int s, t;
    bool bfs() {
        for (int i = 0; i < max_number; i++) d[i] = inf;
        memset(inq, 0, sizeof(inq));
        q.push(s);
        d[s] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            inq[x] = 0;
            for (int i = 0; i < g[x].size(); i++) {
                Edge e = edges_vector[g[x][i]];
                if (e.cap == e.flow) continue;
                int y = e.sub;
                if (d[y] > d[x] + e.cost) {
                    d[y] = d[x] + e.cost;
                    p[y] = g[x][i];
                    if (!inq[y]) q.push(y);
                    inq[y] = 1;
                }
            }
        }
        if (d[t] == inf) return 0;
        return 1;
    }
    void Mincost(int s, int t) {
        this->s = s;
        this->t = t;
        int flow = 0, f;
        long long cost = 0, tot;
        while (bfs()) {
            f = 100000;
            tot = 0;
            for (int i = t; i != s; i = edges_vector[p[i]].super) {
                Edge e = edges_vector[p[i]];
                f = min(f, e.cap - e.flow);
                tot += e.cost;
            }
            flow += f;
            cost += tot * f;
            for (int i = t; i != s; i = edges_vector[p[i]].super) {
                edges_vector[p[i]].flow += f;
                edges_vector[p[i] ^ 1].flow -= f;
            }
        }
        cout << flow << " " << cost << endl;
        return;
    }
    void init() {
        edges_vector.clear();
        for (int i = 0; i < max_number; i++) {
            g[i].clear();
        }
    }
} F;
int a[52][52];
int main() {
    int T;
    cin >> T;
    while (T--) {
        F.init();
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) cin >> a[i][j];
        int s = 0, t = n + m + 1;
        for (int i = 1; i <= n; i++) add_edge(s, i, 1, 0);
        for (int i = 1; i <= m; i++) add_edge(i + n, t, 1, 0);
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++) {
                int x;
                cin >> x;
                add_edge(i, n + x, 1, a[x][i]);
            }
        }
        F.Mincost(s, t);
    }
}
