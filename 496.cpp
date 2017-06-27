#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		unordered_map <int,int> location;
		int l = nums.size();
		for (int i = 0; i < l; i++){
			location[nums[i]] = i;
		}        
		vector <int> res;
		for (auto t : findNums){
			int loc = location[t];
			int val = -1;
			while (loc < l){
				if (nums[loc] > t){
					val = nums[loc];
					break;
				}
				else{
					loc++;
				}
			}
			res.push_back(val);
		}
		return res;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}