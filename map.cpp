#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string,int> m;
    m["abc"]=1;
    m["def"]=2;
    m["ghi"]=3;

    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}