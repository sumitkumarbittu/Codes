#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pi;


int prims(vector<vector<pi>> adj) {
    int n = adj.size();

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    vector<int> k(n, INT_MAX);
    vector<int> mst(n, false);
    int s=0;

    pq.push( {s, 0} );
    k[s] = 0;
    int mw = 0;

    while( !pq.empty() ) {
        int u = pq.top().first;
        pq.pop();

        if(mst[u])
            continue;
        mst[u] = true;
        mw += k[u];

        for( auto t : adj[u] ) {
            int v = t.first;
            int w = t.second;

            if( !mst[v] && w<k[v]) {
                k[v] = w;
                pq.push( {v, k[v]} );
            }
        }
    }
    return mw;
}


int main() {
    int n;
    cin>>n;

    vector<vector<pi>> adj(n);

    for( int i=0; i<n; i++ ) {
        for( int j=0; j<n; j++ ) {
            int w;
            cin>>w;
            if( w != 0 && i<j ) {
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }
    }

    cout << prims(adj) << endl;

    return 0;
}