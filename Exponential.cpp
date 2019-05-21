#include<bits/stdc++.h>
using namespace std;

int expo(int x,int p)
{
    if(p==0)return 1;

    int temp=expo(x,p/2);
    if(p%2==0)return temp*temp;
    return temp*temp*x;
}

int main()
{
    cout<<expo(2,10)<<endl;;
}
