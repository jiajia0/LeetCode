#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head) {
            return head;
        }

        ListNode* temp1,*temp2;
        temp1 = temp2 = head;

        int num = 0;
        while(num!=k) {//��temp1�ƶ�
            num++;
            if(!temp1->next) {//��ʱ���������ĳ��ȣ����Ҹ���k��ֵ
                temp1 = head;
                k = k%num;//���������
                num = 0;
            } else {
                temp1 = temp1->next;
            }
        }

        if(temp1 == temp2) {
            return temp1;
        } else {
            while(temp1->next) {//��temp2�ƶ�����Ҫ�Ͽ���λ��
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            ListNode* newHead = temp2->next;
            temp1->next = head;
            temp2->next = nullptr;

            return newHead;

        }

        /*int len = 1;
        ListNode* temp = head;
        while(temp->next) {//������ܹ��ж��ٸ��ڵ�
            temp = temp->next;
            len++;
        }

        temp->next = head;//����ʱ���һ���ڵ����һ���ڵ�����������Ȼ�����ֱ�Ӵӵ�ǰ�Ľڵ���б���

        k = len - k;//�������Ҫ�������ٸ��ڵ�

        while(k%len) {//����ʹ��ȡģ����
            temp = temp->next;
            k--;
        }

        ListNode* newHead = temp->next;//�½ڵ�
        temp->next = NULL;//�Ͽ�

        return newHead;*/

    }
};

int main() {
    Solution s;

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);

    node1.next = &node2;
    node2.next = &node3;
    //node3.next = &node4;
    //node4.next = &node5;
    //node5.next = &node6;

    ListNode* p = s.rotateRight(&node1,2000000000);
    while(p) {
        cout << p->val << ",";
        p = p->next;
    }

}

