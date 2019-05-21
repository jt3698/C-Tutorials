#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    pair<int,int>floaty[50];
    floaty[1].first=10;
    floaty[1].second=20;
    int*address=&floaty[1].first;
    cout<<*address<<"  "<<floaty[1].second<<endl;

    pair<int,int>test(30,40);
    cout<<test.first<<"  "<<test.second<<endl;

    test=make_pair(50,60);
    cout<<test.first<<"  "<<test.second<<endl;

    test=make_pair(70.9,'P');
    cout<<test.first<<"  "<<test.second<<endl;
}
