#include<iostream>

using namespace std;

void keydup(vector<int> a, int k)
{
    int l = 0, h = a.size()-1, r = -1, i=0;
    while(l<=h)
    {
        int m = l + (h-l)/2;
        if(a[m] == k)
        {
            i++;
            h = m-1, r = a[m];
            while(h >= 0 && a[h--]==k)
            i++;
            while(++m < a.size() && a[m]==k)
            i++;
            cout<<r<<" : "<<i<<endl;
            return;
        }
        else if(a[m]<k)
        l = m+1;
        else
        h = m-1;
    }
    if(r==-1)
    cout<<"Key not found!"<<endl;
}

int main()
{
    int T;
    cout<<"No of TestCase : ";
    cin>>T;
    for(int j=0;j<T;j++)
    {
        vector<int> a;
        int n;
        cout<<"No of Elements in the sorted array : ";
        cin>>n;
        for(int i=0;i<n;i++)
        { 
            int t;
            cin>>t;
            a.push_back(t);
        }
        int k;
        cout<<"Key Element : ";
        cin>>k;
        keydup(a,k);
    }
    return 0;
}