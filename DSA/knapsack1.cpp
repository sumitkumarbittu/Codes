#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

struct item {
    int w, v;
    double vpu;
    int i;
};

bool compareitems(item a, item b) {
    return a.vpu > b.vpu;
}

vector<pair<int, double>> fracks(vector<item> it, int cap) {
    sort(it.begin(), it.end(), compareitems);
    
    double totalv = 0;

    vector<pair<int, double>> select;

    for(auto t : it) {
        if( cap <= 0 ) 
            break;

        int taken = min(t.w, cap);
        double frac = double (taken) / t.w;
        totalv += frac * t.v;
        cap -= taken;

        select.emplace_back(t.i , taken);
    }

    cout<<fixed<<setprecision(2);

    cout<<totalv<<endl;

    return select;

}

int main() {
    int n;
    cin>>n;

    vector<int> w(n);
    for(int i=0; i<n ; i++) 
        cin>>w[i];

    vector<int> v(n);
    for(int i=0; i<n ; i++) 
        cin>>v[i];

    int cap;
    cin>>cap;

    vector<item> it;

    for(int k=0; k<n ; k++)
        it.push_back({w[k], v[k], double(v[k])/w[k], k+1});

    vector<pair<int, double>> f = fracks(it, cap);

    for(auto t : f) {
        cout<<t.first<< " "<<t.second<<endl;
    }

}