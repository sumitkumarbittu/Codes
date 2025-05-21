#include<iostream>
#include <queue>

using namespace std;

int prims_ex(vector<vector<int>> g) {
    int n = g.size(), mw=0;
    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    min_heap.push({0, 0});

    while( !min_heap.empty() ) {
        int w = min_heap.top().first;
        int u = min_heap.top().second;
        min_heap.pop();

        if( vis[u]) 
        continue;

        vis[u] = true;
        mw += w;

        for(int v=0 ; v<n ; v++) {
            if( g[u][v] > 0 && !vis[v] )
                min_heap.push({g[u][v], v});
        }
    }
    return mw;
}

int main() {
    vector<vector<int>> g = {
        {0, 0, 7, 5, 0, 0, 0},
        {0, 0, 8, 5, 0, 0, 0},
        {7, 8, 0, 9, 7, 0, 0},
        {5, 0, 9, 0, 15, 6, 0},
        {0, 5, 7, 15, 0, 8, 9},
        {0, 0, 0, 6, 8, 0, 11},
        {0, 0, 0, 0, 9, 11, 0}
    };

    cout<<prims_ex(g)<<endl;

    return 0;
}