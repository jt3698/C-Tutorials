#include<bits/stdc++.h>
using namespace std;

class BodyMassIndex     ///Usually in header file(separate)
{
    public:
        ///Default Constructor
        BodyMassIndex();

        ///Overload Constructor
        BodyMassIndex(string,int,double);

        ///Destructor
        ~BodyMassIndex();

        ///Accessors
        string get_new_name() const;
        int get_new_height() const;
        double get_new_weight() const;

        void setName(string x)
        {
            new_name=x;
        }

    private:
        string new_name;
        int new_height;
        double new_weight;
};

BodyMassIndex::BodyMassIndex(){
    new_height=0;
    new_weight=0.0;
}
BodyMassIndex::BodyMassIndex(string name,int height,double weight){
    new_name=name;
    new_height=height;
    new_weight=weight;
}
BodyMassIndex::~BodyMassIndex(){

}
string BodyMassIndex::get_new_name() const{
    return new_name;
}
int BodyMassIndex::get_new_height() const{
    return new_height;
}
double BodyMassIndex::get_new_weight() const{
    return new_weight;
}


int main()
{
    string name;
    int height;
    double weight;

    cout<<"Enter Your Name: ";
    cin>>name;
    cout<<"Enter Your Height: ";
    cin>>height;
    cout<<"Enter Your Weight: ";
    cin>>weight;

    BodyMassIndex Jason(name,height,weight);
    cout<<Jason.get_new_name()<<' '<<Jason.get_new_height()<<' '<<Jason.get_new_weight()<<endl;

    cout<<"Enter Your New Name: ";
    cin>>name;
    Jason.setName(name);
    cout<<"New-New Name: "<<Jason.get_new_name()<<endl;

    return 0;
}
