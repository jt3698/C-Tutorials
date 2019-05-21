#include <bits/stdc++.h>

int counter[1001];

int main()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1,1000); // define the range

    for(int n=0; n<1000000; ++n){
        counter[distr(eng)]++; // generate numbers
    }

    int minimum=counter[1];
    int maximum=counter[1];

    for(int i=1;i<=1000;i++){
        minimum=std::min(minimum,counter[i]);
        maximum=std::max(maximum,counter[i]);
    }

    std::cout<<maximum-minimum;
}
