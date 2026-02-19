#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <random>
#include "MyVector2.hpp"
using namespace std;

bool check(myVct& vct1,vector<int>& vct2){
    for(int i=0;i<vct2.size();i++){
        if(vct1.get_value(i)!=vct2[i]){
            return false;
        }
    }
    return true;
}


int main()
{
    myVct vct1;
    vector<int> vct2;
    srand(time(0));
    for(int i=0;i<10000;i++){
        int num=rand();
        vct1.push_back(num%100);
        vct2.push_back(num%100);
    }
    cout<<"check push_back: "<<check(vct1,vct2)<<endl;
    for(int i=0;i<6000;i++){
        vct1.pop_back();
        vct2.pop_back();
    }
    cout<<"check pop_back: "<<check(vct1,vct2)<<endl;
    return 0;
}
