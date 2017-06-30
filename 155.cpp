#include <iostream>
#include <list>

using namespace std;

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
        this -> data = list<int>();
    }
    
    void push(int x)
    {
        this -> data.push_back(x);
        if (data.size() == 1)
        {
            min = x;
        }
        else if (x < min)
        {

            min = x;
        }
    }
    
    void pop() 
    {
        if (!data.empty())
        {
            data.pop_back();
            this -> min = data.front();
            for (auto it = data.begin(); it != data.end(); it++)
            {
                if (*it < this -> min)
                {
                    min = *it;
                }
            }
            
        }
    }
    
    int top() 
    {
        return this -> data.back();
    }
    
    int getMin() 
    {
        return this -> min;
    }

private:
    list<int> data;
    int min;
};

int main(int argc, char const *argv[])
{
    list<int> v = {1,2,3};
    v.push_back(1);
    return 0;
}