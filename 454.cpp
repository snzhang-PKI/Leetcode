#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
    	unordered_map <int,int> mAB, mCD;

    	for (auto a : A)
    	{
    		for (auto b : B)
    		{
    			long long ab = 0LL + a + b;

    			if (mAB.find(ab) == mAB.end())
    			{
    				mAB[ab] = 1;
    			}
    			else
    			{
    				mAB[ab] += 1;
    			}
    		}
    	}
    	int res = 0;

    	for (auto c : C)
    	{
    		for (auto d : D)
    		{
    			long long negcd = 0LL - c - d;

    			if (mAB.find(negcd) != mAB.end())
    			{
    				res += mAB[negcd];
    			}
    		}
    	}
        return res;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	unordered_map <int,int> m;
	for (auto i : m)
	{

	}
	return 0;
}