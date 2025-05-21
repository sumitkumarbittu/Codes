/*
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
*/


/*
#include <iostream>

int main()
{
	std::cout<<"hi"<<std::endl;
}
*/


/*
#include <iostream>

using namespace std;				//print

int main()
{
	cout<<"hello"<<endl;
}
*/


/*
#include <iostream>

using namespace std;

int main()					//employee info
{
	int id,hr,phr,sal;
	cout<<"Input the Employee Id : ";
	cin>>id;
	cout<<"Input the Working hours : ";
	cin>>hr;
	cout<<"Salary per hour : ";
	cin>>phr;
	sal=hr*phr;
	cout<<"Employee Id = "<<id<<endl<<"Salary = "<<sal<<endl;
	return 0; 
}
*/


/*
#include <iostream>

using namespace std;

int main()
{
	int c=0;				//while
	while(c<0)
	{
		cout<<c;
		c++;
	}
	return 0;
}
*/


/*
#include <iostream>

using namespace std;

int main()
{
	int c;					//for
	for(c=0;c<10;c++)
	cout<<"Value is : "<<c<<"\n";
	return 0;
}
*/


/*
#include <iostream>

using namespace std;

int main()
{
	int c=0;				//do-while
	do
	{
		cout<<"Value : "<<c<<"\n";
		c++;
	}while(c<5);
	return 0;
}
*/


/*
#include <iostream>

using namespace std;

int main()
{
	int c=0;				//goto
	a:cout<<c<<"\n";
	c++;
	if(c<5)
	goto a;
	cout<<"End";
	return 0;
}
*/


/*
#include <iostream>

using namespace std;

int main()							//movie ticket
{
	int t;
	float tt;
	char x,z,w;
	
	cout<<"Input no of tickets to book : ";
	cin>>t;
	
if(t>=5&&t<=40)
{
	cout<<"Coupon Available y/n : ";
	cin>>z;

	cout<<"Refreshments y/n : ";
	cin>>x;
	
	cout<<"Circle k/q : ";
	cin>>w;

	if(w=='k')
		tt=75;
	else if(w=='q')
		tt=150;

	tt*=t;
	
	if(t>=20)
		tt*=0.9;

	if(z=='y')
		tt*=0.98;
	
	if(x=='y')
		tt+=(50*t);
	
	cout<<"Total: $"<<tt<<"\n";
}
else
cout<<"Ticket : Min.5 & Max.40\n";
	return 0;
}
*/


/*
#include <iostream>

using namespace std;

int main()
{
	int a=5;
	int &b=a;
	cout<<a<<'\n'<<b<<'\n';
	a+=10;
	cout<<a<<'\n'<<b<<'\n';
	b+=20;
	cout<<a<<'\n'<<b<<'\n';
	return 0;
}
*/


/*
#include <iostream>
#include <cstring>
using namespace std;

int main()							//Numerology
{
	int s=0,a[][26]={{65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90},
			 {1,2,3,4,5,8,3,5,1,1,2,3,4,5,7,8,1,2,3,4,6,6,6,5,1,7}};
	string b;
	getline(cin,b);
	cout<<b<<'\n';
	for(int j=0;b[j]!='\0';j++)
	{
		for(int k=0;k<26;k++)
		{
			int t=b[j];
			if (t==a[0][k])
			s+=a[1][k];
		}
	}
	cout<<s<<'\n';
	
}
*/


/*
#include <iostream>

using namespace std;

int main() {				//2d array malloc using NEW
    int rows = 3;
    int cols = 4;

    int **arr = new int*[3];
	for (int i = 0; i < 3; ++i)
	{
        	arr[i] = new int[4];
	}


// First we malloc.ed a pointer array 1D.
// Then inside a for loop running with row size.
// Malloc.ing columns row times.
// datatype of pointer _ with ** i.e, p to p_ name of pointer = new _ datatype[size];
// int **a=new int*[5];


	for (int i = 0; i < rows; ++i) 
	{
        	for (int j = 0; j < cols; ++j) 
		{-			arr[i][j] = i * cols + j;
		}
	}

    
	for (int i = 0; i < rows; ++i) 
	{
        	for (int j = 0; j < cols; ++j) 
		{
			cout << arr[i][j] << " ";
        	}
		cout << endl;
	}


	// Deallocate memory
	for (int i = 0; i < 3; ++i) 
	{
        	delete[] arr[i];
	}
	delete[] arr;

// free.ing columns using for loop running row times
// Then free.ing 1D row
// delete[] pointer.name;
// delete[] a;
 

    return 0;
}
*/

