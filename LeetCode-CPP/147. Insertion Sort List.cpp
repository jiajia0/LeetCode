#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* result = new ListNode(0);
        ListNode* temp;
        ListNode* tail;

        while(head) {
            temp = head->next;//����һ���ڵ���뿪����������
            tail = result;//��������ĵ�һ���ڵ㿪ʼ����

            while(tail->next && tail->next->val < head->val) {//��tail�ƶ�����Ҫ����ڵ��ǰ��
                tail = tail->next;
            }

            head->next = tail->next;//���ڵ���뵽�м�
            tail->next = head;

            head = temp;
        }

        return result->next;
    }
};

int main() {
    Solution s;


    ListNode node1(10);
    ListNode node2(2);
    ListNode node3(31);
    ListNode node4(14);
    ListNode node5(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    ListNode* p = s.insertionSortList(&node1);

    while(p) {
        cout << p->val;
        cout << endl;
        p = p->next;
    }

}

