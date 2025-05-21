#include<iostream>

using namespace std;

bool pathe(vector<vector<int>> g, int s, int d, vector<bool> v) {
    if(s == d)  return true;

    v[s] = true;

    for( int i=0; i < g[s].size() ; i++ ) {
        if( g[s][i] == 1 && !v[i]) {
            if(pathe(g, i, d, v))
                return true;
        }
    }

    return false;
}

bool pathe_al(vector<vector<int>> al, int s, int d, vector<bool> v) {
    if(s == d) return true;

    v[s] = true;

    for(int i : al[s]) {
        if(!v[i]) {
            if( pathe_al(al,i,d,v) )
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<int>> al(n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) 
            cin>>g[i][j];
    }

    for(int i = 0; i<n ; i++) {
        for(int j=0; j<n; j++) {
            if(g[i][j] == 1)
                al[i].push_back(j);
        }
    }

    int s,d;
    cin>>s;
    cin>>d;

    vector<bool> v(n, false);

    //pathe(g, s-1, d-1, v) ? cout<< "Path exists"<<endl : cout<< "No path exists"<<endl;

    pathe_al(al, s-1, d-1, v) ? cout<< "Path exists"<<endl : cout<< "No path exists"<<endl;

    for(int i=0 ; i<n ;i++) {
        for(int j : al[i])
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}

/*
5
0 1 1 0 0
1 0 1 1 1
1 1 0 1 0
0 1 1 0 1
0 1 0 1 0
1 5
*/