/*
#include <iostream>

using namespace std;

int main()				//a++ and ++a compare
{
	
	for (int i = 0; i < 3; ++i) 
	{ 
        	for (int j = 0; j < 4; ++j) 
		{
			cout<<"i : "<<i<<" "<<"j : "<<j<<'\n';
        		
		}
	}
}
*/


/*
#include <iostream>
#include <string>

using namespace std;

void rev(string &a);

int main()						//reverse of string
{
	string a;
	cin>>a;
	rev(a);
	cout<<a;
}

void rev(string &a)
{
	int l=a.length();
	cout<<l<<'\n';
	char t;
	for(int j=0,k=l-1;j<l/2;j++,k--)
	{
		t=a[j];
		a[j]=a[k];
		a[k]=t;
	}
}
*/


/*
#include <iostream>

using namespace std;

int main()
{
	int *a = new int;				//DMA int
	int *b = new int[b];				//DMA array


	delete a;					//deallocating int
	delete[] b;					//deallocating array

}
*/



/*


	-> Inline Function Call
	-> Default Argument
	-> Function Overloading 
	-> Compile time polymorphism



*/



/*
#include <iostream>

using namespace std;

int main()					//1 to 7 days
{
	int n;
	cin>>n;
	switch(n)
	{
		case 1:
		cout<<"Monday";
		break;

		case 2:
		cout<<"Tuesday";
		break;

		case 3:
		cout<<"Wednesday";
		break;

		case 4:
		cout<<"Thursday";
		break;

		case 5:
		cout<<"Friday";
		break;

		case 6:
		cout<<"Saturday";
		break;

		case 7:
		cout<<"Sunday";
		break;

		default:
		cout<<"Invalid Input";
		break;
	}
	return 0;
}
*/


/*
#include <iostream>

using namespace std;

struct salary
{
	int empid,basic_salary,pf,med;
	float sales;
};

int main()						//Salary Bonus
{
	struct salary n;
	cin>>n.empid;
	cin>>n.basic_salary;
	cin>>n.pf;
	cin>>n.med;
	cin>>n.sales;
	
	int total_salary,net_salary = n.basic_salary-n.pf-n.med;

	if(n.empid<0 || n.basic_salary<0 || n.pf<0 || n.med<0 || n.sales<0)
	cout<<"Unable to Calculate Salary"<<endl;

	else if(n.basic_salary<=7000 && n.sales<=10)
	total_salary = net_salary + 1500;

	else if(n.basic_salary<=7000 && n.sales>=10)
	total_salary = net_salary + 3000;

	else if(n.basic_salary>7000 && n.basic_salary<=15000 && n.sales<=10)
	total_salary = net_salary + 2000;

	else if(n.basic_salary>7000 && n.basic_salary<=15000 && n.sales>=10)
	total_salary = net_salary + 4000;

	else if(n.basic_salary>15000 && n.sales<=10)
	total_salary = net_salary + 2500;

	else if(n.basic_salary>15000 && n.sales>=10)
	total_salary = net_salary + 4500;

	cout<<total_salary<<endl;
	return 0;
}
*/


/*
#include <iostream>

using namespace std;					//Class object example

class n
{
	private:
		int a, b, c;
	public:
		int d, e;
	void set(int a1, int b1, int c1);
	void get()		
	{
		cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
	}
};

void n :: set(int a1, int b1, int c1)		//defining fn n ::
{
	a=a1;
	b=b1;
	c=c1; 
}

int main()
{
	n sum;
	sum.d=4;			//public
	sum.e=5;
	sum.set(1,2,3);			//private so accessed using fn inside class
	sum.get();

}
*/


