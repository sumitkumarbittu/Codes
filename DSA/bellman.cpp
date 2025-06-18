#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

vector<pair<vector<int>, int>> pathe(vector<vector<pi>> adj, int s) {
    int n = adj.size();

    vector<pair<vector<int>, int>> f(n);

    vector<int> d(n, INT_MAX), p(n, -1);

    d[s] = 0;
 
    for( int i=0; i<n-1; i++ ) {
        for( int j=0; j<n; j++ ) {
            for( pi k : adj[j] ) {
                if( d[j] != INT_MAX && d[j] + k.second < d[k.first] ) {
                    d[k.first] = d[j] + k.second;
                    p[k.first] = j;
                }
            }
        }
    }

    for( int i=0; i<n; i++ ) {
        for(pi j : adj[i]) {
            if( d[i] != INT_MAX && d[i] + j.second < d[j.first]) 
                return f;
        }
    }

    for( int i=0; i<n; i++ ) {
        if(i == s) {
            f[i] = {{s}, 0};
            continue;
        }

        if(p[i] == -1) {
            f[i] = {{}, INT_MAX};
            continue;
        }

        vector<int> path;
        for( int j=i; j != -1; j=p[j] )
            path.push_back(j);
        reverse( path.begin(), path.end() );
        f[i] = {path, d[i]};
    }

    return f;
}


int main() {
    int n;
    cin>>n;

    vector<vector<int>> g(n, vector<int>(n));

    for( int i=0; i<n; i++ ) {
        for( int j=0; j<n; j++ )
            cin>>g[i][j];
    }

    vector<vector<pi>> adj(n);

    for( int i=0; i<n; i++ ) {
        for( int j=0; j<n; j++ ) {
            if(g[i][j] != 0)
                adj[i].push_back({j, g[i][j]});
        }
    }

    int s;
    cin>>s;

    vector<pair<vector<int>,int>> f = pathe(adj, s);

    for( int i=0; i<n; i++ ) {
        for( int j : f[i].first) 
            cout<<j+1<<" ";
        cout<<": "<<f[i].second<<endl;
    }

    return 0;
}

/*

4
0 5 0 10
0 0 3 0
0 0 0 1
0 0 0 0
0

*/

/*

1 vector which stores distance, 1 vector which stores precedence if new short distance is found
n^3 loop for relaxation of distance n-1 times i.e, for making the distance vector shorter
then 1 iteration for checking and terminating if any negative cycle found
a loop for returning the pathe with the shortest distance which has two iff, 1 for source with d=0 
and other for no pathe found with d = int.max and 1 last vector for pushing the path for vertices

*/