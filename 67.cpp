#define __USE_MINGW_ANSI_STDIO 0
#include <string>
#include <iostream>
#include <time.h>

using namespace std;


class Solution 
{
public:
    string addBinary(string a, string b) 
    {
    	int n = a.size();
    	int m = b.size();
    	int fill = abs(m-n);
    	int l = max(m,n);
    	int carry = 0;
    	string fillWithZero(fill,'0');
    	string res = "";

    	if (n < m)
    	{
    		a = fillWithZero + a;
    	}	
    	else if (m < n)
    	{
    		b = fillWithZero + b;
    	}
    	cout<<a<<endl;
    	cout<<b<<endl;
    	for (int i = l - 1; i >= 0; i--)
    	{
    		int x = a[i]-'0';
    		int y = b[i]-'0';
    		int r = x + y + carry;
    		cout<<" r = "<<r<<endl;
    		if (r == 0 || r == 1)
    		{
    			res = std::to_string(r+0LL) + res;
    			carry = 0; 
    		}
    		else //(r == 2 || r == 3)
    		{
    			res = std::to_string(r-2LL) + res;
    			carry = 1; 
    		}
    		cout<<res<<endl;
    	}
    	if (carry == 1)
    	{
        	res = '1'+res;
        }
        cout<<res<<endl;
    	return res;
    }
};

int main(int argc, char const *argv[])
{
	clock_t t;
	t = clock();
	cout<<"time : "<<t<<endl;

	Solution mySol;
	mySol.addBinary("111111111111111111111111111111111","1");

	t = clock();
	cout<<"time : "<<t<<endl;
	return 0;
}