#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include "limits.h"
#include <math.h>
#include "time.h"

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector <int> res;
		int n = nums1.size();
        int m = nums2.size();
        vector <vector<int>> A (n, vector<int>(n, -1));	//A[i][j] is the position of the first largest number from nums1[i:j]
        vector <vector<int>> B (m, vector<int>(m, -1)); //B[i][j] is the position of the first largest number from nums2[i:j]
        // calculate A[][]
        for (int l = 1; l<=n; l++){						// l = j - i + 1
        	for (int i = 0; i < n-l+1 ;i++){
        		int j = i + l -1;

        		if (l == 1){
        			A[i][j] = i;
        		}
        		else {
        			int l = A[i][i];
        			int r = A[i+1][j];

        			if (nums1[r] > nums1[l]){
        				A[i][j] = r;
        			}
        			else {
        				A[i][j] = l;
        			}
        		}
        	}
        }
        // calculate B[][]
        for (int l = 1; l<=m; l++){						// l = j - i + 1
        	for (int i = 0; i < m-l+1 ;i++){
        		int j = i + l -1;

        		if (l == 1){
        			B[i][j] = i;
        		}
        		else {
        			int l = B[i][i];
        			int r = B[i+1][j];

        			if (nums2[r] > nums2[l]){
        				B[i][j] = r;
        			}
        			else {
        				B[i][j] = l;
        			}
        		}
        	}
        }
        vector <vector<int>> maxFromNums1;
        vector <vector<int>> maxFromNums2;
        int maxLengthOfNums1 = min(n,k);
        int minLengthOfNums1 = max(k-m,0);
        int maxLengthOfNums2 = min(m,k);
        int minLengthOfNums2 = max(k-n,0);

        vector <int> temp;
        if (maxLengthOfNums1 < n){
	        int frontier = 0;
	        int tail = n - maxLengthOfNums1;
	        while (tail < n){
	        	// cout<<"frontier = "<<frontier<<" " 
	        	int head = A[frontier][tail];
	        	temp.push_back(nums1[head]);
	        	frontier = head + 1;
	        	tail ++;
	        }
	    }
	    else temp = nums1;
	    maxFromNums1.push_back(temp);

	    auto it = temp.begin();
	    for (int i = maxLengthOfNums1; i => minLengthOfNums1; i--){
	    	
	    }





        for (auto i:temp){
        	cout<<i<<' ';
        }
        cout<<endl;





















        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	vector <int> nums1 = {4,6,9,1,0,6,3,1,5,2,8,3,8,8,4,7,2,0,7,1,9,9,0,1,5,9,3,9,3,9,7,3,0,8,1,0,9,1,6,8,8,4,4,5,7,5,2,8,2,7,7,7,4,8,5,0,9,6,9,2};

	vector <int> nums2 = {9,9,4,5,1,2,0,9,3,4,6,3,0,9,2,8,8,2,4,8,6,5,4,4,2,9,5,0,7,3,7,5,9,6,6,8,8,0,2,4,2,2,1,6,6,5,3,6,2,9,6,4,5,9,7,8,0,7,2,3};
	
	mySol.maxNumber(nums1,nums2,60);
	// vector <int> v1 = {1,2,9};
	// vector <int> v2 = {2,1,3};
	// cout<<(v1<v2)<<endl;

	return 0;
}