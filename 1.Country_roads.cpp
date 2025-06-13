#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCases;
    cin >> testCases;
    
    for (int tc = 1; tc <= testCases; tc++) {
        int numberOfCities, numberOfRoads;
        cin >> numberOfCities >> numberOfRoads;
        
        // Adjacency list representation
        vector<int> graph[numberOfCities];
        
        // Distance array - stores minimum maximum edge weight to reach each city
        vector<int> distance(numberOfCities, INT_MAX);
        
        // Cost matrix to store edge weights (handle multiple edges)
        int cost[numberOfCities][numberOfCities];
        memset(cost, 0, sizeof(cost));
        
        // Read roads and build graph
        for (int i = 0; i < numberOfRoads; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            
            // Handle multiple edges between same cities - keep minimum weight
            if (cost[u][v] == 0) {
                // First edge between u and v
                graph[u].push_back(v);
                graph[v].push_back(u);
                cost[u][v] = cost[v][u] = w;
            } else {
                // Multiple edges - keep minimum weight
                cost[u][v] = cost[v][u] = min(cost[u][v], w);
            }
        }
        
        int homeTown;
        cin >> homeTown;
        
        // BFS to find minimum maximum edge weight paths
        queue<int> q;
        q.push(homeTown);
        distance[homeTown] = 0;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            // Explore all neighbors
            for (int neighbor : graph[current]) {
                // Calculate maximum edge weight for this path
                int maxCostInPath = max(distance[current], cost[current][neighbor]);
                 
                // Update if we found a better path (smaller maximum edge weight)
                if (distance[neighbor] > maxCostInPath) {
                    distance[neighbor] = maxCostInPath;
                    q.push(neighbor);
                }
            }
        }
        
        // Output results
        cout << "Case " << tc << ":\n";
        for (int i = 0; i < numberOfCities; i++) {
            if (distance[i] == INT_MAX) {
                cout << "Impossible\n";
            } else {
                cout << distance[i] << "\n";
            }
        }
    }
    
    return 0;
}
