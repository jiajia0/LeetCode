/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;
        Node* iter = head,* next;
        // ��ԭ����������һ�飬ÿ���ڵ��������
        while(iter != NULL) {
            next = iter->next; // ��¼��һ���ڵ�
            Node* node = new Node(iter->val, NULL, NULL);
            iter->next = node;
            node->next = next;
            iter = next;
        }
        // ��ͷ��ʼ��������randomָ��
        iter = head;
        while(iter != NULL) {
            if(iter->random != NULL) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        // ��ԭ��������ָ���������Ҳ����޸�ԭ���������ָ��
        iter = head;
        Node* copy = iter->next;
        Node* copyHead = copy;
        while(copy->next != NULL) {
            iter->next = iter->next->next;
            iter = iter->next;
            
            copy->next = copy->next->next;
            copy = copy->next;
        }
        iter->next = NULL; // ���һ����ֵΪNULL������iter->next = iter->next->next;
        return copyHead;
    }
};