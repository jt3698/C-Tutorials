#include<bits/stdc++.h>
using namespace std;

bool cmp1(pair<int,pair<int,int> >A,pair<int,pair<int,int> >B)
{
    if(A.second.second>B.second.second)return true;
    if(A.second.second<B.second.second)return false;

    if(A.second.first>B.second.first)return true;
    if(A.second.first<B.second.first)return false;

    if(A.first>B.first)return true;
    return false;
}

struct Scores ///Not a function, this is a variable type. in python: class.
{
    int s1,s2,s3;
} scores2[1001];

bool cmp2(Scores A,Scores B)
{
    if(A.s3>B.s3)return true;
    if(A.s3<B.s3)return false;

    if(A.s2>B.s2)return true;
    if(A.s2<B.s2)return false;

    return A.s1>B.s2;
}

int main()
{
    int N;
    cin>>N;
    ///First Way: pair
    pair<int,pair<int,int> >scores[1001];

    ///scores[x].first <-- Sesi 1 , scores[x].second.first <-- Sesi 2, scores[x].second.second <-- Sesi 3

    for(int i=0;i<N;i++)cin>>scores[i].first>>scores[i].second.first>>scores[i].second.second;
    sort(scores,scores+N,cmp1);


    ///Second Way: struct/class
    for(int i=0;i<N;i++)cin>>scores2[i].s1>>scores2[i].s2>>scores2[i].s3;
    sort(scores2,scores2+N,cmp2);
}
