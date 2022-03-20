#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string str)
{
   // str = clean_string(str);
    if(str.length() < 2)
        return false;
    for(int i=0; i<str.length()/2; i++)
    {
        if(str[i] != str[str.length()-1-i])
            return false;
    }
    return true;
}

int main()
{
    vector<string> test_cases = {"dad", "abc", "wasiteliotstoiletisaw", "dontnod", "s"};
    for(int i=0; i<test_cases.size(); ++i)
    {
        if(!isPalindrome(test_cases[i]))
            test_cases.erase(test_cases.begin() + i);
    }
    for(int i=0; i<test_cases.size();i++){
        cout << test_cases[i] << endl;
    }
    return 0;
}
