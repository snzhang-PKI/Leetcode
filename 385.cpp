#include <iostream>

using namespace std;


// class Solution 
// {
// public:
//     NestedInteger deserialize(string s) 
//     {
// 		if (s.find(',') == string::npos)
// 		{
// 			NestedInteger res = NestedInteger();
// 			int p = s.find(',')
// 			int val = stoi(res.substr(1, p - 1));
// 			res.setInteger(val);
// 			string tail = s.substr(p);
// 			return res;
// 		}
// 		else
// 		{
// 			if (s[0] != '[')
// 			{
// 				return NestedInteger(stoi(s));
// 			}
// 			else
// 			{
// 				return NestedInteger(stoi(s.substr(1 , s.size() - 2)));
// 			}
// 		}
//     }
// };


int main(int argc, char const *argv[])
{
	string a = "1a2";
	cout<<a.substr(a.find('a'))<<endl;
	return 0;
}