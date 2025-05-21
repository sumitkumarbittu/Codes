/*

#include <iostream>

using namespace std;

int main()							//1
{
	string name;
	int unit;
	float charge=0,surcharge;

	cout<<"Enter name of the consumer : ";
	cin>>name;
	cout<<"Enter Units Consumed : ";
	cin>>unit;

	if(unit>300)
	{
		charge=(unit-300)*0.90;
		unit=300;
	}

	if(unit>100)
	{
		charge+=(unit-100)*0.80;
		unit=100;
	}
	
	if(unit>0)
	charge+=unit*0.60;

	if(charge>300)
	surcharge=charge*15/100;

	if(surcharge<50)
	surcharge=50;

	charge+=surcharge;

	cout<<"Name : "<<name<<endl<<"Charges : "<<charge<<endl;
	return 0;
}

*/




/*

#include <iostream>

using namespace std;

int main()							//2
{
	string a;
	int j=0;

	cout<<"Input : ";
	getline(cin,a);

	char *b = (char *)malloc(a.size()*sizeof(char));

	for(int i=0;i<a.size();i++)
	{
		if(a[i]!='t')
		{
			b[j]=a[i];
			j++;
		}
	}
	b[j]='\0';

	cout<<"Output : "<<b<<endl;

	free(b);

	return 0;
}

*/




/*

#include <iostream>

using namespace std;

int main()							//3
{
	char a; 
	int x,z,k=0;
	string s;

	cout<<"Input String : ";
	getline(cin,s);

	char *t = (char *)malloc(s.size()*sizeof(char));

	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='#')
		continue;
		z=0;
		a=s[i];
		for(int j=i+1;j<s.size();j++)
		{
			if(s[j]=='#')
			continue;
			if(a==s[j])
			{
				z++;
				s[j]='#';
			}
		}
		s[i]='#';
		if(z==0)
		{
			t[k]=a;
			k++;
		}
	}
	
	for(int i=0;i<k-1;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if(t[i]>t[j])
			{
				a=t[i];
				t[i]=t[j];
				t[j]=a;
			}
		}
	}
	for(int i=0;i<k;i++)
	cout<<t[i]<<' ';

	cout<<endl;

	free(t);
	
	return 0;
}

*/








/*

#include <iostream>
#include <cstdlib>

using namespace std;

int main()						
{
	int n,*a,*s,z=0;

	cout<<"Size : ";
	cin>>n;

	a = (int *)malloc(n*sizeof(int));
	s = (int *)malloc((n-2)*sizeof(int));

	cout<<"Elements : ";
	for(int i=0;i<n;i++)
	cin>>a[i];

	
	

	t=s[0];
	for(int i=1;i<n-2;i++)
	{
		if(t<s[i])
		t=s[i];
	}
	cout<<t<<endl;
	
	free(a);
	free(s);

	return 0;
}

*/






/*

#include <iostream>

using namespace std;

int main()							//4
{
	int c,n,*a,t,s,l=0,z;

	cout<<"Size : ";
	cin>>n;

	a=(int *)malloc(n*sizeof(int));

	cout<<"Elements : ";
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
		s=0,c=1,t=n-i,z=i;
		while(t>=c)
		{
			for(int j=0;j<c;j++,z++)
			s+=a[z];
			t-=c;
			c++;
		}
		if(l<s)
		l=s;
	}
	cout<<"Output : "<<l<<endl;

	free(a);
	return 0;
}

*/








/*

#include <iostream>

using namespace std;

int main()							
{
	int c,n,*a,t,s,l=0,z,y;

	cout<<"Size : ";
	cin>>n;

	a=(int *)malloc(n*sizeof(int));

	cout<<"Elements : ";
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
		s=0,c=1,t=n-i,z=i;
		cout<<"t : "<<t<<endl;
		while(t>=c)
		{
			y=0;
			cout<<"c : "<<c<<endl;
			for(int j=0;j<c;j++,z++)
			{
				cout<<"y : ";
				y+=a[z];
				cout<<y<<endl;
			}
			s+=y;
			cout<<"s : "<<s<<endl;
			t-=c;
			c++;
			cout<<"t : "<<t<<endl;
		}
		cout<<"c : "<<c<<endl;
		if(l<s)
		l=s;
		cout<<s<<" "<<l<<" "<<endl;
		
	}

	cout<<"Output : "<<l<<endl;

	free(a);
	return 0;
}

*/






