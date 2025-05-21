









/*

#include<iostream>

using namespace std;

class oper
{
    int a;
    string c,d;
    public : 
        oper() : a(10), c("Elephant Fish"), d("Gun Horse")
        {}

        friend void operator--(oper &x);
        friend void operator++(oper &x);
        friend void operator--(oper &x,int);
        friend void operator++(oper &x,int);
        friend string operator+(oper &x);

        void show()
        {
            cout<<"Start : "<<endl;
            cout<<a<<endl;
            cout<<c<<endl;
            cout<<d<<endl;
            cout<<": End"<<endl;
        }
};

void operator--(oper &x)    {   --x.a;  }
void operator++(oper &x)    {   ++x.a;  }
void operator--(oper &x,int)    {   x.a--;  }
void operator++(oper &x,int)    {   x.a++;  }
string operator+(oper &x)    {   return x.c+" "+x.d;  }



int main()
{
    oper z;
    z.show();
    z++;
    z.show();
    z--;
    z.show();
    ++z;
    z.show();
    --z;
    z.show();
    string p = +z;
    cout<<"String concatenate : "<<p<<endl;    
}

*/



/*

#include<iostream>

using namespace std;

class oper
{
    int a;
    string c,d;
    public : 
        oper()
        {
            a=10;
            c="Apple BAll",d="Cat Dog";
        }

        void operator--()   //pre --
        {
            --a;
        }

        void operator++(int)    //post ++
        {
            a++;
        }

        void operator--(int)    //post --
        {
            a--;
        }

        void operator++()       //pre ++
        {
            ++a;
        }

        string operator+()      //string concatenate
        {
            return c+ " " + d;
        }

        void show()
        {
            cout<<"Start : "<<endl;
            cout<<a<<endl;
            cout<<c<<endl;
            cout<<d<<endl;
            cout<<": End"<<endl;
        }
};

int main()
{
    oper z;
    z.show();
    z++;
    z.show();
    z--;
    z.show();
    ++z;
    z.show();
    --z;
    z.show();
    string p = +z;
    cout<<"String concatenate : "<<p<<endl;    
}

*/




/*

#include<iostream>

using namespace std;
//PROOOGGRAMMMMIING
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            s.erase(i+1,1);
            i--;
        }
    }
    cout<<s<<endl;
}

*/