#include<iostream> 
#include<utility>
#include<vector>
#include <climits>

using namespace std;

typedef pair<int, int> pi;
 
int pathe(vector<vector<pi>> adj, int s, int d, int k) {
    int n = adj.size();

    vector<vector<int>> dp(k+1, vector<int>(n, INT_MAX));
    dp[0][s-1] = 0;

    for( int e=1; e<=k; e++ ) {
        for( int u=0; u<n; u++ ) {
            if( dp[e-1][u] != INT_MAX ) {
                for( auto t : adj[u] ) {
                    if( dp[e][t.first] > dp[e-1][u] + t.second )
                        dp[e][t.first] = dp[e-1][u] + t.second;
                }
            }
        }
    }

    cout<<endl;
    for(auto i : dp) {
        for(int j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;

    return (dp[k][d-1] != INT_MAX) ?  dp[k][d-1]: -1;
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

    cout << pathe(adj, s, d, k) << endl;

    return 0;
}