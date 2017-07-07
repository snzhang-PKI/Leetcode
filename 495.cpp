#include <vector>
#include <iostream>
#include <list>
#include <stack>

using namespace std;


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

    	if (timeSeries.empty() || duration == 0)
    	{
    		return 0;
    	}

        int i = 0;
        int l = timeSeries.size();
        list<int> stack;
        stack.push_back(timeSeries[0]);
        int res = 0;
        int terminateTime = timeSeries[0] + duration;
        while (i < l)
        {
        	while (i < l && timeSeries[i] <= terminateTime)
        	{
        		stack.push_back(timeSeries[i]);
        		terminateTime = timeSeries[i] + duration;
        		i++;
        	}
        	res += terminateTime - stack.front();

        	if (i == l)
        	{
        		cout<<"touch down"<<endl;
        		break;
        	}
        	else
        	{
        		cout<<"keep going"<<endl;
        		stack.clear();
        		stack.push_back(timeSeries[i]);
        		terminateTime = timeSeries[i] + duration;
        		continue;
        	}
        }
    	return res;  
    }
    
};

int main(int argc, char const *argv[])
{
	/* code */
	vector <int> v = {1};
	Solution mySol;
	cout<<mySol.findPoisonedDuration(v,1000)<<endl;
	return 0;
}