/*
#include <iostream>

using namespace std;					

class b						//Class member nesting as 
{						//private members can only be called by class members

	string s;				//by-default members is private

	void c();				//c(); can only be called inside member function
	
	public:					//until public is notated
		void r();
		
		void o();
		void d();
};


void b:: r()					//scope resolution operator
{
	cout<<"Enter binary : ";
	cin>>s;
}

void b:: c()
{
	for(int j=0;j<s.length();j++)
	{
		if(s.at(j)!='0' && s.at(j)!='1')
		{
			cout<<"Non Binary"<<endl;
			exit(0);
		}
	}
}

void b:: o()
{
	c();					//check whether it is binary or not
	for(int j=0;j<s.length();j++)		
	{
		if(s.at(j)=='0')
			s.at(j)='1';
		else
			s.at(j)='0';
	}
}

void b:: d()
{
	cout<<"Displaying your binary no : "<<s<<endl;
}



int main()
{
	b a;
	a.r();			//reads the string
	//a.c();			//check whether it is binary or not
	a.d();			//display the string
	a.o();			//ones complement 0~1
	a.d();
}
*/


/*
#include <iostream>

using namespace std;

class shop					//class with array e.g.
{
	int id[100];
	int p[100];
	int c;
	public:
		void inc() {c=0;}
		void set();
		void display();
};

void shop:: set()
{
	cout<<"Enter Item Id : ";
	cin>>id[c];
	cout<<"Enter Price : ";
	cin>>p[c];
	c++;					//increment each time called
}

void shop:: display()
{
	for(int j=0;j<c;j++)
	cout<<"Id : "<<id[j]<<"  |  "<<"Price : "<<p[j]<<endl;
}



int main()
{
	shop a;					//variable with datatype shop
	a.inc();				//initialize c to 0
	a.set();				//get sdtin of id and price
	a.set();
	a.set();
	a.set();
	a.display();				//displays all inputs
}
*/


/*
#include <iostream>

using namespace std;				//use of static data member(or variable)
						//and static function member
class emp
{
	int id;
	static int c;				//static data member is defined for whole class 
						//not for individual objects

	public:
		void set()
		{
			cout<<"Enter Employee id : ";
			cin>>id;
			c++;
		}

		void get() 
		{
			cout<<"Employee Id : "<<id<<" of Employee no : "<<c<<endl;
		}

		static void count()		//static member function
		{				//it can be access directly by class, no use of objects
			cout<<"Value of Count : "<<c<<endl;
		}

};

int emp:: c;


int main()
{
	emp a,b,d;				//same c is defined for a,b,d
	
	a.set();
	a.get();

	emp::count();				//it can access only other static fn or static member

	b.set();
	b.get();

	emp::count();

	d.set();
	d.get();

	emp::count();

}
*/


/*
#include <iostream>

using namespace std;

class e						//array of object
{
	int id;
	int sal;
	public:
		void set()
		{
			sal=122;
			cout<<"Enter Employee id : ";
			cin>>id;
		}

		void get()
		{
			cout<<"Employee ID is "<<id<<endl;
		}
};

int main()
{
	e f[4];

	for(int j=0;j<4;j++)
	{
		f[j].set();
		f[j].get();
	}

}
*/


/*
#include <iostream>

using namespace std;

class complex					//passing object as fn argument
{						//int a,b;  ->void sum(a,b);
	int a,b;
	public:
		void set(int v1, int v2)
		{
			a=v1;
			b=v2;
		}

		void sum(complex o1, complex o2)
		{
			a=o1.a + o2.a;
			b=o1.b + o2.b;
		}

		void print()
		{
			cout<<"Complex no : "<<a<<"+"<<b<<"i"<<endl;
		}
};

int main()
{
	complex c1,c2,c3;

	c1.set(1,2);
	c1.print();

	c2.set(3,4);
	c2.print();

	c3.sum(c1,c2);
	c3.print();

}
*/


/*
#include <iostream>

using namespace std;

class complex					//Friend fn
{
	int a,b;
	public:
		void set(int n1, int n2)
		{
			a=n1;
			b=n2;
		}

		//Non member fn gets access to private member
		friend complex sum(complex o1,complex o2);		
							//friend tag is used before declaration
		void print()
		{
			cout<<"Complex no is "<<a<<"+"<<b<<"i"<<endl;
		}

};

complex sum(complex o1,complex o2)
{
	complex o3;
	o3.set((o1.a+o2.a),(o1.b+o2.b));
	return o3;
}

int main()
{
	complex c1,c2,s;

	c1.set(1,4);
	c1.print();

	c2.set(5,8);
	c2.print();

	s = sum(c1,c2);
	s.print();

}
*/


