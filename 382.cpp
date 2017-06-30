//Definition for singly-linked list.
#include <time.h>
#include <iostream>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution 
{
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) 
    {
        data = head;
        l = 0;
        ListNode* tmp = data;
        while (tmp != nullptr)
        {
        	tmp = tmp -> next;
        	l++;
        }
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
    	if (l == 0)
    	{
    		cout<<"the vessel is empty, there's nothing to get"<<endl;
    		return 0;
    	}
    	
        int luckyguy = rand()%l;
        ListNode* tmp = data;
        for (int i = 0; i < luckyguy; i++)
        {
        	tmp = tmp -> next;
        }
        return tmp->val;
    }

private:
	ListNode* data;
	int l;

};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}