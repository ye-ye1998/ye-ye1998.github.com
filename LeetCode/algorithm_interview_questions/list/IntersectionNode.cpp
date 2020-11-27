// 编写一个程序，找到两个单链表相交的起始节点。
// https://leetcode-cn.com/leetbook/read/top-interview-questions/xan8ah/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr && headB == nullptr) {
        return nullptr;
    }
    ListNode* pA = headA;
    ListNode* pB = headB;
    while (pA && pB)
    {
        /* code */
        pA = pA->next;
        pB = pB->next;
    }
    if(pA) {
        pB = headA;
        while (pA)
        {
            /* code */
            pA = pA->next;
            pB = pB->next;
        }
        pA = headB;
    }
    else if(pB) {
        pA = headB;
        while (pB)
        {
            /* code */
            pA = pA->next;
            pB = pB->next;
        }
        pB = headA;
    }
    else {
        pA = headA;
        pB = headB;
    }
    while (pA && pB)
    {
        /* code */
        if(pA == pB) {
            return pA;
        }
        pA = pA->next;
        pB = pB->next;
    }
    return nullptr;
}

int main()
{
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(9);
    ListNode* a3 = new ListNode(1);
    ListNode* b1 = new ListNode(3);
    ListNode* s1 = new ListNode(2);
    ListNode* s2 = new ListNode(4);
    a1->next = a2;
    a2->next = a3;
    a3->next = s1;
    s1->next = s2;
    b1->next = s1;
    cout << getIntersectionNode(a1, b1)->val << endl;
    return 0;
}