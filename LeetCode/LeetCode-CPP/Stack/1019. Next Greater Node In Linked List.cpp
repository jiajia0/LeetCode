/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> res;
        
        int i = 0;
        
        while(head) {
            res.push_back(head->val); // �ȼ���һ���µĽڵ�
            // �ж϶�Ӧindex�ϵ�Ԫ���Ƿ�С�뵱ǰ�ڵ㣬��С����Ѷ�Ӧindexλ���ϵ�Ԫ������Ϊ��ǰ�ڵ�ֵ
            while(!st.empty() && res[st.top()] < head->val) {
                res[st.top()] = head->val;
                st.pop();
            }
            st.push(i); // ��Ŷ�Ӧ��index
            i++;
            head = head->next;
        }
        
        // ��û�г�ջ��Ԫ�ض�Ӧ��index����Ϊ0
        while(!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }
        
        return res;
    }
};

*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr = head;
        vector<int> res;
        while(curr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        
        stack<int> st;
        for(int i = res.size() - 1; i >= 0; i--) {
            int curr_num = res[i];
            // ��ջ�бȵ�ǰ�ڵ�С�Ķ���pop��
            while(!st.empty() && st.top() <= res[i])
                st.pop();
            if(st.empty()) // ��ջΪ�գ���˵��û�бȵ�ǰ�ڵ�������
                res[i] = 0;
            else
                res[i] = st.top();
            st.push(curr_num); // �ѵ�ǰ�������뵽ջ��
        }
        return res;
    }  
};