/*
#include <iostream>

using namespace std;

class complex;

class calculator
{
	public:
		int add(int a, int b)
		{
			return (a+b);
		}

		int sum(complex ,complex );
};

class complex
{
	int a,b;
	public:
		friend int calculator :: sum(complex o1, complex o2);

		void set(int n1,int n2)
		{
			a=n1;
			b=n2;
		}

		void print()
		{
			cout<<"Complex no is "<<a<<"+"<<b<<"i"<<endl;
		}
};

int calculator :: sum(complex o1,complex o2)
{
	return (o1.a+o2.a);

 }


int main()
{
	






}
*/



/*
#include <iostream>

using namespace std;

class student
{
	int p,c,m;

	public:
		string name;
		int roll,mark;

		void marks()
		{
			cout<<"Enter Marks in Physics : ";
			cin>>p;
			cout<<"Enter Marks in Chemistry : ";
			cin>>c;
			cout<<"Enter Marks in Maths : ";
			cin>>m;
			mark=(p+c+m);
		}

		void display()
		{
			cout<<mark<<endl;
		}

};

int main()
{
	student a;

	cout<<"Enter Student Name : ";
	cin>>a.name;

	cout<<"Enter Student Roll : ";
	cin>>a.roll;

	a.marks();

	cout<<a.name<<endl<<a.roll<<endl;

	a.display();

	return 0;

}
*/


/*
#include <iostream>

using namespace std;

class Solution 
{
public:
    int addDigits(int num) 
    {
        if(num>=0 && num<pow(2,31))
        {    int a;
            x:
            while(num>9){
		a=0;
		while(num>9)

            {
                a+=num%10;
                num/=10;
            }
		num=a;
            
            }
		num=a;
            return num;
        }
        else
        return 1;
    }
}; 


int main()
{
	Solution a;
	
	cout<<a.addDigits(38);

	return 0;

}
*/


/*
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>1)
        {
            if(n%2!=0)
            break;
            n/=2;
        }
        if(n==1)
        return true;
        else
        return false;

    }
};

int main()
{
	Solution a;

	cout<<a.isPowerOfTwo(11);

	return 0;
}
*/


/*
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n==2 || n==3)
        return false;

	while(n>3)
        {
            if(n%4!=0)
	    break;
	    n/=4;
        }
        if(n==1)
        return true;
        else
        return false;
    }
};

int main()
{
	Solution a;

	cout<<a.isPowerOfFour(7);

	return 0;
}
*/


/*
class Solution {
public:
    int addDigits(int num) {
        if(num>=0 && num<pow(2,31))
        {    int a;
            x:a=0;
            while(num>9)
            {
                a+=num%10;
                num/=10;
            }
            if(a>9)
            {
                num=a;
                goto x;
            }
            else 
            return a;
        }
        else
        return 1;
    }
};
*/







/*
#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a=0;
        int b=0;
        long int s=0;
        for(int i=0;i<32;i++)
        {
            b=n%10;
            n/=10;
            a+=b;
            a*=10;
        }
        
        return a;
    }
};

int main()
{
	Solution apple;

	uint32_t sum;

	sum=apple.reverseBits(00000010100101000001111010011100);
	
	cout<<sum<<endl;

	return 0;
}
*/






/*
#include <iostream>

using namespace std;

int main()
{



for(int j=0;j<32;j++)
        {
            if(a!=0)
            {
            b=a%10;
            a/=10;
            if(b==1)
            s+=pow(2,j);
            }
        }



}
*/



/*
#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &v)
{
	for(int j=0; j<v.size(); j++)
	cout<<v[j]<<" ";
	cout<<endl;
}

int main()
{
	vector<int> a;
	int e,size;

	cout<<"Enter Size : ";
	cin>>size;

	for(int j=0; j<size; j++)
	{
		cout<<"Enter an Elements : ";
		cin>>e;

		a.push_back(e);
	}

	display(a);

	vector<int> :: iterator i = 

	display(a);

	return 0;
}
*/


/*
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int l,a[32],b[32],x=0,y=0,i;
	string p;
        l=s.length();

        for(i=0;i<l;i++)
        {
            if(s[i]=='1')
            {
                b[y]=0;
                y++;
            }
        }

	
	
	if(y>=0)
	{
		for(i=0;i<l;i++)
		p[i]='0';
		return p;
	}

	for(i=0;i<l-1;i++)
        {
		if(y>1)
		{
			p[i]='1';
			y--;
		}
		else
		p[i]='0';
	}
	p[l]=1;	
	return p;
    }
};


int main()
{
	Solution z;

	z.maximumOddBinaryNumber(10011);

		

	return 0;
}
*/


