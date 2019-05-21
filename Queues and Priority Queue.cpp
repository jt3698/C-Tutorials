#include<queue>
#include<iostream>

using namespace std;

int main()
{
    cout<<"Basic Queues"<<endl;
    queue<int>places;
    for(int i=1;i<=5;i++)places.push(i);

    places.pop();  /*First In First Out*/

    cout<<places.front()<<endl; /*Output First one*/
    cout<<places.back()<<endl;  /*Output Last one*/

    cout<<endl<<"Priority Queue"<<endl;

    priority_queue<int>biggest;  /*Sort Maximum to Minimum*/
    biggest.push(10);
    biggest.push(40);
    biggest.push(5);

    for(int i=0;i<3;i++){
        cout<<biggest.top()<<"  ";
        biggest.pop();
    }
}

