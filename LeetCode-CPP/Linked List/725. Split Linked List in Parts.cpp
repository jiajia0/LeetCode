#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> nodes;
        int counts = 0;//����ͳ�������ж��ٸ��ڵ�
        ListNode* p = root;

        while(p) {//ѭ��������ܹ��Ľڵ���
            p = p->next;
            counts++;
        }

        int num,rem,i,j;
        num = counts/k;//�����ÿ���ж��ٸ��̶��ڵ�
        rem = counts%k;//�����������Ҳ����ǰ���ٸ�����Ҫ��һ���ڵ�

        for(i=0;i<k;i++) {
            ListNode* head = new ListNode(0);//�½�һ���µ�ͷ���
            p = head;
            for(j=0;j<num;j++) {//ÿ���ڵ�Ĺ̶������������
                ListNode* node = new ListNode(root->val);
                p->next = node;
                p = p->next;
                if(root) {
                    root = root->next;
                }
            }
            if(rem-- > 0 && root) {//��Ҫ���һ���ڵ�
                ListNode* rmnode = new ListNode(root->val);
                p->next = rmnode;
                if(root) {
                    root = root->next;
                }
            }

            nodes.push_back(head->next);//��ӵ�������
        }

        return nodes;

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

    vector<ListNode*> node = s.splitListToParts(&node1,5);
    int i = 0;
    for(i=0;i<node.size();i++) {
        ListNode* p = node[i];
        while(p) {
            cout << p->val << endl;
            p = p->next;
        }
        cout << endl;
    }
}

