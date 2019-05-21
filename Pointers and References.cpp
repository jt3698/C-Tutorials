#include<iostream>

using namespace std;

int addition(int x,int y)
{
    return x+y;
}
int subtraction(int x,int y)
{
    return x-y;
}

int operation(int x,int y,int (*the_thing)(int, int))
{
    return the_thing(x, y);
}

int main()
{
    cout<<"Pointers to Pointers"<<endl;
    int x = 5;
    int *y = &x;
    int *(*z) = &y;
    cout<<*(*z)<<endl<<endl;

    cout<<"Basic Pointers"<<endl;
    int health=80;
    int *health2=&health;
    int *health3=health2;

    //health3+=20;
    *health2+=20;
    cout<<&health<<"  "<<health2<<"  "<<*health3<<"  "<<health<<endl<<endl;

    cout<<"Array Pointers"<<endl;
    int array1[]={1,2,3,4,5};   /*Array is already a pointer*/
    int *pointer=array1+1;      /*Set pointer to address of 2nd indeex inside arrat*/
    *pointer+=200;
    *(pointer+3)=300;   /*Set Value at new address*/

    cout<<array1[0]<<" "<<array1[1]<<" "<<array1[2]<<" "<<array1[3]<<" "<<array1[4]<<endl;

    cout<<0[array1]<<" "<<1[array1]<<" "<<2[array1]<<" "<<3[array1]<<" "<<4[array1]<<endl<<endl;

    cout<<"Function Pointers"<<endl;
    int (*add)(int,int)=addition;
    cout<<add(6,7)<<endl;
    cout<< operation(5, 5, add)<<endl;
    cout<< operation(8, 5, subtraction)<<endl;
}
