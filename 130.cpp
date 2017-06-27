#include <iostream>
#include <vector>
#include <list>

using namespace std;



class Solution {
public:
	void solve(vector<vector<char>>& board) 
	{
		int m = board.size();

		if (m == 0)
		{
			return;
		}
		else 
		{
			int n = board[0].size();

			if (n == 0)
			{
				return;
			}
			else 
			{
				list <pair<int,int>> bfsQueue;
				for (int i = 0; i < n; i++)
				{
					if (board[0][i] == 'O')
					{
						board[0][i] = 'I';
						bfsQueue.push_back(make_pair(0,i));
					}
					if (board[m-1][i] == 'O')
					{
						board[m-1][i] = 'I';
						bfsQueue.push_back(make_pair(m-1,i));
					}
				}

				for (int i = 1; i < m - 1; i++)
				{
					if (board[i][0] == 'O')
					{
						board[i][0] = 'I';
						bfsQueue.push_back(make_pair(i,0));
					}
					if (board[i][n-1] == 'O')
					{
						board[i][n-1] = 'I';
						bfsQueue.push_back(make_pair(i,n-1));
					}
				}

				while (!bfsQueue.empty())
				{
					auto frontier = bfsQueue.back();
					bfsQueue.pop_back();
					int i = frontier.first;
					int j = frontier.second;

					if (i > 0 && board[i-1][j] == 'O')
					{
						board[i-1][j] = 'I';
						bfsQueue.push_back(make_pair(i-1,j));
					}
					if (i < m-1 && board[i+1][j] == 'O')
					{
						board[i+1][j] = 'I';
						bfsQueue.push_back(make_pair(i+1,j));						
					}
					if (j > 0 && board[i][j-1] == 'O')
					{
						board[i][j-1] = 'I';
						bfsQueue.push_back(make_pair(i,j-1));
					}
					if (j < n-1  && board[i][j+1] == 'O')
					{
						board[i][j+1] = 'I';
						bfsQueue.push_back(make_pair(i,j+1));
					}
				}

				for (int i = 0; i < m; i++)
				{
    				for (int j = 0; j < n; j++)
    				{
    					if (board[i][j] == 'O')
    					{
    						board[i][j] = 'X';
    					}
    					else if (board[i][j] == 'I')
    					{
    						board[i][j] = 'O';
    					}
    				}
    			}
    			return;
			}
		}
	}
};

int main (int argc, char* argv[])
{
	Solution mysol;
	vector <char> v1  = {'X','O','O','X','X','X','O','X','O','O','X','O','O','X','X','X','X','X','O','O'};
	vector <char> v2  = {'X','O','X','X','X','X','X','X','X','X','X','X','O','X','X','X','O','X','O','O'};
	vector <char> v3  = {'X','X','X','X','O','X','X','X','X','X','X','O','O','X','X','X','O','X','O','X'};
	vector <char> v4  = {'X','O','X','X','X','O','X','X','X','O','X','O','X','X','X','X','O','X','O','O'};
	vector <char> v5  = {'O','X','X','X','O','X','O','X','O','X','X','X','O','X','X','X','O','X','X','X'};
	vector <char> v6  = {'X','X','O','X','X','O','O','X','X','X','X','O','O','X','X','X','O','X','O','O'};
	vector <char> v7  = {'O','X','X','O','O','X','O','X','X','O','X','O','O','X','X','X','O','X','O','O'};
	vector <char> v8  = {'O','X','X','X','X','X','O','X','X','X','X','O','X','X','X','X','O','X','X','O'};
	vector <char> v9  = {'X','O','O','X','X','O','X','X','O','O','X','O','O','X','X','X','O','X','O','X'};
	vector <char> v10 = {'X','X','X','O','O','X','O','X','X','O','X','O','O','X','X','X','X','X','X','O'};
	vector <vector<char>> target = {v1,v2,v3,v4,v5,v6,v7,v8,v9,v10};
	// ["XOOXXXOXOO","XOXXXXXXXX","XXXXOXXXXX","XOXXXOXXXO","OXXXOXOXOX","XXOXXOOXXX","OXXOOXOXXO","OXXXXXOXXX","XOOXXOXXOO","XXXOOXOXXO"]
	mysol.solve(target);
	for (auto row : target)
	{
		for (auto slot : row)
		{
			cout<<slot<<" ";
		}
		cout<<endl;
	}
	return 0;
}