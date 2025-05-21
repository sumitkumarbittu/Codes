
#include<iostream>

using namespace std;


//pairs

#include<utility> //for pairs

void explainPair() {
	pair<int, int> p = {1, 3};
	cout << p.first <<" " << p.second;
	pair<int, pair<int, int>> q = {1, {3, 4}};
	cout << q.first <<" " <<q.second.second << " " << q.second.first;
	pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
	cout << arr[1].second;
}


//vectors

#include<vector> //for vector

void explainVector () {
	vector<int> v;
	v.push_back(1);
	v.emplace_back(2);

	vector<pair<int, int> > vec;
	vec.push_back( {1,2} );
	vec.emplace_back(1, 2);

	vector<int> v1(5, 100);		//{100, 100, 100, 100, 100}

	vector<int> v2(5);			//{0, 0, 0, 0, 0}
 
	vector<int> v3(5, 20);		//{20, 20, 20, 20, 20}
	
	vector<int> v4(v3);			// copy elements of v3 to new vector v4

	vector<int>:: iterator it = v.begin();
	it++;
	cout <<  *it << endl;

	vector<pair<int, int> >:: iterator it1 = vec.begin();
	it1++;
	cout <<  it1->first << endl;

	auto it2 = v1.begin();
	it2+=2;
	cout <<  *it << endl;

	vector<int>:: iterator it3 = v.end();
	vector<int>:: iterator it4 = v.rend();
	vector<int>:: iterator it5 = v.rbegin();

	cout << v[0] << " " << v.at(0) << endl;
	cout << v.back() << endl;

	for (vector<int>:: iterator it6 = v2.begin(); it6 != v2.end(); it6++) {
	cout << *(it6) << endl;

	for(auto it7 = v4.begin(); it7 != v4.end(); it7++) {
	cout << *(it7) << endl;

	for (auto it : v) {
		cout << it << " ";		

	// {10, 20, 12, 23}
	v.erase(v.begin()+1);		// {10, 12, 23}

	// {10, 20, 12, 23, 35}
	v.erase(v.begin() + 2, v.begin() + 4);		//{10, 20, 35}

	// Insert function

	vector<int> v(2, 100);			//{100, 100}

	v.insert(v.begin(), 300);		//{300, 100, 100}

	v.insert(v.begin() + 1, 2, 10);	// {300, 10, 10, 100, 100}

	vector<int> copy(2,50);			// {50, 50}

	v.insert(v.begin(), copy.begin(), copy.end()); 		// {50, 50, 300, 10, 10, 100, 100}

	cout << v.size(); 			// 2

	v. pop_back(); 			// {10}

	// v1 -> {10, 20}
	// v2 -> {30, 40}
	v1.swap(v2); 				// v1 -> {30, 40} , v2 → {10, 20} 

	v.clear(); 				// erases the entire vector

	cout << v.empty();

}


//Lists

#include<list>			//for list

void explainList() {
	list<int> ls;

	ls.push_back(2); 			// {2} 

	ls.emplace_back(4); 		// {2, 4} 

	ls.push_front (5); 			// {5, 2, 4};

	ls.emplace_front(); 		//{2, 4};

	// rest functions same as vector
	// begin, end, rbegin, rend, clear, insert, size, swap

}


void explainMap() {
	map<int, int> mpp;

	map<int, pair<int, int>> mpp2;
	map< pair<int, int>, int> mpp3;

	mpp[1] = 2;
	mpp.emplace({3, 1});
	mpp.insert ({2, 4});
	mpp[{12,3}] = 10;
	{
		{1, 2}
		{2, 4}
		{3, 1}
	}

	for(auto it : mpp) {
	cout << it.first <<" " << it.second << endl;
	cout < mpp[1];
	cout < mpp[5];

	auto it = mpp.find(3);
	cout < *(it).second;
	auto it = mpp.find(5);

	// This is the syntax
	auto it = mpp. lower_bound (2) ;
	auto it = mpp. upper_bound (3);
	// erase, swap, size, empty, are same as above
}



int main() {
	//explainPair();
	//explainVector();
	explainList();
	return 0;

}