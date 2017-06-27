#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        cout<<num<<endl;
        if (num == 0 || num == 1){
            return true;
        }
        long long n = num;
        n = abs(n);
        if (n%2 && n%3 && n%5){
        	return false;
        }
        else {
        	if (n%2 == 0){
                cout<<"/2"<<endl;
        		return isUgly(n/2);
        	}
        	else if (n%3 == 0){
                cout<<"/3"<<endl;
        		return isUgly(n/3);
        	}
        	else{
                cout<<"/5"<<endl;
        		return isUgly(n/5);
        	}
        }

    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
    cout<<mySol.isUgly(-2147483648)<<endl;
	return 0;
}