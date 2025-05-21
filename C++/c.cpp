/*

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n=0,x=0;
        while(head!=NULL)
        {
            if(head->val==1)
            x+=pow(2,n);
            head=head->next;
            n++;
        }
        return x;
    }
};


int main()
{

}







*/





/*

#include <iostream>

using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        int n=num.size(),c;
        for(int j=0;j<n;j++)
        {
            c=0;
            for(int i=0;i<n;i++)    {if(num[i]==j+48)   c++;}
		cout<<c<<endl;
            if(num[j]!=c)   return false;
        }
        return true;
    }
};



int main()
{
	string n;
	Solution a;

	cin>>n;
	cout<<a.digitCount(n);

	return 0;
}

*/










/*

#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
	n--;
        while(n>=0) {     n-=(++i);
        cout<<"i : "<<i<<"  n : "<<n<<endl;}
        return i-1;
    }
};



int main()
{
	int n;
	Solution a;

	cin>>n;
	cout<<a.arrangeCoins(n)<<endl;

	return 0;
}

*/











/*

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main()
{
	unordered_set<int> nums;

	nums.insert(10);
	nums.insert(20);
	nums.insert(30);
	nums.insert(40);
	nums.insert(50);

	string a = nums.find(20);

	cout<<a;

	for(int i : nums)
	cout<<i<<endl;

}


*/





/*

#include<iostream>

using namespace std;

class tollbooth
{
    unsigned int c;
    double m;
    public:
        tollbooth()
        {
            m=0;
            c=0;
        }

        void paying_cars()
        {
            c++;
            m+=0.5;
        }
        
        void non_paying_cars()
        {
            c++;
        }
        
        void display()
        {
            cout<<"Cars : "<<c<<endl<<"Cash : "<<m<<endl;
        }
        
};


int main()
{
    tollbooth a;
    char n;
    do
    {
        printf("Choice : ");
	cin>>n;
        switch(n)
        {
            case '1':
                a.paying_cars();
                break;
            case '2':
                a.non_paying_cars();
                break;
            case '3':
                a.display();
                break;    
            case 27:
                break;
            default:
                printf("Invalid!\n");     
        }
    }while(n!=27);
    
    return 0;
}


*/





/*

#include<iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(),j=0;
        char p;
        for(int i=0;i<n;i++)
        {
            j=i;
            while(s[j]!=32 && j<n)
            j++;
	cout<<"Upper [i,j] = ["<<i<<","<<j<<"]		";
            for(int k=i,l=j-1;k<(j+i)/2;k++,l--)
            {
                p=s[k];
                s[k]=s[l];
                s[l]=p;
            }
            i=j;
	cout<<"Low [i,j] = ["<<i<<","<<j<<"]"<<endl;
        }
        return s;
    }
};

int main()
{
	Solution a;

	string s="Let's take LeetCode contest";

	cout<<a.reverseWords(s)<<endl;

	for(int i=0;i<=10;i++)
	cout<<i;

	cout<<endl<<s<<endl;


}

*/





/*

#include<iostream>

using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size(),z;
        char p;
        for(int i=0;i<n;i++)
        {
            if(k<=n-i)
            {
              for(int x=i,y=i+k-1;x<(x+y)/2;x++,y--)
                {
                    p=s[x];
                    s[x]=s[y];
                    s[y]=p;
                }
                i+=(2*k-1);
            }
            else if(k>n-i)
            {
                z=n-i;
                for(int x=i,y=n-1;x<(x+y+1)/2;x++,y--)
                {
                    p=s[x];
                    s[x]=s[y];
                    s[y]=p;
                }
                return s;
            }
        }																	
        return s;
    }
};


int main()
{
	Solution a;

	string s = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
	cout<<a.reverseStr(s,39)<<endl;

	for(int i=0;i<=10;i++)
	cout<<i;

	cout<<endl<<s<<endl;


}

*/


/*

#include<iostream>

using namespace std;


class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            while(l<r && !( (s[l]>='a' && s[l]<='z') || (s[l]>='A' && s[l]<='Z') ) )
            l++;
            while(l<r && !( (s[r]>='a' && s[r]<='z') || (s[r]>='A' && s[r]<='Z') ) )
            r--;
		cout<<l<<"	"<<r<<endl;
            swap(s[l],s[r]);
		l++,r--;
        }
        return s;
    }
};


int main()
{
	Solution a;

	string s = "Test1ng-Leet=code-Q!";
	cout<<a.reverseOnlyLetters(s)<<endl;

	for(int i=0;i<=10;i++)
	cout<<i;

	cout<<endl<<s<<endl;


}

*/




















