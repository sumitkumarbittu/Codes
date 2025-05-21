#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> countSubarrays(vector<int>& nums, long long k) {     //2302
        int n = nums.size();
        long long s=0,f=0;
        vector<int> t;

        vector<vector<int>> c;

        for(int l=0, r=0 ; r<n ; r++) {
            s+=nums[r];

            c.push_back(vector<int>{nums[r]});
            t.push_back(nums[r]);
            c.push_back(t);


            while(l <= r && s * (r-l+1) >= k) { 
                t.clear();
                t.push_back(nums[r]);

                s-=nums[l];
                t.push_back(nums[l]);

                l++;

                c.push_back(t);
            }

            f += r-l+1;
        }
        return c;
    }
};

int main() {
    Solution S;
    int k = 50;

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i:vec)
    cout<<i<<" ";
    cout<<endl<<endl;
    
    vector<vector<int>> c = S.countSubarrays(vec,k);

    for(vector<int> i : c) {
        for(int j : i)
        cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}