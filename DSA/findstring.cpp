#include<iostream>

using namespace std;

int findstring(string &s, string t, int m) {
    int res=0, n=s.size();
    for(int i=0; i<n-1; i++) {
        if(s[i] == t[0] && s[i+1] == t[1]) {
            cout<<i<<i+1<<endl;
            s.erase(i, 2);
            i-=2;
            res+=m;
            cout<<s<<endl;
            n=s.size();
        }
    }
    return res;
}

int main() {
    string s = "aabbaaxybbaabb";
    cout<<findstring(s, "ab", 5)<<endl;
    cout<<s<<endl;
    return 0;
}