/*

#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string a;
        int x=0;
        for(int i=0;i<s.size();i++)
        {
		cout<<s[i];
            if(s[i]>='A' && s[i]<='Z')
            a[x++]=s[i]+32;
            else if( !( (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) )
            s.erase(i--);
        }
	cout<<endl<<s<<endl;
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            return false;
        }
        return true;
    }
};

int main()
{
	Solution a;

	string s = "a.b,.";
	cout<<a.isPalindrome(s)<<endl;

	for(int i=0;i<=10;i++)
	cout<<i;

	cout<<endl<<s<<endl;


}

*/







/*

typedef struct node
{
    int a[10];
    struct node *n;
}node;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

    node h;
    for(int i=0;i<)
    if(num[i])

}

*/


/*

#include <iostream>

using namespace std;

class unary
{
	int a,b,c;

	public : 
		unary()
		{
			cin>>a>>b>>c;
		}

		void operator-()
		{
			c=-c;
		}

		void operator++()
		{
			++a,++b;

		}

		void operator++(int)
		{
			a++;
			b++;

		}

		void show()
		{
			cout<<"a : "<<a<<"	b : "<<b<<"	c : "<<c<<endl;
		}


};

int main()
{
	unary x;

	-x;
	x.show();

	++x;
	x.show();

	x++;
	x.show();	

}

*/


/*

#include <iostream>

using namespace std;

class oo
{
	string a,b;

	public : 
		oo()
		{
			getline(cin,a);
		}

		void operator+(oo &z)
		{
			z.b=a+z.a;
		}

		void show()
		{
			cout<<"a : "<<a<<"	";
			cout<<"b : "<<b<<"	";
			cout<<"c : "<<c<<endl;
		}

};

int main()
{
	oo x,z;

	x+z;
	
	x.show();
	z.show();


}

*/



/*

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int v[] = {1, 5, 10, 50, 100, 500, 1000};
        char r[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int n = 0, p = 0, q = 0, c = 0;

        for (int i = 0; s[i] != '\0'; i++) {
            // Find the value of current Roman numeral (s[i])
            for (int j = 0; j < 7; j++) {
                if (r[j] == s[i]) {
                    p = v[j];
                }
            }

            // Find the value of next Roman numeral (s[i+1]) if exists
            if (s[i+1] != '\0') {
                for (int j = 0; j < 7; j++) {
                    if (r[j] == s[i+1]) {
                        q = v[j];
                    }
                }
            } else {
                q = 0;  // End of string, no next numeral
            }

            // If the current numeral is smaller than the next one, subtract it
            if (p < q) {
                n -= p;
            } else {
                n += p;
            }
        }

        return n;
    }
};

int main() {
    Solution solution;
    
    // Test case
    string roman;
    cout << "Enter a Roman numeral: ";
    cin >> roman;
    
    int result = solution.romanToInt(roman);
    cout << "Integer value: " << result << endl;
    
    return 0;
}

*/







/*



class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.size();
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            a.push_back(i);
        }
        int x=0,y=a.size()-1;
        for(int i=a[x],j=a[y];x<y;x++,y--)
        swap(s[i],s[j]);
        return s;
    }
};





class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int x,l,a,b,s=0,y;
        for(int i=low;i<=high;i++)
        {
            x=i,l=0;
            while(x>0)
            l++,x/=10;
            for(int j=0,k=l-1;j<l/2;j++,k--)
            {
                x=i , y=x%10 , a+=y , y=x/pow(10,k);
                x=x%(int)pow(10,k) , b+=y;
                if(a==b)
                {s++;break;}
            }
        }
        return s;
    }
};


int main()
{
	Solution a;

	cout<<a.countSymmetricIntegers(1,100)<<endl;
}





for(int i=0,j=0;i<a.size();i++)
        {
            if(a[j]==a[i] && i!=j)
            {
                a.erase(a.begin()+j);
                j++,i=0;
            }
        }


*/