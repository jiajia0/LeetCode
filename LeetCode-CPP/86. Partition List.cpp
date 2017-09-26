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
    ListNode* partition(ListNode* head, int x) {

        ListNode* ltDummy = new ListNode(0);
        ListNode* gtDummy = new ListNode(0);
        ListNode* ltTail = ltDummy;
        ListNode* gtTail = gtDummy;

        while(head) {
            if(head->val < x) {
                ltTail->next = head;
                ltTail = head;
            } else {
                gtTail->next = head;
                gtTail = head;
            }
            head = head->next;
        }

        ltTail->next = gtDummy->next;
        gtTail->next = NULL;//���һ�����ܲ�Ϊ�գ�������Ҫ��ֵΪ��

        return ltDummy->next;


        /*if(!head) {
            return NULL;
        }

        ListNode* result = new ListNode(0);

        stack<ListNode*> lt;//С��x��
        stack<ListNode*> gt;//����x��

        while(head) {
            if(head->val < x) {
                lt.push(head);
            } else {
                gt.push(head);
            }
            head = head->next;
        }

        while(!lt.empty() || !gt.empty()) {
            if(!gt.empty()) {//��������û�б�������������
                gt.top()->next = result->next;
                result->next = gt.top();
                gt.pop();
            } else {
                lt.top()->next = result->next;
                result->next = lt.top();
                lt.pop();
            }
        }

        return result->next;*/

    }
};

int main() {
    Solution s;


    ListNode node1(1);
    ListNode node2(4);
    ListNode node3(3);
    ListNode node4(2);
    ListNode node5(5);
    ListNode node6(2);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    ListNode* p = s.partition(&node1,3);

    while(p) {
        cout << p->val;
        cout << endl;
        p = p->next;
    }

}

