#include<iostream>

using namespace std;

bool isCyclic(vector<vector<int>> g) {
    int n = g.size();
    vector<bool> vis(n, false), recursionStack(n, false);

    for(int i=0; i<n ; i++) {
        if( !vis[i] ) {
            vector<int> stack;
            stack.push_back(i);
            vis[i] = true;
            recursionStack[i] = true;

            while( !stack.empty() ) {
                int c = stack.back();
                bool f = false;

                for(int j=0; j<n; j++) {
                    if( g[c][j] == 1 ) {
                        if( !vis[j] ) {
                            stack.push_back(j);
                            vis[j] = true;
                            recursionStack[j] = true;
                            f = true;
                            break;
                        }
                        else if (recursionStack[j])
                            return true;
                    }
                }
                if( !f ) {
                    recursionStack[c] = false;
                    stack.pop_back();
                }
            }
        }
    }
    return false;
}

bool isCyclic_al(vector<vector<int>> al) {
    int n = al.size();
    vector<bool> v(n, false), rs(n, false);

    for( int i=0; i<n; i++ ) {
        if( !v[i] ) {
            vector<int> s;
            s.push_back(i);
            v[i] = true;
            rs[i] = true;

            while( !s.empty() ) {
                int c = s.back();
                bool f = false;

                for( int j : al[c] ) {
                    if( !v[j] ) {
                        s.push_back(j);
                        v[j] = true;
                        rs[j] = true;
                        f = true;
                        break;
                    }
                    else if( rs[j] )
                        return true;
                }
                if( !f ) {
                    rs[c] = false;
                    s.pop_back();
                }
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<int>> adj(n);

    for( int i=0; i<n ; i++) {
        for( int j=0; j<n; j++) 
            cin>>g[i][j];
    }

    for(int i =0 ; i<n ; i++) {
        for( int j=0; j<n; j++ ) {
            if(g[i][j] == 1)
                adj[i].push_back(j);
        }
    }

    //isCyclic(g) ? cout<<"Graph is cyclic\n" : cout<<"Graph is not cyclic\n";

    isCyclic_al(adj) ? cout<<"Graph is cyclic\n" : cout<<"Graph is not cyclic\n";

    for(int i=0; i<n; i++) {
        for(int j : adj[i])
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}


/*
5
0 1 1 0 0
0 0 0 1 1
0 1 0 1 0
0 0 0 0 1
0 0 0 0 0
*/