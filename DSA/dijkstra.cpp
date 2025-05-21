#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;

vector<pair<vector<int>, int>> pathe(vector<vector<pair<int, int>>> adj, int s) {
    int n = adj.size();

    vector<pair<vector<int>, int>> f(n);

    vector<int> d(n, INT_MAX), p(n, -1);

    d[s] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s});

    while( !pq.empty() ) {
        int dis = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if( dis > d[u] )    continue;

        for( pi k : adj[u] ) {
            if( d[k.first] > d[u] + k.second ) {
                d[k.first] = d[u] + k.second;
                p[k.first] = u;
                pq.push({d[k.first], k.first});
            }
        }
    }

    for(int des=0; des<n; des++) {
        if(s == des) 
            f[des] = {{s+1}, 0};
        else {
            vector<int> path;
            int c = des;
            while(c != s) { 
                if(c == -1) 
                    break;
                path.push_back(c+1);
                c = p[c];
            }
            if(c == -1) 
                f[des] = {{}, INT_MAX};
            else {
                path.push_back(s+1);
                reverse(path.begin(), path.end());
                f[des] = {path, d[des]};
            }
        }
    }
    return f;
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> g(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>g[i][j];
        }
    }

    vector<vector<pi>> adj(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(g[i][j] > 0)
                adj[i].push_back({j, g[i][j]});
        }
    }

    int s;
    cin>>s;
    s--;

    vector<pair<vector<int>, int>> x = pathe(adj,s);

    for( auto i : x) {
        for( auto j : i.first)
            cout<<j<<" ";
            cout<<": "<<i.second<<endl;
    }

    return 0;
}
