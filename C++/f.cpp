#include<iostream>

using namespace std;

class Address
{
    int h_no, pincode;
    string street_name, location, city,state,country;
    public : 
        void get()
        {
            cout<<"House No. ";
            cin>>h_no;
            cout<<"Street Name : ";
            getline(cin,street_name);
            cout<<"Location : ";
            getline(cin,location);
            cout<<"City : ";
            getline(cin,city);
            cout<<"State : ";
            getline(cin,state);
            cout<<"Country : ";
            getline(cin,country);
            cout<<"Pincode : ";
            cin>>pincode;
        }

        void show()
        {
            cout<<h_no;
        }
};

int main()
{
    
}