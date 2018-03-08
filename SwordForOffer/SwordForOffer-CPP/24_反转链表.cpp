#include <iostream>
#include "./Utils/List.h"

using namespace std;

// ������24����ת����
// ��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������
// ͷ��㡣



ListNode* ReverseList(ListNode* pHead) {
    ListNode* pReversedHead = nullptr;// ����ָ��ת֮���ͷ�ڵ�
    ListNode* pNode = pHead;// ָ��ǰ�ڵ�
    ListNode* pPrev = nullptr;// ָ��ǰһ���ڵ�

    while(pNode != nullptr) {
        ListNode* pNext = pNode->m_pNext;// �ҵ���һ���ڵ�

        if(pNext == nullptr)
            pReversedHead = pNode;

        pNode->m_pNext = pPrev;// ��ǰ�ڵ�ָ��ǰһ���ڵ�
        pPrev = pNode;// ��ʱ�Ľڵ�����һ���ڵ��ǰ�ڵ�
        pNode = pNext;// ��ǰ�ڵ�����һ���ƶ�
    }
    return pReversedHead;
}

// ====================���Դ���====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// ����������ж�����
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ���������ֻ��һ�����
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ���������
void Test3()
{
    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
