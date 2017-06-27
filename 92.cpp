//Definition for singly-linked list.
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if (head == nullptr || head -> next == nullptr)
    	{
    		return head;
    	}
    	int count = 2;
    	ListNode* cut = head;
    	ListNode* p = nullptr;
	    ListNode* q = nullptr;
	    ListNode* tail = head; 
    	if (m == 1)
    	{
	    	tail = cut; 
	    	p = cut -> next;
	    	q = p -> next;
	    	cut -> next = cut;    		
    	}
    	else
    	{
    		while (count < m)
	    	{
	    		cut = cut -> next;
	    		count ++;
	    	}
	    	p = cut -> next;
	    	q = p -> next;
	    	tail = cut -> next;
    	}

    	while (count <= n)
    	{
    		p -> next = cut -> next;
    		cut -> next = p;
    		p = q;

    		if (q == nullptr)
    		{
    			break;
    		}
    		else
    		{
    			q = q -> next;
    			count ++;
    		}
    	}
    	ListNode* res = cut -> next;
    	tail -> next = p;

    	if (m == 1)
    	{
    		// res ->printList();
    		return res;
    	}
    	else
    	{
    		// head -> printList();
    		return head;
    	}
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
	// b -> next = c;
	c -> next = d;
	d -> next = e;
	e -> next = f;
	f -> next = g;
	g -> next = h;
	Solution mySol;
	mySol.reverseBetween(a,1,2);
}