#include <iostream>

using namespace std;
























/*

#include<iostream>

using namespace std;

class deno{};

int main()                              //Exception Handling
{
    double n,d;
    try
    {
        cin>>n>>d;
        if(d == 0)
        throw deno();
        cout<<n/d;
    }
    catch(const deno&)
    {
        cout<<"Denominator is Zero!\n";
    }
}


*/




/* 

#include <string>
#include <cctype>

class OverLoadDemo {
public:
    void merge(const string& str1, const string& str2) {
        string merged = str1 + str2;
        string vowels = "", consonants = "";

        for (char ch : merged) {
            if (isalpha(ch)) {
                char lowerCh = tolower(ch);
                if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
                    vowels += ch;
                } else {
                    consonants += ch; 
                }
            }
        }

        cout << vowels + consonants << endl;
    }

    int merge(const string& str) {
        int sum = 0;

        for (char ch : str) {
            if (isdigit(ch)) {
                sum += ch - '0';
            }
        }

        return sum;
    }
};

int main() {
    OverLoadDemo obj;

    cout << "Merging strings (vowels first, then consonants):" << endl;
    obj.merge("Graphic", "Era");

    cout << "Sum of digits in 'gra54phic37abc': " << obj.merge("gra54phic37abc") << endl; // Expected output: 19
    cout << "Sum of digits in 'graphicworld': " << obj.merge("graphicworld") << endl;     // Expected output: 0

    return 0;
}

*/












/*

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        minutes += seconds / 60;
        seconds %= 60;

        hours += minutes / 60;
        minutes %= 60;
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    void readTime() {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
        normalize();
    }

    Time addTime(const Time& other) const {
        int totalHours = hours + other.hours;
        int totalMinutes = minutes + other.minutes;
        int totalSeconds = seconds + other.seconds;

        return Time(totalHours, totalMinutes, totalSeconds);
    }

    void displayTime() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << ":"
             << setfill('0') << setw(2) << seconds << endl;
    }
};

int main() {
    Time time1, time2;

    cout << "Enter the first time:" << endl;
    time1.readTime();

    cout << "Enter the second time:" << endl;
    time2.readTime();

    Time result = time1.addTime(time2);

    cout << "The sum of the two times is: ";
    result.displayTime();

    return 0;
}

*/












/*

class Publication {
protected:
    string title;

public:
    Publication(const string& t = "Unknown Title") : title(t) {}
    virtual void showInfo() const {
        cout << "Publication Title: " << title << endl;
    }
};

class Book : virtual public Publication {
protected:
    int accessionNumber;

public:
    Book(const string& t = "Unknown Title", int accNo = 0)
        : Publication(t), accessionNumber(accNo) {}

    void showInfo() const override {
        Publication::showInfo();
        cout << "Book Accession Number: " << accessionNumber << endl;
    }
};

class Magazine : virtual public Publication {
protected:
    int volumeNumber;

public:
    Magazine(const string& t = "Unknown Title", int volNo = 0)
        : Publication(t), volumeNumber(volNo) {}

    void showInfo() const override {
        Publication::showInfo();
        cout << "Magazine Volume Number: " << volumeNumber << endl;
    }
};

class Journal : public Book, public Magazine {
public:
    Journal(const string& t = "Unknown Title", int accNo = 0, int volNo = 0)
        : Publication(t), Book(t, accNo), Magazine(t, volNo) {}

    void showInfo() const override {
        Book::showInfo();   
        Magazine::showInfo(); 
        cout << "Journal combines Book and Magazine information.\n";
    }
};

int main() {
    Journal myJournal("Advanced Computing", 600, 50);

    myJournal.showInfo();

    return 0;
}

*/






/*

class A {
public:
    void func(int& val) {
        val *= 2;
    }
};

class B {
public:
    void func(int& val) {
        val *= 3;
    }
};

class C {
public:
    void func(int& val) {
        val *= 5;
    }
};

class D {
    int val;

public:
    D() : val(1) {}

    void update_val(int new_val) {
        A a;
        B b;
        C c;

        int countA = 0, countB = 0, countC = 0;

        while (new_val % 2 == 0) {
            a.func(val);
            countA++;
            new_val /= 2;
        }

        while (new_val % 3 == 0) {
            b.func(val);
            countB++;
            new_val /= 3;
        }

        while (new_val % 5 == 0) {
            c.func(val);
            countC++;
            new_val /= 5;
        }

        cout << "A's func called " << countA << " times" << endl;
        cout << "B's func called " << countB << " times" << endl;
        cout << "C's func called " << countC << " times" << endl;
    }

    int get_val() const {
        return val;
    }
};

int main() {
    D d;
    int new_val = 30;
    d.update_val(new_val);
    return 0;
}

*/








