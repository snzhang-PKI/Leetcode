// generate a fakehead will make it eaiser to deal with coner case

#include <iostream>

using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    void printList()
    {
    	if(this == nullptr)
    	{
    		cout<<endl;
    	}
    	else
    	{
    		cout<<this -> val<<" ";
    		this -> next ->printList();
    	}
    }
};

class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        n -= m;
        ListNode* fakeHead = new ListNode(0);
        fakeHead -> next = head;
        ListNode* preStart = fakeHead;
        for (int i = 1; i < m; i++)
        {
            preStart = preStart -> next;
        }
        ListNode* start = preStart -> next;
        for (int i = 0; i < n; i++)
        {
            ListNode* tmp = start -> next;
            start -> next = tmp -> next;
            tmp -> next = preStart -> next;
            preStart -> next = tmp;
        }
        return fakeHead -> next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    ListNode* f = new ListNode(6);
    ListNode* g = new ListNode(7);
    ListNode* h = new ListNode(8);
    a -> next = b;
    b -> next = c;
    c -> next = d;
    d -> next = e;
    e -> next = f;
    f -> next = g;
    g -> next = h;
    Solution mySol;
    mySol.reverseBetween(a,1,2);
    return 0;
}