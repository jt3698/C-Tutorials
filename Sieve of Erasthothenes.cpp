#include<stdio.h>
#include<stdbool.h>

 bool prime[100000001];
 int primelist[5800000];
 int counter=0;
 int less_than=100000000;

 void sieve()
 {
     int i,o;
     for(i=2;i<=less_than;i++)prime[i]=true;
     prime[1]=false;
     for(i=1;i*i<=less_than;i++)if(prime[i])for(o=i*i;o<=less_than;o+=i)prime[o]=false;
     for(i=1;i<=less_than;i++)if(prime[i]){counter++;primelist[counter]=i;}
 }

int main()
{
    sieve();
    printf("%d %d",counter,primelist[counter]);
}