/*
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {					//Reverse bit wrong logic
        uint32_t a=0;
        int b=0;
        long int s=0;
        for(int i=0;i<32;i++)
        {
            b=n%10;
            n/=10;
            a+=b;
            a*=10;
        }
        for(int j=0;j<32;j++)
        {
            if(a!=0)
            {
            b=a%10;
            a/=10;
            if(b==1)
            s+=pow(2,j);
            }
        }
        return s;
    }
};

*/


/*
class Solution {
public:
    int pivotInteger(int n) {				//Pivot Integer
        if(n==1)
        return 1;
        int x=0,y=0,i,j,k;
        for(i=1;i<n;i++)
        {
            for(k=1;k<=i;k++)
            x+=k;
            for(j=i;j<=n;j++)
            y+=j;
            if(x==y)
            return i;
            x=0,y=0;
        }
        return -1;
    }
};
*/



/*
int x,y,b,s=0;
        if(n%7==0)
        b=n/7;
        else
        b=(n/7)+1;

        for(i=0;i<b;i++)
        {
            for(int j=x;j<=y;j++)
            {
                s+=j;
                n-=7;
            }
        }
*/


/*
int i,a=0,b,s=0;
        while(n>0)
        {
            a++;
            for(i=1;i<=7;i++)
            {
                if(n==0)
                return s;
                b=i+a;
                s+=b;
                n--;
            }
        }
        return s;
*/

/*
if(n==0)
        return 0;
					//bulb switch
        int a[100]={1},i,j,x=0,c=1;
        
        for(i=1;i<n;i++)
        {
            
            for(j=0;j<n;j++)
            {
                if(n%c==0)
                {
                    if(a[j]==0)
                    a[j]=1;
                    else
                    a[j]=0;
                }
            }
            c++;
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==1)
            x++;
        }
        return x;
*/


/*
#include <iostream>

#include <vector>

using namespace std;


class Solution {
public:
    int bulbSwitch(int n) {
        vector<int> a(n,0);
        int i,j,x=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {    
                if((j+1)%(i+1)==0)
                {
                    if(a[j]==0)
                    a[j]=1;
                    else
                    a[j]=0;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==1)
            x++;
        }
        return x;
    }
};


int main()
{
	Solution x;
	int z;

	z=x.bulbSwitch(9999);

	cout<<z<<endl;

	return 0;
}
*/


/*
#include <iostream>

using namespace std;

int main()
{

	for(int i=0;i<50;i++)
	cout<<"Hi, jaiko"<<endl;
	




}
*/


/*
#include ‹stdio.h>
#include ‹string.h>
#include ‹conio.h>
int main(){
//
0123456789
char str[]={"Jai Shree Ram"};
printf ("%s\n", str);
int pos=4;
// Enter the Position
int n=9;
// Enter the no of charcters to be deleted
int len=strlen(str);
n=n-1;
for(int i=pos+n;i<len;i++){
str [1-n]=str[1];
}
puts(str);
return
*/


/*
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i,j,n=nums.size();
        for(i=0;i<=n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=nums[j])
                return i; 
            }
            
        }
    }
};

int main()
{
	Solution a;

	int nums[]={0,2,3};

	cout<<a.missingNumber(&nums)<<endl;



	return 0;
}
*/




/*
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void minimumSum(int num) {
        vector<int> a;
        for(int i=0;i<4;i++)
        {
            a[i]=num%10;
            num/=10;
        }
        for(int j=0;j<4;j++)
	cout<<a[j];

	sort(a.begin(),a.end());

	for(int j=0;j<4;j++)
	cout<<a[j];

	x=10*a[0]+a[3];
	y=10*a[1]+a[2];

	return x+y;
    }

};

int main()
{
	Solution a;

	a.minimumSum(2423);

	

	return 0;

}
*/


/*

class Solution {
public:
    int alternateDigitSum(int n) {
        int a=1,s=0,b;
        while(n>0)
        {
            b=n%10;
            n/=10;
            b*=a;
	cout<<b<<endl;
            s+=b;
            a*=(-1);
        }
        return s;
    }
};
*/


#include <iostream>

using namespace std;


int main()
{
	Solution a;

	cout<<a.alternateDigitSum(321)<<endl;




}






/*
#include <iostream>

using namespace std;

int main()
{







}
*/