#include <vector>
#include <limits.h>
#include <stack>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
    	// Max -> secondMax
    	int res = 0;
    	int l = height.size();
    	
    	if (l == 0)
    	{
    		return res;
    	}

    	stack<pair<int,int>> s;
    	pair<int,int>bottom = {-1,-1};

    	for (auto h : height)
    	{
    		if (s.empty())
    		{
    			if (h > bottom.first)
    			{
    				bottom = {h,1};
    			}
    			else if (h == bottom.first)
    			{
    				bottom.second += 1;
    			}
    			else
    			{
    				s.push(bottom);
    				bottom = {h,1};
    			}
    		}
    		else
    		{
    			if (h < bottom.first)
    			{
    				s.push(bottom);
    				bottom = {h,1};
    			}
    			else if (h == bottom.first)
    			{
    				bottom.second += 1;
    			}
    			else
    			{
    				while (!s.empty() && s.top().first < h) /* =? */
    				{
    					//filling water!
    					res += bottom.second * (s.top().first - bottom.first);
    					bottom.first = s.top().first;
    					bottom.second += s.top().second;
    					s.pop();
    				}

    				if (!s.empty())
    				{
    					//filling again
    					res += bottom.second * (h - bottom.first);
    					bottom.first = h;
    					bottom.second += 1;
    				}
    				else
    				{
    					bottom = {h,1};
    				}
    			}
    		}
    	}

    	return res;

    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	vector <int> h = {0,5,3,3,5};
	auto r = mySol.trap(h);
	cout<<r<<endl;
	return 0;
}