/*

class oper
{
    int a;
    public : 
        oper(int n) : a(n)  {}

        friend void operator--(oper &x);
        friend void operator++(oper &x);
        friend void operator--(oper &x,int);
        friend void operator++(oper &x,int);
        friend void operator-(oper &x);

        void show()
        {
            cout<<a<<endl;
        }
};

void operator--(oper &x)    {   --x.a;  }
void operator++(oper &x)    {   ++x.a;  }
void operator--(oper &x,int)    {   x.a--;  }
void operator++(oper &x,int)    {   x.a++;  }
void operator-(oper &x)     {   x.a = -x.a; }

int main()
{
    oper z(10);
    z.show();
    z++;
    z.show();
    z--;
    z.show();
    ++z;
    z.show();
    --z;
    z.show(); 
    -z;
    z.show();
    return 0;  
}

*/

/*

class b                                     //constructor and destructor inheritance
{
    public : 
        b()
        {
            cout<<"Constructor b no parameter!"<<endl;
        }
        b(int x)
        {
            cout<<"Constructor b : "<<x<<endl;
        }
        ~b()
        {
            cout<<"Destructor b!"<<endl;
        }
};

class d : public b
{
    public : 
        d()
        {
            cout<<"Constructor d no parameter!"<<endl;
        }
        d(int x,int y) : b(x)
        {
            cout<<"Constructor d : "<<x<<" "<<y<<endl;
        }
        ~d()
        {
            cout<<"Destructor d!"<<endl;
        }
};

int main()
{
    //d z;
    d y(2,3);
    return 0;
}

*/



/*

class volume                                    //pure virtual method
{
    protected :
        float r,h;
    public : 
        virtual void display_volume() = 0 ;
};

class cone : public volume
{
    public :
        cone(float ra,float he)
        {
            r = ra;
            h = he;
        }

        void display_volume()
        {
            cout<<(3.14*r*r*h)/3.0<<endl;
        }
};

class cylinder : public volume
{
    public :
        cylinder(float ra,float he)
        {
            r = ra;
            h = he;
        }

        void display_volume()
        {
            cout<<(3.14*r*r*h)<<endl;
        }
};

class hemisphere : public volume
{
    public :
        hemisphere(float ra)
        {
            r = ra;
        }

        void display_volume()
        {
            cout<<(2*3.14*r*r*r)/3.0<<endl;
        }
};

int main()
{
    cone c(3,4);
    cylinder cy(3,4);
    hemisphere h(3);
    c.display_volume();
    cy.display_volume();
    h.display_volume();
    return 0;
}

*/

/*
int main()
{
    volume *p;
    volume c;
    cone a;
    hemisphere b;
    p = &a;
    p->setdata(4,6);
    p->display_volume();
    p = &b;
    p->setdata(2,3);
    p->display_volume();
//  p = &c;
//  p->display_volume();
    return 0;
}
*/











/*

struct a                                              //virtual method
{
    virtual void w()    {   cout<<"a"<<endl;    }
};

struct b : a
{
    void w()    {   cout<<"b"<<endl;    }
};

struct c : a
{
    void w()    {   cout<<"c"<<endl;    }
};

struct d : c
{
    void w()    {   cout<<"d"<<endl;    }
};

void x(a &p)
{
    p.w();
}

int main()
{
    b m;
    x(m);       //b
    c n;
    x(n);       //c
    d o;
    x(o);       //d
    return 0;
}

*/














/*

struct a                                              //without virtual method
{
    void w()    {   cout<<"a"<<endl;    }
};

struct b : a
{
    void w()    {   cout<<"b"<<endl;    }
};

struct c : a
{
    void w()    {   cout<<"c"<<endl;    }
};

struct d : c
{
    void w()    {   cout<<"d"<<endl;    }
};

void x(a &p)
{
    p.w();
}

int main()
{
    b m;
    x(m);       //a
    c n;
    x(n);       //a
    d o;
    x(o);       //a
    return 0;
}

*/









/*

class eg                                            //access level
{
    protected :
        int c = 6;
        void test()         {   cout<<c<<"eg"<<endl;     }
    ~eg()
    {
        cout<<"eg dead"<<endl;
    }

};

class fh : public eg
{
    public : 
        void guess()        {   cout<<c<<"fh"<<endl;   test();   }
    ~fh()
    {
        cout<<"fh dead"<<endl;
    }
};

int main()
{
    fh z;
    z.guess();
}

*/














/*

struct du                                           //overloading and overriding
{
    void d()        { cout<<"None"<<endl;   }
    void d(int a)   { cout<<"Error"<<endl;   }
};

struct ef : du
{
    void d(int a)   { cout<<a<<endl;   }
};

int main()
{
    ef z;
    z.du::d();
    z.d(5);
}

*/












/*

struct mn                                           //overriding
{
    void a()  {     cout<<"apple"<<endl;  }
    void b()  {     cout<<"ball"<<endl;   }
    void c()  {     cout<<"cat"<<endl;    }
};

struct xy : mn
{
    void a()  {     cout<<"dog"<<endl;   }
    void c()  {     b();           }
};

int main()
{
    xy z;
    z.a();
    z.b();
    z.c();

    return 0;
}

*/