#include <vector>
#include <iostream>
#include <stack>

using namespace std;

void PrintBoard(vector<vector<char>> v)
{
	cout<<"-------------------------------------------------------------"<<endl;
	for (auto row : v)
	{
		for (auto c : row)
		{
			cout<<c;
		}
		cout<<endl;
	}
}

class Solution
{
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
    	int j = click.back();
    	click.pop_back();
    	int i = click.back();
    	click.pop_back();
    
    	if (board[i][j] == 'M')
    	{
    		board[i][j] = 'X';
    		// PrintBoard(board);
   			return board;
   		}
   		else
   		{
   			int m = board.size();
    		int n = board[0].size();
    		stack <pair<int,int>> dfsStack;
   			dfsStack.push(pair<int,int>(i,j));
   			while (!dfsStack.empty())
   			{
   				auto frontier = dfsStack.top();
   				dfsStack.pop();
   				i = frontier.first;
   				j = frontier.second;
    			int adjMineCount = 0;
    			if (IsValid(i - 1, j, m, n) && board[i - 1][j] == 'M')	adjMineCount ++;
    			if (IsValid(i + 1, j, m, n) && board[i + 1][j] == 'M')	adjMineCount ++;
    			if (IsValid(i, j - 1, m, n) && board[i][j - 1] == 'M')	adjMineCount ++;
    			if (IsValid(i, j + 1, m, n) && board[i][j + 1] == 'M')	adjMineCount ++;
    			if (IsValid(i - 1, j - 1, m, n) && board[i - 1][j - 1] == 'M') 	adjMineCount ++;
    			if (IsValid(i - 1, j + 1, m, n) && board[i - 1][j + 1] == 'M')	adjMineCount ++;
    			if (IsValid(i + 1, j - 1, m, n) && board[i + 1][j - 1] == 'M')	adjMineCount ++;
    			if (IsValid(i + 1, j + 1, m, n) && board[i + 1][j + 1] == 'M')	adjMineCount ++;
    			
    			if (adjMineCount)	board[i][j] = '0' + adjMineCount;
    			else 
    			{
    				board[i][j] = 'B';
	    			if (IsValid(i - 1, j, m, n) && board[i - 1][j] == 'E')	dfsStack.push(pair<int,int>(i - 1, j));
	    			if (IsValid(i + 1, j, m, n) && board[i + 1][j] == 'E') 	dfsStack.push(pair<int,int>(i + 1, j));
	    			if (IsValid(i, j - 1, m, n) && board[i][j - 1] == 'E') 	dfsStack.push(pair<int,int>(i, j - 1));
	    			if (IsValid(i, j + 1, m, n) && board[i][j + 1] == 'E') 	dfsStack.push(pair<int,int>(i, j + 1));
	    			if (IsValid(i - 1, j - 1, m, n) && board[i - 1][j - 1] == 'E') 	dfsStack.push(pair<int,int>(i - 1, j - 1));
	    			if (IsValid(i - 1, j + 1, m, n) && board[i - 1][j + 1] == 'E') 	dfsStack.push(pair<int,int>(i - 1, j + 1));
	    			if (IsValid(i + 1, j - 1, m, n) && board[i + 1][j - 1] == 'E') 	dfsStack.push(pair<int,int>(i + 1, j - 1));
	    			if (IsValid(i + 1, j + 1, m, n) && board[i + 1][j + 1] == 'E') 	dfsStack.push(pair<int,int>(i + 1, j + 1));
	    		}
	    	}
	    	return board;
    	}
    }
    bool IsValid(const int& i, const int& j, const int& m, const int& n)
    {
    	return (i >= 0 && j >= 0 && i <= m - 1 && j <= n - 1);
    }
};

int main(int argc, char const *argv[])
{
	Solution mySol;
	vector <char> t (50,'E');
	vector<vector<char>> v (50, t);
	vector<int> c = {29,2};
	mySol.updateBoard(v,c);
	return 0;
}