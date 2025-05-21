#include<iostream>
#include<vector>

using namespace std;

#define INF INT_MAX

vector<vector<int>> floyd_warshall(vector<vector<int>> g) {
    int v = g.size();
    for(int k=0;k<v;k++) {
        for(int i=0;i<v;i++) {
            for(int j=0;j<v;j++) {
                if(g[i][k] != INF && g[k][j] != INF)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    return g;
}

int main() {
    vector<vector<int>> g = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}};

    g = floyd_warshall(g);

    for(vector<int> i : g) {
        for(int j : i)  
            j != INF ? cout<<j<<" " : cout<<"INF ";
        cout<<endl;
    }

    return 0;
}