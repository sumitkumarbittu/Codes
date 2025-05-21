#include<iostream>

using namespace std;

void prin(vector<int> a)
{
	for(int i : a)
	cout<<i<<" ";
	cout<<endl;
}

int lastRemaining(int n)
{
        int x;
        vector<int> a;
        for(int i=1;i<=n;i++)
        a.push_back(i);
        while(a.size()>1)
        {
            x = a.size();
            if(x>1)
            {
                for(int i=0;i<(x+1)/2;i++)
                a.erase(a.begin() + i);
            }
            x = a.size();
            if(x>1)
            {
                for(int i=x-1; i>=0; i=i-2)
                a.erase(a.begin() + i);
            }
        }
        return a[0];
}

int main()
{
	int n=16;
	cout<<lastRemaining(n);
}







/*

#include<iostream>

using namespace std;

bool symmetric(int n)
    {
        int a=0;
        while(n>0)
        {
            a++;
            n/=10;
        }
        if(a%2 == 0)
        {
            int z = pow(10,a/2);
            int l=0,m=0;
            int x = n%z;
            int y = n/z;
            while(x>0)
            {
                l+=(x%10);
                x/=10;
                m+=(y%10);
                y/=10;
            }
            if(m == l)
            return true;
        }
        return false;
    }

int main()
{
	cout<<symmetric(98);
}

*/













/*

#include<iostream>

using namespace std;

bool palindrome(string p)				//LEET 2396
    {
        string pa = p;
        reverse(pa.begin(), pa.end());
        if(pa == p)
        return true;
        return false;
    }

    string base(int n,int b)
    {
        int a;
        string p = "";
        while(n>0)
        {
            a = n%b;
            n/=b;
            p += to_string(a);
        }
        return p;
    }

    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++)
        {
            if(palindrome(base(n, i)))
            return true;
        }
        return false;
    }



int main()
{
	cout<<isStrictlyPalindromic(98);
}

*/