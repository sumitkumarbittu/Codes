#include<iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        map<int, int> map;
        int n = count.size();
        for(int i=0; i<n; i++) {
            if(count[i] != 0)
                map[i] = count[i];
        }

        vector<double> res;
        res.push_back(map.begin()->first);
        res.push_back(map.rbegin()->first);

        vector<int> r;
        double a = 0;
        int b=0;
        for(auto m : map) {
            a += m.first * m.second;
            b += m.second;
            r.push_back(b);
            //cout<<m.first<<" "<<m.second<<" "<<b<<endl;
        }
        res.push_back(a/b);

        int c = b/2;
        for(int i=0; i<r.size(); i++) {
            if((b % 2 == 1 && r[i] >= c) || r[i] > c) {
                res.push_back(next(map.begin(), i)->first);
                break;
            } else if(r[i] == c) {
                res.push_back((next(map.begin(), i)->first + next(map.begin(), i+1)->first) / 2.0);
                break;
            }
        }

        auto m = max_element(map.begin(), map.end(), [](const auto &a, const auto &b) {return a.second < b.second;});
        res.push_back(m->first);

        return res;
    }
};

int main() {
    Solution S;
    vector<int> count = {0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<double> d = S.sampleStats(count);
    for(double c : d)
        cout<<c<<" ";
    cout<<endl;
}