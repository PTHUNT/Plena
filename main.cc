#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>  
using namespace std;

void dowork(string str)
{
    unordered_map<char, int> charcount;
    for(int i = 0; i < str.length(); i++)
    {
        charcount[str[i]]++;
    }
    for(int i = 0; i < str.length(); i++)
    {
       if(charcount[str[i]] == 1)
       {
           cout << str[i] << '\n';
           break;
       }
       
    }
    vector<int> vec;
    auto itr = charcount.begin();
    while(itr !=charcount.end())
    {
        vec.push_back(itr->second);
        itr++;
    }
    
    std::sort(vec.begin(), vec.end());
    
    string newstr;
   
    for(int j = 0; j < vec.size(); j++)
    {
       auto itr2 = charcount.begin();
       while(itr2 !=charcount.end()) 
       {
           if(itr2->second == vec[j])
           {
               for(int k =0; k <vec[j]; k++) newstr+=itr2->first;
               charcount.erase(itr2);
               
           }
           itr2++;
           
       }
    }
    
    cout << newstr << "\n";
     
    
}

int main()
{
    dowork("bubble");

    return 0;
}
