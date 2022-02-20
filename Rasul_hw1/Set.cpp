#include <vector>
#include <iostream>
#include "Set.h"

Set::Set() {}

void Set::InsertElement(int a){
    vec.push_back(a);
}

void Set::RemoveElement(int a){
    int ind=0;
        for(unsigned int i=0;i<vec.size();i++){
        if(a==vec[i]){
            ind =i;
        }
    }
    vec[ind]=vec[vec.size()-1];
    vec.pop_back();
}

bool Set::IsEmpty(){
return vec.size()==0;
}

bool Set::IsContain(int a){
bool l = false;
for(unsigned int i=0;i<vec.size();i++){
        if(a==vec[i]){
            l=true;
        }
}
return l;
}

int Set::RandomElement(){
return vec[0];
}

int Set::LargestElement(){
    int maxi=vec[0],ind=0;
for(unsigned int i=1;i<vec.size();i++){
if(vec[i]>maxi){
    maxi=vec[i];
    ind=i;
}
}

return vec[ind];
}
void Set::Print(){
        for( unsigned int i = 0; i < vec.size(); i++ )
			{
				std::cout << "Element[" << i << "] = " << vec[i] << std::endl;
			}
			std::cout << std::endl;
    }
