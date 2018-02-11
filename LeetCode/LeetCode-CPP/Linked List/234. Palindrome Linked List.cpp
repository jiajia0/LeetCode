#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> halfValues;//ʹ��һ��ջ����������ǰ��ߵĽڵ�.
        ListNode* fast = head;
        ListNode* slow = head;
        if(!head) {
            return true;
        }
        while(fast&&fast->next) {//ʹ�ÿ���ָ���ҵ������е�
            fast = fast->next->next;
            halfValues.push(slow->val);
            slow = slow->next;
        }
        if(fast) {//fastָ��Ϊ��˵��Ϊ����,��ʱ����Ҫ�Ƚ����м���Ǹ���ֵ
            slow = slow->next;
        }

        while(slow) {//��Ϊ�������
            if(slow->val != halfValues.top()) {
                return false;
            } else {
                halfValues.pop();
                slow = slow->next;
            }
        }
        return true;

    }
};
int main() {
    Solution s;


    ListNode node1(1);
    ListNode node2(2);

    ListNode node3(2);
    ListNode node4(1);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    cout << s.isPalindrome(&node1);


}

