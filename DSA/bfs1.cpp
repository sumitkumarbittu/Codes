#include<iostream>
#include<queue>

using namespace std;

bool partite(vector<vector<int>> g) {
    int n = g.size();
    vector<int> c(n, -1);

    for(int i=0; i<n; i++) {
        if(c[i] == -1) {
            queue<int> q;
            q.push(i);
            c[i] = 0;
            while( !q.empty() ) {
                int u = q.front();
                q.pop();
                for(int j : g[u]) {
                    if(c[j] == -1) {
                        c[j] = 1 - c[u];
                        q.push(j);
                    }
                    else if(c[u] == c[j]) 
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<int>> adj(n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) 
            cin>>g[i][j];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(g[i][j] == 1)
                adj[i].push_back(j);
        }
    }

    partite(adj) ? cout<< "BiPartite\n" : cout<< "Not BiPartite\n";

    return 0;
}