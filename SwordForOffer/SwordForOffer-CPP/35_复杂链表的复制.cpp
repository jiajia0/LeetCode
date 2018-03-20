#include <iostream>
#include <unordered_map>
#include "Utils/ComplexList.h"

using namespace std;

// ������35����������ĸ���
// ��Ŀ����ʵ�ֺ���ComplexListNode* Clone(ComplexListNode* pHead)����
// ��һ�����������ڸ��������У�ÿ����������һ��m_pNextָ��ָ����һ��
// ����⣬����һ��m_pSibling ָ�������е����������nullptr��

// ��һ�ַ�����ʹ�ù�ϣ��
ComplexListNode* Clone(ComplexListNode* pHead) {

    if(pHead == nullptr)
        return nullptr;

    ComplexListNode* pNode = pHead;
    ComplexListNode* result = nullptr;// ��Ǵ�ʱ��ͷ�ڵ����ڷ���
    unordered_map<ComplexListNode*,ComplexListNode*> cloneNodes;

    // ����һ������
    while(pNode != nullptr) {
        ComplexListNode* pClone = new ComplexListNode();// ����һ���ڵ�
        if(result == nullptr)// ������ؽ��Ϊ�գ����丳ֵ
            result = pClone;
        pClone->m_nValue = pNode->m_nValue;// ���Ƹýڵ��ϵ�����
        pClone->m_pNext = pNode->m_pNext;// ָ����һ��
        pClone->m_pSibling = nullptr;
        cloneNodes[pNode] = pClone;// �����ϣ����
        pNode = pNode->m_pNext;// �ƶ�����һ��
    }

    ComplexListNode* pTempResult = result;
    // ������һ��ָ��
    while(pHead != nullptr) {
        ComplexListNode* pTemp = pHead->m_pSibling;// �õ���һ��ָ��
        pTempResult->m_pSibling = cloneNodes[pTemp];// �ӹ�ϣ�����õ��ڵ㣬������ָ��

        pHead = pHead->m_pNext;
        pTempResult = pTempResult->m_pNext;
    }

    return result;
}

// ====================���Դ���====================
void Test(const char* testName, ComplexListNode* pHead)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode* pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSiblingָ��������
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling�γɻ�
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// ֻ��һ�����
void Test4()
{
    ComplexListNode* pNode1 = CreateNode(1);
    BuildNodes(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// ³���Բ���
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
