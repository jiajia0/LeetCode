#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    struct ListNode* getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
        if(!headA || !headB) {
            return NULL;
        }

        ListNode*a = headA;
        ListNode*b = headB;
        while(a!=b) {//�൱���ǽ���ɨ��һ�飬����н����Ȼ�����
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return a;
        //�ȱ���һ�������ٱ�����һ������
        /*unordered_set<struct ListNode*> nodes;//�������
        while(headA) {
            nodes.insert(headA);
            headA = headA->next;
        }
        while(headB) {
            if(nodes.count(headB)) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;*/

        //ͬʱ������������
        /*while(headA && headB) {
            if(headA == headB) {
                //cout << "0. " << headA->val;
                return headA;
            }
            if(nodes.count(headA)) {//���A�ڵ��ڼ������ܹ��ҵ���˵�����Ǹ�����
                //cout << "1. " << headA->val;
                return headA;
            } else if(nodes.count(headB)) {//B
                //cout << "2. " << headB->val;
                return headB;
            } else {
                nodes.insert(headA);
                nodes.insert(headB);
                headA = headA->next;
                headB = headB->next;
            }
        }
        if(!headA) {//���A�������ˣ���Ҫ����һ��B����Ϊ����B��A�ĳ��ȳ���A�����һ���ڵ����B���м�һ��������ʱB��û�б�����
            while(headB) {
                if(nodes.count(headB)) {
                    //cout << "4. " << headB->val;
                    return headB;
                }
                headB = headB->next;
            }
        }
        if(!headB) {
            while(headA) {
                if(nodes.count(headA)) {
                    //cout << "5. " << headA->val;
                    return headA;
                }
                headA = headA->next;
            }
        }
        return NULL;*/
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

    node3.next = &node4;
    node4.next = &node5;


    node2.next = &node6;
    node5.next = &node6;

    ListNode * p = s.getIntersectionNode(&node1,&node3);
}

