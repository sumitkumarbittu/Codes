#include<iostream> 

using namespace std;

typedef pair<int, int> pi;

int pathe(vector<vector<pi>> adj, int s, int d, int k) {
    int n = adj.size();

    vector<vector<int>> dp(k+1, vector<int>(n+1, INT_MAX));
    dp[0][s] = 0;

    for( int e=1; e<=k; e++ ) {
        for( int u=1; u<=k; u++ ) {
            if( )
        }
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
            if( g[i][j] != 0 )
                adj[i].push_back({j, g[i][j]});
        }
    }

    int s,d,k;
    cin>>s>>d>>k;

    int f = pathe(adj, s, d, k);

    return 0;    
}