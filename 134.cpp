#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int sumGas = 0;
    	int sumCost = 0;
    	int stationNumber = gas.size();
    	int sum = 0;
    	vector <int> profit ;
    	for (int i = 0; i < stationNumber; i++){
    		profit.push_back(gas[i]-cost[i]);
    		sum += gas[i] - cost[i];
    	}

    	if (sum < 0){
    		return -1;
    	}
    	else{
    		int res = 0;
    		list<int> stack = list<int>(1,0);
    		for (int i = 0; i < stationNumber; i++){

    			if (stack.back()<0){
    				if (profit[i] > 0){
    					stack.push_back(profit[i]);
    					res = i;
    					// continue;
    				}
    				else{
    					// continue;
    				}
    			}
    			else{
    				if (profit[i] + stack.back() >= 0){
    					stack.back() += profit[i];
    					// continue;
    				}
    				else {
    					stack.push_back(profit[i]);
    					res = -1;
    				}
    			}
    			cout<<i<<" "<<res<<endl;
    			cout<<"stack : ";
    			for (auto s:stack){
    				cout<<s<<" ";
    			}
    			cout<<endl;
    		}
    		return res;
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution mysol;
	vector<int> gas = {0};
	vector<int> cost(1,0);
	cout<<mysol.canCompleteCircuit(gas,cost)<<endl;
	return 0;
}