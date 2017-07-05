// unordered_set is better than unordered_map here

#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
 		vector <int> res;
 		unordered_set <int> tmp(nums1.begin(), nums1.end());
 		for (auto n : nums2)
 		{
 			if (tmp.find(n) != tmp.end())
 			{
 				tmp.erase(n);
 				res.push_back(n);
 			}
 		}
 		return res;       
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}