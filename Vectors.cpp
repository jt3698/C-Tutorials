#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    cout<<"Basic Vectors and Pushing Back(Adding)"<<endl;
    vector<int>hello(10);
    for(int i=0;i<hello.size();i++)hello[i]=i;

    cout<<hello.at(1)<<"  "<<hello.at(2)<<endl;
    hello.push_back(300);
    cout<<hello.size()<<"  "<<hello.at(0)<<endl;

    for(int i=0;i<hello.size();i++)cout<<hello.at(i)<<"  ";
    cout<<endl;

    cout<<endl<<"Removing based on Position"<<endl;
    for(int i=1;i<=3;i++)hello.erase(hello.begin());  /*Erasing in which position but basically address*/
    for(int i=0;i<hello.size();i++)cout<<hello.at(i)<<"  ";
    cout<<endl;

    for(int i=1;i<=3;i++)hello.erase(hello.begin()+i);  /*Erasing in which position but basically address*/
    for(int i=0;i<hello.size();i++)cout<<hello.at(i)<<"  ";
    cout<<endl;

    /*From <algorithm> library*/
    cout<<endl<<"Removing based on Value"<<endl;
    hello.push_back(9);
    hello.erase(remove(hello.begin(),hello.end(),300),hello.end());
    for(int i=0;i<hello.size();i++)cout<<hello.at(i)<<"  ";
    cout<<endl;

    hello.erase(remove(hello.begin(),hello.end(),9),hello.end());
    for(int i=0;i<hello.size();i++)cout<<hello.at(i)<<"  ";
    cout<<endl;

    cout<<endl<<"Clear the Vector"<<endl;
    hello.clear();
    cout<<hello.size()<<endl;
    for(int i=0;i<hello.size();i++)cout<<hello.at(i)<<"  ";

    cout<<endl<<"Check if Empty"<<endl;
    cout<<"Is it empty? "<<hello.empty()<<endl;
    hello.push_back(1);
    cout<<"Is it empty? "<<hello.empty()<<endl;
}
