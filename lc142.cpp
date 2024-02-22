#include <iostream>
/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return NULL;
        }
        ListNode *cur = head->next;
        int tempnum = 0;
        int curnum = 1;
        while (cur) {
            ListNode *temp = head;
            tempnum = 0;
            while (tempnum < curnum) {
                if (temp == cur) {
                    return temp;
                }
                temp = temp->next;
                tempnum++;
            }
            cur = cur->next;
            curnum++;
        }
        return NULL;
    }
};

// Function to create a cycle in the linked list at position 'pos'
void createCycle(ListNode *head, int pos) {
    if (pos == -1) return;
    ListNode *tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    ListNode *cycleStart = head;
    for (int i = 0; i < pos; ++i) {
        cycleStart = cycleStart->next;
    }
    tail->next = cycleStart;
}

int main() {
    // Create the linked list: [3,2,0,-4]
    ListNode *head = new ListNode(1);

    // Create an instance of the Solution class
    Solution solution;

    // Call the detectCycle method to detect the start of the cycle
    ListNode *cycleStart = solution.detectCycle(head);

    // Print the output
    if (cycleStart != nullptr) {
        std::cout << "Tail connects to node index " << std::endl;
    } else {
        std::cout << "No cycle found" << std::endl;
    }

    return 0;
}

/*int main() {
    // Create the linked list: [3,2,0,-4]
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Set the cycle position
    int pos = 1;

    // Create a cycle in the linked list
    createCycle(head, pos);

    // Create an instance of the Solution class
    Solution solution;

    // Call the detectCycle method to detect the start of the cycle
    ListNode* cycleStart = solution.detectCycle(head);

    // Print the output
    if (cycleStart != nullptr) {
        std::cout << "Tail connects to node index " << pos << std::endl;
    } else {
        std::cout << "No cycle found" << std::endl;
    }

    return 0;
}*/