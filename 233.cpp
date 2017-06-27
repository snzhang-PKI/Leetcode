/* 233
*
*
*
*
*/

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDigitOne(int m) {
        if (m < 1){
            return 0;
        }
        else if (m <= 9){
            return 1;
        }
        else{
            long long n = m;
            long long mypow = 1;
            int count = 0;
            while (n > mypow -1){
                mypow = mypow * 10;
                count ++;
            }
            mypow = mypow / 10;
            int head = n / mypow;
            int tail = n % mypow;
            //cout<<"head = "<<head<<endl;
            //cout<<"tail = "<<tail<<endl;
            //cout<<"cout = "<<count<<endl;
            if (head == 1) {
                return tail + 1 + (count - 1) * pow (10, count - 2) + countDigitOne(tail);
            }
            else {
                return head * (count - 1) * pow (10, count - 2) + pow (10, count - 1) + countDigitOne(tail);
            }


        }
    }
};

int main(int argc, char **argv)
{
	/* code */
    Solution mysol;
    int input = stoi(argv[1]);
    cout<<mysol.countDigitOne(input)<<endl;
	return 0;
}