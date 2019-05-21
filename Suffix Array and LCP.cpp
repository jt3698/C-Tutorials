#include<bits/stdc++.h>
using namespace std;

string text;
int N;
int suffix_array[100001],lcp_array[100001],idx[100001];

bool cmp(pair<int,pair<int,int> >A,pair<int,pair<int,int> >B)
{
    if(A.second.first<B.second.first)return true;
    if(A.second.first==B.second.first)return A.second.second<B.second.second;
    return false;
}

void build_suffix_array()
{
    pair<int,pair<int,int> >suffixes[100001];
    for(int i=0;i<N;i++){
        suffixes[i].first=i;
        suffixes[i].second.first=text[i]-'a';
        suffixes[i].second.second=-1;
        if(i+1<N)suffixes[i].second.second=text[i+1]-'a';
    }
    sort(suffixes,suffixes+N,cmp);

    for(int k=4;k<2*N;k*=2){
        int rank_now=0;
        int prev_rank=suffixes[0].second.first;
        suffixes[0].second.first=rank_now;
        idx[suffixes[0].first]=0;

        for(int i=1;i<N;i++){
            if(prev_rank==suffixes[i].second.first && suffixes[i].second.second==suffixes[i-1].second.second)
                suffixes[i].second.first=rank_now;
            else{
                prev_rank=suffixes[i].second.first;
                suffixes[i].second.first=++rank_now;
            }
            idx[suffixes[i].first]=i;
        }

        for(int i=0;i<N;i++){
            int next_index=suffixes[i].first+k/2;
            suffixes[i].second.second=-1;
            if(next_index<N)suffixes[i].second.second=suffixes[idx[next_index]].second.first;
        }

        sort(suffixes,suffixes+N,cmp);
    }
    for(int i=0;i<N;i++)suffix_array[i]=suffixes[i].first;
    return;
}

void build_lcp_array()
{
    for(int i=0;i<N;i++)idx[suffix_array[i]]=i;
    int k=0;
    for(int i=0;i<N;i++){
        if(idx[i]+1==N){
            k=0;
            continue;
        }
        int j=suffix_array[idx[i]+1];
        while(j+k<N && i+k<N && text[j+k]==text[i+k])k++;

        lcp_array[idx[i]]=k;
        if(k>0)k--;
    }
    return;
}

int main()
{
    cin>>text;
    N=text.size();
    build_suffix_array();
    build_lcp_array();

    for(int i=0;i<N;i++)printf("%d ",suffix_array[i]);
    printf("\n");
    for(int i=0;i<N;i++)printf("%d ",lcp_array[i]);
    printf("\n");
}