/*

#include <iostream>

using namespace std;				//5



class car				//data abstraction
{
	private : 				// Class and Objects
		int speed;

	public : 
		void set(int s)
		{
			speed=s;	
		}

		
		int get()
		{
			return speed;
		}


};




int main()							
{
	int s;
	car a;

	cout<<"Speed : ";
	cin>>s;

	a.set(s);
	cout<<a.get()<<endl;

	return 0;
}

*/




/*

#include <iostream>

using namespace std;

class hotel						//6
{
	private : 
		int rno,nod;
		float t;
		string n;

		float calc(float t,int nod)
		{
			float z=t*nod;
			
			if(z>10000)
			return 1.05*z;
			
			else
			return z;

		}
		
	public : 
		void checkin()
		{
			cout<<"Room No. ";
			cin>>rno;

			cout<<"Name : ";
			cin>>n;

			cout<<"Tarrif : ";
			cin>>t;

			cout<<"No of Days : ";
			cin>>nod;
		}


		void checkout()
		{
			cout<<rno<<endl<<n<<endl<<t<<endl<<nod<<endl;

			cout<<calc(t,nod)<<endl;

		}


};


int main()							
{
	hotel a;

	a.checkin();

	a.checkout();

	return 0;
}

*/




/*

#include <iostream>

using namespace std;


class bank					//7
{
	public:
		string n;
		int acc,bal;
		char t;

		void assign()
		{
			cout<<"Name : ";
			cin>>n;

			cout<<"Acc no. ";
			cin>>acc;

			cout<<"Account Type : ";
			cin>>t;

			cout<<"Balance : ";
			cin>>bal;

		}

		int deposit()
		{
			int z;			

			cout<<"Amount to Deposit : ";
			cin>>z;

			bal+=z;

			return bal;
		}

		int withdraw()
		{
			int y;			

			cout<<"Current Balance : "<<bal<<endl;
			
			cout<<"Amount to Withdraw : ";
			cin>>y;

			bal-=y;

			return bal;
		}

		void display()
		{
			cout<<n<<endl<<bal<<endl;
		}		


};


int main()							
{
	bank b;

	b.assign();

	b.deposit();	

	b.withdraw();

	b.display();

	return 0;
}

*/






/*

#include <iostream>

using namespace std;

class student					//8
{
	public :
		int s[5];

		void input()
		{
			for(int i=0;i<5;i++)
			cin>>s[i];
		}
		
		int calc()
		{
			int sum=0;

			for(int i=0;i<5;i++)
			sum+=s[i];

			return sum;
		}

};


int main()							
{
	student a;
	int n,c=0,anna=136;

	cout<<"No. of students in class : ";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		a.input();

		if(anna<a.calc())
		c++;
	}

	cout<<c<<endl;

	return 0;
}

*/




/*

#include <iostream>
#include <cmath>

using namespace std;

class ar					//9
{
	public :
		int a,b,c;

		int area(int a)
		{
			return a*a;
		}

		int area(int a,int b)
		{
			return a*b;
		}

		int area(int a,int b,int c)
		{
			int s=a+b+c,z;
			z=s*(s-a)*(s-b)*(s-c);		
			return sqrt(z);
		}
};


int main()							
{
	int a,b,c,d,e,f;

	cin>>a>>b>>c>>d>>e>>f;

	ar square,rectangle,triangle;

	cout<<square.area(a)<<endl;
	cout<<rectangle.area(b,c)<<endl;
	cout<<triangle.area(d,e,f)<<endl;

	return 0;
}

*/






/*

#include <iostream>
#include <string>

using namespace std;

class invoice					//10
{
	private : 
		 
		string no,des;
		int q;
		double pq;

	public :

		invoice()
		{
			q=0,pq=0;
			no="M000";
			des="Hardware Part";
		}


		double amount()	{return q*pq;}



		string get_no()		{return no;}
		void set_no(string b)	{no=b;}


		string get_des()	{return des;}
		void set_des(string b)	{des=b;}


		int get_q()		{return q;}
		void set_q(int b)	{if(b>0) q=b;}


		double get_pq()		{return pq;}
		void set_pq(double b)	{if(b>0) pq=b;}

		void input()
		{
			int i;
			double j;
			string k;

			cout<<"no : ";
			getline(cin,k);
			set_no(k);

			cout<<"des : ";
			getline(cin,k);	
			set_des(k);

			cout<<"q : ";
			cin>>i;
			set_q(i);

			cout<<"pq :";
			cin>>j;
			set_pq(j);
		}

};



int main()							
{
	invoice y;


	cout<<y.get_no()<<endl<<y.get_des()<<endl;
	cout<<y.get_q()<<endl<<y.get_pq()<<endl;

	cout<<"Amount : "<<y.amount()<<endl<<endl;


	y.input();


	cout<<y.get_no()<<endl<<y.get_des()<<endl;
	cout<<y.get_q()<<endl<<y.get_pq()<<endl;

	cout<<"Amount : "<<y.amount()<<endl;

	return 0;
}

*/





