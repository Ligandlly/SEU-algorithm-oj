#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <list>
using namespace std;

enum { max_vertex_number = 502 };

struct Vertex {
    bool visited;
    list<pair<Vertex *, int> > adjacent;
    int dist;
    Vertex() {
        visited = false;
        dist = -1;
    }
};

Vertex graph[max_vertex_number];

bool cmp(Vertex &v1, Vertex &v2) {
    if (v2.dist == -1) {
        return true;
    }
    if (v1.dist == -1) {
        return false;
    }
    if (v1.dist < v2.dist) {
        return true;
    }
    return false;
}

int main() {
    int groupNumber = 0;
    scanf("%d", &groupNumber);
    // Vertex * const graph = ::graph + 1;  // 1... n


        while (groupNumber--) {
        int n, E, s, t;
        scanf("%d%d%d%d", &n, &E, &s, &t);

            for (size_t i = 0; i < n + 1; ++i) {
                graph[i].adjacent.clear();
                graph[i].dist = -1;
                graph[i].visited = false;
            }

        for (size_t i = 0; i < E; ++i) {
            int v1, v2, w;
            scanf("%d%d%d", &v1, &v2, &w);
            graph[v1].adjacent.push_back(make_pair(graph + v2, w));
            graph[v2].adjacent.push_back(make_pair(graph + v1, w));
        }

        int visited_vertices_number = 1;
        graph[s].dist = 0;
        graph[s].visited = true;
        for (auto &item : graph[s].adjacent) {
            if (item.first->dist == -1 || item.first->dist > item.second)
                item.first->dist = item.second;
        }

        while (visited_vertices_number != n) {
            Vertex *v = nullptr;
                // min_element(graph + 1, graph + 1 + n - visited_vertices_number, cmp);

            for (int i = 1; i < n + 1; ++i) {
                if (graph[i].visited == false && (v == nullptr || cmp(graph[i], *v))) {
                    v = graph + i;
                }
            }

            v->visited = true;
            visited_vertices_number++;

            for (auto &item : v->adjacent) {
                if (item.first->visited == false) {
                    int v_to_item = item.second;
                    if (v->dist + v_to_item < item.first->dist || item.first->dist == -1) {
                        item.first->dist = v->dist + v_to_item;
                    }
                }
            }
        }

        cout << graph[t].dist << endl;
    }

    return 0;
}