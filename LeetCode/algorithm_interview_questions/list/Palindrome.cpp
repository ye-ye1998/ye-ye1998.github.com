    // 请判断一个链表是否为回文链表。
    // https://leetcode-cn.com/leetbook/read/top-interview-questions/xaw0rm/

    #include <iostream>

    using namespace std;

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* reverseList(ListNode* p) {  // 反转链表
        if(p == nullptr) {
            return p;
        }
        ListNode* pre = nullptr;
        ListNode* cur = p;
        ListNode* nex = nullptr;
        while (cur)
        {
            /* code */
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr) {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast) {
            if(fast->next == nullptr) {
                slow = slow->next;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = reverseList(slow);
        slow = head;
        while (fast)
        {
            /* code */
            if(fast->val != slow->val) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }

    int main()
    {
        ListNode* p1 = new ListNode(1);
        ListNode* p2 = new ListNode(0);
        ListNode* p3 = new ListNode(1);
        ListNode* p4 = new ListNode(1);
        p1->next = p2;
        p2->next = p3;
        p3->next = p4;
        if(isPalindrome(p1)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
        return 0;
    }