#include<iostream>

using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        int mod = 1e9+7;
        vector<int> powers;
        for(int i=1; ;i++) {
            long long p = pow(i, x);
            if(p>n)
                break;
            powers.push_back((int)p);
        }

        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int p : powers) {
            cout<<p<<endl;
            for(int s = n; s>=p; s--) {
                cout<<s<<"   "<<dp[s]<<" "<<dp[s-p]<<" ";
                dp[s] = (dp[s] + dp[s-p]) % mod;
                cout<<dp[s]<<endl;
            }
        }
        return (int)dp[n];
    }
};

int main() {
    Solution S;
    cout << S.numberOfWays(20, 2) << endl;
}