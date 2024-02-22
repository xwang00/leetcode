#include <iostream>
/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* cura = headA;
        while (cura) {
            ListNode* curb = headB;
            while (curb) {
                if (cura == curb) {
                    return cura;
                }
                curb = curb->next;
            }
            cura = cura->next;
        }
        return NULL;
    }
};

int main() {
    // Create the nodes for linked list A: [4,1,8,4,5]
    ListNode* listA = new ListNode(4);
    listA->next = new ListNode(1);
    listA->next->next = new ListNode(8);
    listA->next->next->next = new ListNode(4);
    listA->next->next->next->next = new ListNode(5);

    // Create the nodes for linked list B: [5,6,1,8,4,5]
    ListNode* listB = new ListNode(5);
    listB->next = new ListNode(6);
    listB->next->next = new ListNode(1);

    // Create the intersection node with value 8
    ListNode* intersectionNode = new ListNode(8);
    listA->next->next->next->next->next = intersectionNode;
    listB->next->next->next = intersectionNode;

    // Skip counts for listA and listB
    int skipA = 2, skipB = 3;

    // Create an instance of the Solution class
    Solution solution;

    // Call the getIntersectionNode method to find the intersection node
    ListNode* intersection = solution.getIntersectionNode(listA, listB);

    // Print the output
    if (intersection)
        std::cout << "Intersected at '" << intersection->val << "'"
                  << std::endl;
    else
        std::cout << "No intersection found" << std::endl;

    return 0;
}