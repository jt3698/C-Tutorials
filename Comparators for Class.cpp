#include<bits/stdc++.h>
using namespace std;

struct Data
{
    int A,B,C;
    bool operator<(const Data &other) const{
        if(A>other.A)return true;
        if(A==other.A)return B<other.B;
        return false;
    }
};

set<Data>po;

int main()
{
    for(int i=1;i<=10;i++)for(int o=1;o<=10;o++){
        Data temp;
        temp.A=i;
        temp.B=o;
        temp.C=1;
        po.insert(temp);
    }
   // for(set<Data>::iterator it=po.begin();it!=po.end();it++)cout<<it->A<<" "<<it->B<<" "<<it->C<<"\n";

    Data x;
    x.A=3;x.B=4;x.C=1;
    set<Data>::iterator tmp=po.find(x);
    cout<<tmp->A<<" "<<tmp->B<<" "<<tmp->C<<"\n";
    po.erase(tmp);
    for(set<Data>::iterator it=po.begin();it!=po.end();it++)cout<<it->A<<" "<<it->B<<" "<<it->C<<"\n";

}
