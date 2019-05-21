#include<bits/stdc++.h>
using namespace std;

int weights[101];
int prices[101];
int N;
int store[101][1001];

int dp(int n,int weight_now)
{
    if(n==N+1)return 0;

    if(store[n][weight_now]!=-1)return store[n][weight_now];

    if(weight_now+weights[n]>1000)return dp(n+1,weight_now);

    return store[n][weight_now]=max( dp(n+1,weight_now+weights[n]) + prices[n] , dp(n+1,weight_now) );
}

int main()
{
    memset(store,-1,sizeof(store));

    cin>>N;
    for(int i=1;i<=N;i++)cin>>weights[i]>>prices[i];

    cout<<dp(1,0);
}