/*

#include<iostream>

using namespace std;

class tollbooth				//11
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
            cout<<"Cars : "<<c<<endl;
	    cout<<"Cash : "<<m<<endl;
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

#include <iostream>

using namespace std;

class time					//12
{
	private : 

		int h,m,s;

	public :
 
		time()
		{
			h=m=s=0;
		}

		time(int a,int b,int c)
		{
			h=a,m=b,s=c;
		}

		time add(time p,time q)
		{
			time r;
	
			r.h=p.h+q.h;
			r.m=p.m+q.m;
			r.s=p.s+q.s;

			if(r.s>=60)
			{
				r.m++;
				r.s-=60;
			}
			if(r.m>=60)
			{
				r.h++;
				r.m-=60;
			}

			return r;
		}

		void display()
		{
			if(h/10==0)
			cout<<"0"<<h;
			else
			cout<<h;
			cout<<":";

			if(m/10==0)
			cout<<"0"<<m;
			else
			cout<<m;
			cout<<":";

			if(s/10==0)
			cout<<"0"<<s;
			else
			cout<<s;
			cout<<endl;
		}

};



int main()							
{
	class time x(7,10,45),y(10,25,40),z;

	z=z.add(x,y);

	z.display();

	return 0;
}

*/




/*

#include <iostream>

using namespace std;

class acc					//13
{
	private : 

		double bal,i;

	public :

		void set_bal(int x)
		{
			bal=x;
		} 

		void set_i(int x)
		{
			i=x;
		}

		double month()
		{
			return (bal*i)/1200.0;
		}

		double total()
		{
			bal+=month();
			return bal;
		}


};


int main()							
{
	acc a,b;
	double n,p,q;

	cin>>p>>q;			//2000 3000

	a.set_bal(p);
	b.set_bal(q);

	cin>>n;				//4

	a.set_i(n);
	b.set_i(n);

	cout<<a.total()<<endl;
	cout<<b.total()<<endl;

	cin>>n;				//5

	a.set_i(n);
	b.set_i(n);

	cout<<a.total()<<endl;
	cout<<b.total()<<endl;

	return 0;
}

*/




/*

#include <iostream>

using namespace std;

class complex						//14
{
	double r,i;	

	public : 
		
		complex()
		{
			r=0,i=0;
		}

		complex(double x,double y)
		{
			r=x,i=y;
		}

		complex operator+(complex x)
		{
			r+=x.r;
			i+=x.i;
			return complex(r,i);
		}

		complex operator-(complex x)
		{
			r-=x.r;
			i-=x.i;
			return complex(r,i);
		}

		bool operator==(complex x)
		{
			if(r==x.r && i==x.i)
			return true;
			else
			return false;
		}
		

		void display()
		{
			cout<<r<<"+i"<<i<<endl;
		}

		void input()
		{
			cin>>r>>i;
			
		}

};


int main()							
{
	complex a,b,c,d,e,f;

	a.input();
	b.input();

	a = a + b;
	a.display();
	
	c.input();
	d.input();

	c = c - d;
	c.display();
	
	e.input();
	f.input();

	e.display();
	f.display();
	if((e==f)!=0)
	cout<<"both are same";
	else
	cout<<"both are not same";


	return 0;

}

*/





/*

#include <iostream>

using namespace std;

class unary					//15
{
	int m,n;	

	public :

		unary()
		{
			m=8,n=9;
		}

		void operator-()
		{
			m=-m;
			n=-n;
		}

		void operator--()
		{
			--m;
			--n;
		}

		void operator--(int)
		{
			m--;
			n--;
		}

		void operator++()
		{
			++m;
			++n;
		}

		void operator++(int)
		{
			m++;
			n++;
		}

		void show()
		{
			cout<<m<<" "<<n<<endl;
		}

};


int main()							
{
	unary a,b,c,d,e;

	a.show();
	-a;
	a.show();
	

	b.show();
	--b;
	b.show();

	c.show();
	++c;
	c.show();

	d.show();
	d--;
	d.show();

	e.show();
	e++;
	e.show();

	return 0;

}

*/




















/*

#include <iostream>

using namespace std;

int main()							
{




	return 0;
}

*/