#include<iostream>
#include<map>

using namespace std;

int main()
{
   cout<<"Basic Maps"<<endl;
   map <int,int> counting_basket;
   counting_basket[2]++;
   counting_basket[2]+=2;
   cout<<counting_basket.at(2)<<"  "<<counting_basket[5]<<endl; /*Accessed Something Never Accessed Before*/
   cout<<counting_basket.size()<<endl;

   cout<<endl<<"Looping through Map with Iterator"<<endl;
   for(map<int,int>::iterator counter=counting_basket.begin();counter!=counting_basket.end();counter++){
        cout<<counter->first<<"  "<<counter->second<<endl;
   }

   cout<<endl<<"Inserting New Values"<<endl;
   counting_basket.insert(pair<int,int>(4,44));
   counting_basket[8]=88;
   cout<<"4  "<<counting_basket.at(4)<<endl;
   cout<<"8  "<<counting_basket.at(8)<<endl;

   cout<<endl<<"Erasing Values"<<endl;
   std::map<int,int>::iterator it = counting_basket.find(4);

   cout<<"Before"<<endl;
   for(map<int,int>::iterator counter=counting_basket.begin();counter!=counting_basket.end();counter++){
        cout<<counter->first<<"  "<<counter->second<<endl;
   }
   cout<<endl<<"Here: "<<it->first<<"  "<<it->second<<endl;
   counting_basket.erase(it);

   cout<<endl<<"After"<<endl;
   for(map<int,int>::iterator counter=counting_basket.begin();counter!=counting_basket.end();counter++){
        cout<<counter->first<<"  "<<counter->second<<endl;
   }

   cout<<endl<<"Clear the Map"<<endl;
   counting_basket.clear();
   cout<<counting_basket.size()<<endl;

   cout<<endl<<"Check if Empty"<<endl;
   cout<<"Is it empty? "<<counting_basket.empty()<<endl;
   counting_basket.insert(pair<int,int>(4,44));
   cout<<"Is it empty? "<<counting_basket.empty()<<endl;

   cout<<endl<<"Multimaps"<<endl;
   multimap<int,int>multi;
   for(int i=1;i<=5;i++)multi.insert(pair<int,int>(i,i*10));
   multi.insert(pair<int,int>(3,25));
   for(map<int,int>::iterator counter=multi.begin();counter!=multi.end();counter++){
        cout<<(*counter).first<<"  "<<counter->second<<endl;
   }
   map<int,int>::iterator finding=multi.find(3);
   cout<<finding->second<<endl;
   for(int i=1;i<=2;i++)finding++;
   cout<<(*finding).second<<endl;
}
