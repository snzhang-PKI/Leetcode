#include <string>
#include <iostream>

using namespace std;

class Solution 
{
public:
    bool isValid(string s) 
    {
        if (s == "")
        {
        	return true;
        }
        else if (s.find("()") != string::npos)
        {
        	s.erase(s.find("()"), 2);
        	return isValid(s);
        }
        else if (s.find("[]") != string::npos)
        {
        	s.erase(s.find("[]"), 2);
        	return isValid(s);
        }
        else if (s.find("{}") != string::npos)
        {
        	s.erase(s.find("{}"), 2);
        	return isValid(s);
        }
        else{
        	return false;
        }
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}