#include <iostream>
#include <bitset>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        int head = 31;
        bitset <32> input(num);
        list<int> positionOfOnes = list<int>();
        for (int i = 30; i >= 0; i--){
        	if (input[i]){
        		positionOfOnes.push_back(i);
        		if (input[i+1]){
        			break;
        		}
        	}
        }
        vector <int> fab = vector <int>();
        int prepre = 1;
        fab.push_back(1);
        int pre = 2;
        fab.push_back(2);
        for (int i = 2; i < 32; i++){
        	fab.push_back(fab[i-1]+fab[i-2]);
        }
        int tail = positionOfOnes.back();
        positionOfOnes.pop_back();
        int p = 1;
        int q = fab[tail];
        if (positionOfOnes.size() == 0){
        	return p+q;
        }
        else{
        	while (!positionOfOnes.empty()){
        		head = positionOfOnes.back();
        		positionOfOnes.pop_back();
        		int dis = head - tail;
        		if (dis > 1){
        			p = p + q;
        			if (dis == 2){
        				q = fab[tail] + fab[tail+1];
        			}
        			else {
        				q = fab[dis-2] * fab[tail+1] + fab[dis-3] * fab[tail];
        			}
        		}
        		// form xxx11xxxxx
        		else{
        			p = fab[tail];
        			q = fab[tail+1];
        		}
        		tail = head;
        	}
        }
        return p+q;
    }
};

int main(int argc, char const *argv[])
{
	Solution mysol;
	cout<<mysol.findIntegers()<<endl;
	return 0;
}