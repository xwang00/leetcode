#include <iostream>

/**
 * Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = new ListNode();
        ListNode *cur = new ListNode();
        ListNode *dummyhead = new ListNode();
        dummyhead->next = head;
        fast = dummyhead;
        cur = dummyhead;
        int i = 0;
        while (i != n)
        {
            fast = fast->next;
            i++;
        }
        while (fast->next)
        {
            cur = cur->next;
            fast = fast->next;
        }
        cur->next = cur->next->next;
        return dummyhead->next;
    }
};

/*class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *cur = new ListNode();
        ListNode *newlist = new ListNode();
        cur = head;
        newlist = head;
        int count = 0;
        while (cur)
        {
            cur = cur->next;
            count++;
        }
        int i = 0;
        cur = head;
        if (head->next == NULL || n==count){return head->next;}
        if (head && head->next)
        {
            while (i + n + 1 != count)
            {
                i++;
                cur = cur->next;
            }
            cur->next = cur->next->next;
        }
        return newlist;
    }
};*/

// Function to print the linked list
void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Create the input linked list: 1->2->3->4->5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);

    // Create an instance of the Solution class
    Solution solution;

    // Call the removeNthFromEnd method to remove the nth node from the end
    int n = 2;
    ListNode *modifiedHead = solution.removeNthFromEnd(head, n);

    // Print the output linked list after removing the nth node from the end
    printList(modifiedHead);

    return 0;
}

/*int main()
{
    // Create the input linked list: 1->2->3->4->5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create an instance of the Solution class
    Solution solution;

    // Call the removeNthFromEnd method to remove the nth node from the end
    int n = 2;
    ListNode *modifiedHead = solution.removeNthFromEnd(head, n);

    // Print the output linked list after removing the nth node from the end
    printList(modifiedHead);

    return 0;
}*/
