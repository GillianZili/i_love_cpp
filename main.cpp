#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <random>
#include "my_vector.hpp"
using namespace std;

bool check(myVct& vct1,vector<int>& vct2){
    if(vct1.get_size()!=vct2.size()){
        return false;
    }
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
        int action=rand()%2;
        if(action==1){
            int num=rand()%100;
            vct1.push_back(num);
            vct2.push_back(num);
        }else{
            if(vct1.get_size()&&vct2.size()){
                vct1.pop_back();
                vct2.pop_back();
            }
        }
        
    }
    cout<<"check result: "<<check(vct1,vct2)<<endl;
    return 0;
}
