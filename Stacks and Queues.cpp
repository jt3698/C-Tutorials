#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*Notice how you cannot access elements in between, must in front or back (different from array)*/

    //Stack
    stack<int>stk;  /*stk is a stack of integer*/
    for(int i=1;i<=5;i++)stk.push(i); /*Inserting Elements inside stack*/

    cout<<stk.top()<<"\n";  /*Output Last Element to go in --> '5'*/
                        /*If stack is empty, runtime error*/

    /*Safer Way*/
    if(stk.empty())cout<<"Nothing Here\n";
    else cout<<stk.top()<<"\n";

    stk.pop();  /*Get rid of Last Element to go in*/
            /*If stack is empty, runtime error*/

    stk.push(10);  /*Insert another element*/

    cout<<stk.top()<<"\n"; /*Output the Last element to go in --> '10'*/


    //Queue
    queue<int>que;  /*que is a queue of integer*/
    for(int i=1;i<=5;i++)que.push(i); /*Inserting Elements inside queue*/

    cout<<que.front()<<"\n"; /*Output First Element to go in --> '1'*/
                            /*If queue is empty, runtime error*/

    que.pop();  /*Get rid of First Element to go in*/
            /*If queue is empty, runtime error*/

    cout<<que.front()<<"\n"; /*Output the First element to go in --> '2'*/
}
