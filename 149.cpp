#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

// Definition for a point.
struct Point 
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
 
class Solution 
{
public:
    int maxPoints(vector<Point>& points) 
    {
        int res = 0;

        vector<unordered_map<pair<int,int>,int>> emission;
        return res;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}