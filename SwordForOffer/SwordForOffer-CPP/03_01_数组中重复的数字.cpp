#include <iostream>

using namespace std;

//��һ������Ϊn����������������ֶ���0~n-1�ķ�Χ�ڡ�
//������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
//Ҳ��֪��ÿ�������ظ��˼��Σ����ҳ�����������һ���ظ�������.

bool duplicate(int numbers[], int length, int* duplication) {
    // ���
    if(numbers == nullptr || length <= 0) {
        return false;
    }
    // ������������Ƿ���Ч
    for(int i=0; i < length; i++) {
        if(numbers[i] < 0 || numbers[i] > length-1 ) {
            return false;
        }
    }

    // LeetCode�ⷨ
    for(int i=0; i<length; i++) {
        int temp = abs(numbers[i]);
        if(numbers[temp] < 0) {
            *duplication = -numbers[temp];
            return true;
        }
        numbers[temp] = -numbers[temp];
    }

    // ���нⷨ
    /*// ��������
    for(int i=0; i<length; i++) {
        // ��ǰ�±�������Ԫ�ز����
        while(numbers[i] != i) {
            // �����ǰԪ�����Ե�ǰԪ��Ϊ�±��λ���Ϸ�Ԫ����ȣ���˵���ظ�
            if(numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }

            // ����Numbers[i] �� numbser[numbser[i]]
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;

        }
    }*/

    return false;
}

// ====================���Դ���====================
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// �ظ�����������������С������
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �ظ�����������������������
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �����д��ڶ���ظ�������
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// û���ظ�������
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// û���ظ�������
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// ��Ч������
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 1;
}
