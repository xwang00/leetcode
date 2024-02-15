#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>

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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL) //
        {
            return NULL;
        }
        ListNode *cur = head;
        ListNode *newhead = new ListNode(cur->val);
        while (cur->next)
        {
            cur = cur->next;
            ListNode *node = new ListNode(cur->val);
            node->next = newhead; //指针指向的是内存里的一块区域，指针本身不是这块东西。指针可以理解成一种特殊的value
            newhead = node; //这一行和上一行毫无影响
        }
        return newhead;
    }
};

int main()
{
    Solution rlist;
    ListNode *list = rlist.reverseList(NULL);
    std::cout << list;
    return 0;
}

/*
int main()
{
    ListNode *head = new ListNode(1); // 创建第一个节点
    ListNode *current = head;         // 用于追踪链表的当前节点

    // 将数组 [2,3,4,5] 的元素添加到链表中
    int elements[] = {2, 3, 4, 5};
    for (int i = 0; i < 4; ++i)
    {
        current->next = new ListNode(elements[i]); // 创建新节点并连接到当前节点的next
        current = current->next;                   // 将当前节点更新为新创建的节点
    }
    Solution rlist;
    ListNode * list = rlist.reverseList(head);
    std::cout << list ;
    return 0;
}
*/