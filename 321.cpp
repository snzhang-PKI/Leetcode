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
struct optimalResult{
	//index of the first number in value
	int head;
	//largest value possible
	list<int> value;
	optimalResult (int h = INT_MAX , list<int> v  = list<int>(), int r = -1):head(h),value(v){}
};
void printlist(list<int> l){
	for (auto i:l){
		cout<<i<<" ";
	}
	cout<<endl;
}

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    	clock_t t;
		t = clock();
		cout<<t<<endl;
    	vector<int> res;
        //vector<vector<vector<int>>> T;
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

        // for (int i = 0; i < n; i++){
        // 	for (int j = i ; j < n ; j++){
        // 		for (int r = i; r <= j; r++){
        // 			cout<<nums1[r]<<" ";
        // 		}
        // 		cout<<"max : "<<nums1[A[i][j]]<<endl;
        // 	}
        // }
        vector <vector<vector<optimalResult>>> T(n+1, vector <vector<optimalResult>> (m+1,vector <optimalResult>(k+1,optimalResult())));
        for (int i = 0; i< n+1 ;i++){
        	for (int j = 0; j < m+1; j++){
        		T[i][j][0] = optimalResult();
        	}
        };
        // int in = 0;
        // for (auto i:T){
        // 	int jn = 0;
        // 	for (auto j:i){
        // 		int tn = 0;
        // 		for (auto t : j){
        // 			cout<<in<<" "<<jn<<" "<<tn<<endl;
        // 			tn++;
        // 		}
        // 		jn++;
        // 	}
        // 	in++;
        // }
        // cout<<"+++++++++++++++"<<endl;
        // i = n
        for (int j = m; j >= 0; j--){
        	for (int t = 1; t <= k; t++){
        		if (t+j > m){
        			// cout<<n<<" "<<j<<" "<<t<<endl;
        			// cout<<T[n][j][t].head<<endl;
        			// cout<<T[n][j][t].value<<endl;
        			// cout<<T[n][j][t].row<<endl;
        			T[n][j][t] = optimalResult();
        		}
        		else {
        			// cout<<n<<" "<<j<<" "<<t<<endl;
        			int head = B[j][m-t];
        			list<int> value =  T[n][head+1][t-1].value;
        			value.push_front(nums2[head]);
        			T[n][j][t] = optimalResult(head,value);
        		}
        	}
        }
        // j = m
        for (int i = n; i >= 0; i--){
        	for (int t = 1; t <= k; t++){
        		// cout<<i<<" "<<t<<endl;
        		if (t+i > n){
        			// cout<<n<<" "<<j<<" "<<t<<endl;
        			// cout<<T[n][j][t].head<<endl;
        			// cout<<T[n][j][t].value<<endl;
        			// cout<<T[n][j][t].row<<endl;
        			T[i][m][t] = optimalResult();
        		}

        		else {
        			
        			int head = A[i][n-t];
        			list<int> value =  T[head+1][m][t-1].value;
        			value.push_front(nums1[head]);
        			
        			T[i][m][t] = optimalResult(head,value);

        		}
        		// cout<<i<<" "<<t<<endl;
        	}

        }
        // cout<<"123"<<endl;
        t = clock();
		cout<<t<<endl;
        for (int i = n-1; i >= 0 ;i--){
        	for (int j = m-1; j >= 0; j--){
        		for (int t = 1; t <= k; t++){

        			if ( m+n < t+i+j){
        				continue;
        			}
        			// cout<<"i = "<<i<<" j = "<<j<<" t = "<<t<<endl;
        			int first = A[i][min(n+m-t-j,n-1)];
        			int second = B[j][min(n+m-t-i,m-1)];
					// cout<<i<<j<<t<<endl;
					// cout<<"first = "<<first<<" second = "<<second<<endl;

        			if (nums1[first] > nums2[second]){
        				// cout<<"C1"<<endl;

        				int head = first;
        				list <int> value;
        				if (t > 1){
        					value = T[head+1][j][t-1].value;
        				}
        				else{
        					value = list<int>();
        				}
        				value.push_front(nums1[head]);
        				T[i][j][t] = optimalResult(head,value);
        			}
        			else if (nums1[first] < nums2[second]){
        				// cout<<"C2"<<endl;

        				int head = second;
        				list<int> value;
        				if(t>1){
        					value =T[i][head+1][t-1].value;
        				}
        				else{
        					value = list<int>();
        				}
        				value.push_front(nums2[head]);
        				T[i][j][t] = optimalResult(head,value);
        				// if (i ==5 && j ==8 && t==2){
        				// 	cout<<"first = "<<first<<" second = "<<second<<endl;
        				// 	printlist(T[i][j][t].value);
        				// }
        				
        			}
        			else{
        				// cout<<"C3"<<endl;
        				auto branch1 = T[first+1][j][t-1];
        				auto branch2 = T[i][second+1][t-1];

        				if (branch1.value > branch2.value){
	        				int head = first;
	        				list<int> value;
	        				if (t>1){
	        					value =  T[head+1][j][t-1].value;
	        				}
	        				else{
	        					value = list<int>();
	        				}
	        				value.push_front(nums1[head]);
	        				T[i][j][t] = optimalResult(head,value);
        				}
        				else {
		        			int head = second;
		        			list<int> value;
		        			if (t > 1){
	        					value =T[i][head+1][t-1].value;
		        			}
		        			else {
		        				value = list <int>();
		        			}
	        				value.push_front(nums2[head]);
	        				T[i][j][t] = optimalResult(head,value);
        				}
        			}
        			// cout<<"i = "<<i<<" j = "<<j<<" t = "<<t<<" "<<endl;
        			// printlist(T[i][j][t].value);
        		}
        	}
        }
        list<int> resList = T[0][0][k].value;

      	for (auto i : resList){
      		res.push_back(i);
      	}
      	for (auto i : res){
      		cout<<i;
      	}
      	cout<<endl;
      	t = clock();
		cout<<t<<endl;
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