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
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head || !head->next) {
            return head;
        }

        ListNode* preCur = head;
        ListNode* cur = head->next;
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        int flag = 0;
        while(cur) {
            if(preCur->val == cur->val) {//�����ȵĻ�,���λ��ֵΪ1
                flag = 1;
            } else {//����ȣ����Ϊ��ֵΪ0�����������ʱ���Ϊ�Ѿ�Ϊ0�ˣ���ô�������յ�������
                if(flag == 0) {
                    ListNode* node = new ListNode(preCur->val);
                    temp->next = node;
                    temp = node;
                }
                preCur = cur;
                flag = 0;
                if(!cur->next) {//�����һ��û�������ˣ�����ʱ��curҲ����
                    temp->next = cur;
                }
            }
            cur = cur->next;
        }

        return result->next;

        /*if(!head) {
            return nullptr;
        }

        vector<int> nodes1;
        vector<int> nodes2;
        vector<int> resultnodes;
        ListNode* result = new ListNode(0);
        ListNode* temp = result;

        while(head) {

            if(find(nodes1.begin(),nodes1.end(),head->val) == nodes1.end()) {//�������������뵽nodes1��
                nodes1.push_back(head->val);
                //cout << "nodes1:" << head->val << endl;
            } else {//������������nodes2��
                nodes2.push_back(head->val);
                //cout << "nodes2:" << head->val << endl;
            }
            head = head->next;
        }

        //ȡ�����С���������ſ���
        set_difference(nodes1.begin(),nodes1.end(),nodes2.begin(),nodes2.end(),inserter(resultnodes,resultnodes.begin()));//ȡ����set�Ĳ

        for(vector<int>::iterator it=resultnodes.begin();it!=resultnodes.end();it++) {
            //cout << *it << endl;
            ListNode* node = new ListNode(*it);
            temp->next = node;
            temp = node;
        }

        return result->next;*/

    }
};

int main() {
    Solution s;

    ListNode node1(1);
    ListNode node2(1);
    ListNode node3(2);
    ListNode node4(2);
    ListNode node5(3);
    ListNode node6(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    ListNode* p = s.deleteDuplicates(&node1);

    while(p) {
        cout << p->val;
        cout << endl;
        p = p->next;
    }

}

