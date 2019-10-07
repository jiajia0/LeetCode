/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(), G.end());
        int res = 0;
        while(head) {
            // ����ĸ�������ǰ�ڵ���������У�������һ���ڵ�Ϊ�ջ��߲�����������
            if(s.count(head->val) && (head->next == NULL || !s.count(head->next->val))) {
                res++;
            }
            head = head->next;
        }
        return res;
    }
};