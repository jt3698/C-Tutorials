#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int A[1001];

int binarysearch(int left, int right, int to_find)
{
	if(left>=right)return left;
	int mid=(left+right)/2;
	if(A[mid]==to_find)return mid;
	if(A[mid]<to_find)return binarysearch(mid+1,right,to_find);
	if(A[mid]>to_find)return binarysearch(left,mid,to_find);
}

int main()
{
    int i;int x;
    cin>>x;
    for(int i=1;i<=x;i++)scanf("%d",&A[i]);
	sort(A+1,A+x+1);
	int temp;
	cin>>temp;
    printf("%d\n",binarysearch(1,x,temp));
    return 0;
}
