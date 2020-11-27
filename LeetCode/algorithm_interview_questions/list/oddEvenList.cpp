// 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点
// 指的是节点编号的奇偶性，而不是节点的值的奇偶性。
// 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
// https://leetcode-cn.com/leetbook/read/top-interview-questions/xa0a97/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr) {
        return head;
    }
    ListNode* evenBegin = head->next;
    ListNode* odd = head;
    ListNode* even = head->next;
    while (even != nullptr && odd != nullptr)
    {
        /* code */
        if(even) {
            if(even->next == nullptr) {
                break;
            }
            odd->next = even->next;            
            odd = odd->next;
        }
        if(odd) {
            even->next = odd->next;
            even = even->next;
        }
    }
    odd->next = evenBegin;
    return head;
}

int main()
{
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    ListNode* p6 = new ListNode(6);
    ListNode* p7 = new ListNode(7);
    ListNode* p8 = new ListNode(8);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    p7->next = p8;
    ListNode* out = oddEvenList(p1);
    return 0;
}