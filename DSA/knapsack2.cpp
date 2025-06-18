#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n,k;	cin >> n>>k;
 
	vector<int> c,d;
	for(int i=0;i<n;i++) { int e; cin>>e; c.push_back(e); }
	for(int i=0;i<n;i++) { int e; cin>>e; d.push_back(e); }
 
	vector<pair<pair<int, int>, double>> vpw;
	for(int i=0;i<n;i++) {
		vpw.push_back( {{c[i],d[i]}, double(c[i]) / d[i] }); 
	}
	
	sort(vpw.begin(), vpw.end(), [](const auto &a, const auto &b) { return a.second > b.second; });

	double p=0;
	int i=0;
	while( k>0 ) {
		int v = vpw[i].first.first, w = vpw[i].first.second;
		if(k >= w ) {
			p += v;
			k -= w;
		}
		else {
			p += int(k*vpw[i].second);
			break;
		}
		i++;
	}

	cout<<p<<endl;
 
	return 0;
}