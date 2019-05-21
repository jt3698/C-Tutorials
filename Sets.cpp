#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int>A;

    ///Inserting a value to a set
    A.insert(1);
    A.insert(5);
    A.insert(3);

    ///Output with Iterator
    set<int>::iterator it;
    for(it=A.begin();it!=A.end();it++)cout<<*it<<endl;
}
