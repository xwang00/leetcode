#include <iostream>
/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode *cur = dummyhead;
        if (head) {
            while (cur->next && cur->next->next) {
                ListNode *temp1 = cur->next;
                ListNode *temp2 = cur->next->next->next;
                cur->next = cur->next->next;
                cur->next->next = temp1;
                cur->next->next->next = temp2;
                cur = cur->next->next;
            }
        }
        return dummyhead->next;
    }
};

// Function to print the linked list
void printList(ListNode *head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create the input linked list: 1->2->3->4
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Create an instance of the Solution class
    Solution solution;

    // Call the swapPairs method to swap the pairs of nodes
    ListNode *swappedHead = solution.swapPairs(head);

    // Print the output linked list after swapping pairs
    std::cout << swappedHead;

    return 0;
}