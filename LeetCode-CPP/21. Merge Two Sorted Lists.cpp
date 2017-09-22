#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;//����ָ��l1
        ListNode* p2 = l2;//����ָ��l2
        ListNode* tail;//������ʾ��ǰ���һ���ڵ�
        int flag;//������ǵ�һ����ֵ˭��˭С���������ȷ������ֵ��
        if(!p1) {//���l1Ϊ�գ�ֱ�ӷ���l2
            return p2;
        } else if(!p2) {//l2Ϊ�գ�����l1
            return p1;
        } else {
            if(p1->val<=p2->val) {//�Ƚϵ�һ���ڵ�Ĵ�С��
                tail = p1;
                p1 = p1->next;
                flag = 1;
            } else {
                tail = p2;
                p2 = p2->next;
                flag = 2;
            }

            while(p1 && p2) {
                if(p1->val <= p2->val) {//���p1������p2��С����tailָ��p1,���Ҽ���������
                    tail->next = p1;
                    tail = p1;
                    p1 = p1->next;
                } else {//���p2��p1����С��tailָ������
                    tail->next = p2;
                    tail = p2;
                    p2 = p2->next;
                }
            }

            if(!p1) {//�����ʱp1ָ����ˣ�ֱ�ӽ�p2ʣ�µ��������ӵ��ڵ���.
                tail->next = p2;
            } else if(!p2) {
                tail->next = p1;
            }
        }
        if(flag == 1) {
            return l1;
        } else {
            return l2;
        }

    }
};

int main() {
    Solution s;


    ListNode node1(1);
    ListNode node2(1);

    ListNode node3(2);
    ListNode node4(3);

    node1.next = &node2;

    node3.next = &node4;

    ListNode * p = s.mergeTwoLists(&node1,&node3);

    while(p) {
        cout << p->val;
        p = p->next;
    }

}

