#include <iostream>
#include "limits.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x != 0)
        {
        	res = res * 10 + x % 10;
        	if (res < INT_MIN || res > INT_MAX)
        	{
        		return 0;
        	}
        	x = x / 10;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	cout<<mySol.reverse(INT_MAX)<<endl;
	// cout<<-123%10<<endl;
	return 0;
}