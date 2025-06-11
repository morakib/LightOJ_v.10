#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> graph;  // who comes after each drink
map<string, int> color;             // 0=not visited, 1=visiting, 2=done
bool found_cycle;

void dfs(string drink) {
    color[drink] = 1;  // mark as "visiting"
    
    // check all drinks that come after this drink
    for (string next_drink : graph[drink]) {
        if (color[next_drink] == 1) {
            // oh no! we found a cycle!
            found_cycle = true;
            return;
        }
        if (color[next_drink] == 0) {
            dfs(next_drink);
        }
    }
    
    color[drink] = 2;  // mark as "done"
}

int main() {
    int t;
    cin >> t;
    
    for (int case_num = 1; case_num <= t; case_num++) {
        // reset everything for new test case
        graph.clear();
        color.clear();
        found_cycle = false;
        
        int m;
        cin >> m;
        
        // read all rules
        for (int i = 0; i < m; i++) {
            string first, second;
            cin >> first >> second;
            
            // rule: drink 'first' before 'second'
            graph[first].push_back(second);
            
            // make sure both drinks are in our color map
            color[first] = 0;
            color[second] = 0;
        }
        
        // check each drink for cycles
        for (auto& p : color) {
            string drink = p.first;
            if (color[drink] == 0) {  // not visited yet
                dfs(drink);
                if (found_cycle) break;
            }
        }
        
        // print answer
        cout << "Case " << case_num << ": ";
        if (found_cycle) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}

/*
HOW IT WORKS (5-year-old explanation):

Imagine you have toys and rules:
- "Play with toy A before toy B"
- "Play with toy B before toy C"

We draw arrows: A → B → C (this is OK!)

But if we have:
- "Play with toy A before toy B" 
- "Play with toy B before toy A"

We get: A → B → A (this is a LOOP! Impossible!)

Our program:
1. Reads all the rules
2. Draws arrows between drinks  
3. Looks for loops using DFS
4. If loop found → "No", otherwise → "Yes"

The colors help us find loops:
- 0 = haven't visited this drink yet
- 1 = currently visiting (in our path)  
- 2 = completely done with this drink

If we visit a drink that's already being visited (color=1), 
that means we found a loop!
*/
