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
    void reorderList(ListNode* head) {
        if(!head || !head->next) {
            return;
        }

        ListNode *p1 = head;
        ListNode *p2 = head->next;

        //���ÿ���ָ������ʽ�����ƽ���ֿ���ż���Ļ�ƽ���֣������Ļ���һ�ڱȵڶ��ڶ�һ��
        while(p2&&p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        ListNode* head2  = p1->next;//p1ָ���һ�ڵ����һ���ڵ㣬������һ�����ǵڶ��ڵĿ�ʼ
        ListNode* temp;
        p1->next = NULL;//���׶Ͽ�

        p2 = head2->next;//ָ��head2����һ���ڵ�

        head2->next = NULL;//����ʱhead2��������Ϊ�����ڶ��ڷ��������һ���ڵ�

        while(p2) {
            temp = p2->next;//����temp��¼��p2����һ���ڵ�
            p2->next = head2;//��������
            head2 = p2;
            p2 = temp;
        }

        /*while(head) {
            cout << head->val << ",";
            head = head->next;
        }

        cout << endl;

        while(head2) {
            cout << head2->val << ",";
            head2 = head2->next;
        }*/

        //�����������ں�����
        p1 = head;
        p2 = head2;

        //������������
        while(p2) {//Ҫô������ȣ�Ҫô��һ�ڶ࣬���������õڶ�����Ϊ�жϿյ�����
            temp = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = temp;
        }

        /*while(head) {
            cout << head->val << ",";
            head = head->next;
        }*/

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
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    s.reorderList(&node1);

}

