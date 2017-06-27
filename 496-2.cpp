// 这个题目用stack解决应该是更高效的 O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <time.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		unordered_map <int,int> resHash;
		stack <int> s;
		for (auto n : nums){
			while (!s.empty() && n > s.top()){
				resHash[s.top()] = n;
				s.pop();
			}
			s.push(n);
		}
		vector <int> res;
		for (auto m : findNums){
			if (resHash.find(m) != resHash.end()){
				res.push_back(resHash[m]);
			}
			else {
				res.push_back(-1);
			}
		}
		return res;
    }
};

class Solution2 {
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
	
	vector <int> v1;
	for (int i = 9999; i > 0; i--){
		v1.push_back(i);
	}
	v1.push_back(10000);
	vector <int> v2 = v1;
	Solution mySol;
	Solution2 mySol2;
	clock_t t;
	t= clock();
	cout<<t<<endl;
	mySol.nextGreaterElement(v1,v2);
	t= clock();
	cout<<t<<endl;
	mySol2.nextGreaterElement(v1,v2);
	t= clock();
	cout<<t<<endl;

	return 0;
}