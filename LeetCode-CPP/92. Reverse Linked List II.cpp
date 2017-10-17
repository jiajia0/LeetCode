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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || m==n) {
            return head;
        }

        ListNode* dummpy = new ListNode(0);
        dummpy->next = head;
        ListNode* temp = dummpy;
        ListNode* result = new ListNode(0);
        ListNode* tail = result;

        stack<ListNode*> node1;
        stack<ListNode*> node2;

        int num = n - m + 1;//��Ҫ��1,��ʱ��Ҫ����������Ǹ��ڵ�

        m--;
        while(m) {//��m֮ǰ�Ķ������node1ջ��
            temp = temp->next;
            node1.push(temp);
            m--;
        }

        while(num&&temp) {
            temp = temp->next;
            node2.push(temp);
            num--;
        }

        if(temp) {
            temp = temp->next;//�ƶ����任���һ���ڵ�
        }

        while(!node1.empty()) {//ǰ���˳�򲻱䣬����ʹ��ͷ�巨
            node1.top()->next = result->next;
            result->next = node1.top();
            if(tail == result) {
                tail = node1.top();
            }
            node1.pop();
        }


        while(!node2.empty()) {
            tail->next = node2.top();
            tail = tail->next;
            node2.pop();
        }

        while(temp) {
            tail->next = temp;
            tail = temp;
            temp = temp->next;
        }

        tail->next = nullptr;

        return result->next;


        /*ListNode* dummpy = new ListNode(0);
        dummpy->next = head;
        ListNode* start = dummpy;//ָ����Ҫ�任�Ŀ�ͷ
        ListNode* tail = nullptr;//ָ����Ҫ�任�Ľ�β
        ListNode* temp = nullptr;
        ListNode* p1,*p2;

        int num = n - m;

        m--;

        while(m) {//���е���Ҫ�任λ�õ�ǰһ���ڵ�
            start = start->next;
            m--;
        }

        p1 = start;//��¼�жϵ�λ��
        p2 = start->next;//��¼ת��������һ��λ��

        start = start->next;//�˿̵�λ�ò�����Ҫ��ʼ�任��λ��
        temp = start->next;//ָ����һ���ڵ�
        start->next = nullptr;

        while(temp && num) {
            tail = temp->next;
            temp->next = start;

            start = temp;
            temp = tail;
            num--;
        }


        p1->next = start;


        while(temp) {//��Ҫ��temp������tail����Ϊtail����Ϊ��
            p2->next = temp;
            p2 = temp;
            temp = temp->next;
        }

        return dummpy->next;*/
    }
};

int main() {
    Solution s;


    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    node1.next = &node2;
    node2.next = &node3;
    //node3.next = &node4;
    //node4.next = &node5;

    ListNode* p = s.reverseBetween(&node1,2,3);

    while(p) {
        cout << p->val;
        cout << endl;
        p = p->next;
    }

}

