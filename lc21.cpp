#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* lista = list1;
        ListNode* listb = list2;
        ListNode* temp = ans;

        // while (lista || listb) {
        //     if (listb && (lista == nullptr || lista->val > listb->val)) {
        //         temp->next = listb;
        //         temp = temp->next;
        //         listb = listb->next;
        //     } else {
        //         temp->next = lista;
        //         temp = temp->next;
        //         lista = lista->next;
        //     }
        // }

        while (lista && listb) {
            if (lista->val > listb->val) {
                temp->next = listb;
                temp = temp->next;
                listb = listb->next;
            } else {
                temp->next = lista;
                temp = temp->next;
                lista = lista->next;
            }
        }
        if (lista) temp->next = lista;
        if (listb) temp->next = listb;
        temp = ans->next;
        delete ans;
        return temp;
    }
};

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // ListNode* list1 = nullptr;
    // ListNode* list2 = nullptr;
    Solution solution;
    ListNode* ans = solution.mergeTwoLists(list1, list2);
    while (ans) {
        std::cout << ans->val;
        ans = ans->next;
    }
    return 0;
}