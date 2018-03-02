#include <iostream>
#include "./Utils/List.h"

using namespace std;

void DeleteDuplication(ListNode** pHead) {
    if(pHead == nullptr || *pHead == nullptr || (*pHead)->m_pNext == nullptr)
        return;
    //PrintList(*pHead);
    ListNode* pPreNode = *pHead;// ָ��ǰһ������ͬ�Ľڵ�
    ListNode* pCurNode = pPreNode->m_pNext;// ָ��ǰ���ڱ����Ľڵ�
    ListNode* pResult = new ListNode;
    ListNode* pTemp = pResult;
    pTemp->m_pNext;
    int flag = 0;
    while(pCurNode) {
        // ����ϸ��ڵ�͵�ǰ�ڵ���ͬ������Ҫɾ��
        if(pPreNode->m_nValue == pCurNode->m_nValue)
            flag = 1;
        else {// ˵��pre��cur��Ԫ�ز����
            if(flag == 0) {// ˵�������������������ֶ�����ͬ����ʱ�ܹ�ȷ��preָ�����Ψһֵ
                ListNode* node = new ListNode;
                node->m_nValue = pPreNode->m_nValue;
                pTemp->m_pNext = node;
                pTemp = node;
            }
            pPreNode = pCurNode;
            flag = 0;
            if(!pCurNode->m_pNext) {// ˵��cur�����һ��Ԫ�أ�ֱ����ӽ�ȥ
                pTemp->m_pNext = pCurNode;
            }
        }
        pCurNode = pCurNode->m_pNext;
    }
    *pHead = pResult->m_pNext;
    //PrintList(*pHead);
}

/*void DeleteDuplication(ListNode** pHead) {
    if(pHead == nullptr || *pHead == nullptr)
        return;

    ListNode* pPreNode = nullptr;
    ListNode* pNode = *pHead;

    while(pNode != nullptr) {
        // ָ����һ���ڵ�
        ListNode* pNext = pNode->m_pNext;
        bool needDelete = false;// ��������Ƿ���Ҫɾ��

        // �����ǰ�ڵ��ֵ����һ���ڵ��ֵһ��������Ҫɾ��
        if(pNext!=nullptr && pNext->m_nValue == pNode->m_nValue)
            needDelete = true;

        // �������Ҫɾ�������¼�¸ýڵ㣬�����ƶ�����һ���ڵ�
        if(!needDelete) {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        } else {
            int value = pNode->m_nValue;// ��¼�µ�ǰ����ֵ
            ListNode* pToBeDel = pNode;// ����ָ����Ҫɾ���Ľڵ�
            // �����Ҫɾ���Ľڵ����һ���ڵ���ͬ
            while(pToBeDel != nullptr && pToBeDel->m_nValue == value) {
                pNext = pToBeDel->m_pNext;
                delete pToBeDel;
                pToBeDel = nullptr;
                pToBeDel = pNext;// �ƶ�����һ���ڵ�
            }
            // ��ʱpNextָ����һ������ͬ������
            if(pPreNode == nullptr)
                *pHead = pNext;
            else
                pPreNode->m_pNext = pNext;
            pNode = pNext;
        }
    }
}*/


// ====================���Դ���====================
void Test(char* testName, ListNode** pHead, int* expectedValues, int expectedLength)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    DeleteDuplication(pHead);

    int index = 0;
    ListNode* pNode = *pHead;
    while(pNode != nullptr && index < expectedLength)
    {
        if(pNode->m_nValue != expectedValues[index])
            break;

        pNode = pNode->m_pNext;
        index++;
    }

    if(pNode == nullptr && index == expectedLength)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// ĳЩ������ظ���
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 5 };
    Test("Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// û���ظ��Ľ��
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 3, 4, 5, 6, 7 };
    Test("Test2", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// ����һ�����֮���������н���ֵ����ͬ
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2 };
    Test("Test3", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// ���н���ֵ����ͬ
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    Test("Test4", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// ���н�㶼�ɶԳ���
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(2);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(3);
    ListNode* pNode7 = CreateListNode(4);
    ListNode* pNode8 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    Test("Test5", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// �����������֮��������㶼�ɶԳ���
void Test6()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);
    ListNode* pNode8 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2, 4 };
    Test("Test6", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// ������ֻ���������ظ��Ľ��
void Test7()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2 };
    Test("Test7", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// �����ֻ��һ�����
void Test8()
{
    ListNode* pNode1 = CreateListNode(1);

    ConnectListNodes(pNode1, nullptr);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1 };
    Test("Test8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// �����ֻ�������ظ��Ľ��
void Test9()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    Test("Test9", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// ������
void Test10()
{
    ListNode* pHead = nullptr;

    Test("Test10", &pHead, nullptr, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();

    return 0;
}
