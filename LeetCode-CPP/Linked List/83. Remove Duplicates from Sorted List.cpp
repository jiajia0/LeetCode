#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        /*ListNode* tail = new ListNode(-99999);
        ListNode* start = tail;

        while(head) {
            //��һ���ڵ㲻Ϊ�ղ��ҵ�ǰ�ڵ���¸��ڵ����ֲ�һ�� ���� ��һ���ڵ�Ϊ�ղ��ҵ�ǰ�ڵ���µĽڵ����һ����һ��
            if(head->next && head->val != head->next->val || !head->next && head->val != tail->val) {//����ȵĻ������µ�����
                ListNode* node = new ListNode(0);
                node->val = head->val;
                //cout << head->val;
                tail->next = node;
                tail = node;
            }
            head = head->next;
        }

        return start->next;*/

        if(!head) {
            return NULL;
        }

        ListNode * start = head;
        ListNode * tail = head->next;

        while(tail) {
            if(start->val == tail->val) {
                start->next = tail->next;
                tail = tail->next;
            } else {
                start = start->next;
            }

        }
        return head;
    }
};

int main() {
    Solution s;


    ListNode node1(0);
    ListNode node2(0);
    ListNode node3(0);
    ListNode node4(0);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    ListNode * p = s.deleteDuplicates(&node1);

    while(p) {
        cout << p->val;
        p = p->next;
    }

}

