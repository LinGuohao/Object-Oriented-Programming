#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
 
int main()
{
    vector<int>obj;//����һ�������洢���� int
    for(int i=0;i<10;i++) // push_back(elem)���������������� 
    {
        obj.push_back(i);
        cout<<obj[i]<<",";    
    }
 
    for(int i=0;i<5;i++)//ȥ���������һ������ 
    {
        obj.pop_back();
    }
 
    cout<<"\n"<<endl;
 
    for(int i=0;i<obj.size();i++)//size()������ʵ�����ݸ��� 
    {
        cout<<obj[i]<<",";
    }
 
    return 0;
}
