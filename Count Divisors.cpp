#include<bits/stdc++.h>

bool prime[10001];
int less_than=10000;
int counter=0;
int primelist[2000];

void sieve()
{
    int i,o;
    for(i=2;i<=less_than;i++)prime[i]=true;
    prime[1]=false;
    for(i=1;i*i<=less_than;i++)if(prime[i])for(o=i*i;o<=less_than;o+=i)prime[o]=false;
    for(i=1;i<=less_than;i++)if(prime[i]){counter++;primelist[counter]=i;}
}

int divisor_old(int x)
{
     if(prime[x])return 2;
     int answer=1;
     int i;
     int temp;
     for(i=1;i<=counter;i++){
        temp=1;
        if(x==1)break;
        while(x%primelist[i]==0){
            x/=primelist[i];
            temp++;
        }
        answer*=temp;
     }
     return answer;
}

int divisor(int x)
{
    int answer=0,i;
    for(i=1;i*i<=x;i++)if(x%i==0)answer++;
    i--;
    if(i*i==x)return 2*answer-1;
    return 2*answer;
}
int main()
{
    sieve();
    int i;
    for(i=1;i<=100;i++)printf("%d-  %d-%d\n",i,divisor_old(i),divisor(i));

    return 0;
}
