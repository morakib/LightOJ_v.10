#include <bits/stdc++.h>
using namespace std;

const int N = 20005;
vector<int> graph[N];
bool visited[N];
int color[N];

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    color[start] = 0;  // 0 for vampire, 1 for lykan

    int vampire = 1, lykan = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                color[v] = 1 - color[u];  // alternate color
                if (color[v] == 0) vampire++;
                else lykan++;
                q.push(v);
            }
        }
    }
    return max(vampire, lykan);
}

int main() {
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int edges;
        cin >> edges;

        // reset everything
        for (int i = 0; i < N; i++) {
            graph[i].clear();
            visited[i] = false;
        }

        int u, v;
        set<int> nodes; // keep track of all unique nodes
        for (int i = 0; i < edges; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            nodes.insert(u);
            nodes.insert(v);
        }

        int total = 0;
        for (int node : nodes) {
            if (!visited[node]) {
                total += bfs(node);
            }
        }

        cout << "Case " << cs << ": " << total << "\n";
    }
    return 0;
}
