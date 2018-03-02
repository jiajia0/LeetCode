#include <iostream>
#include <string.h>

using namespace std;

// ������17����ӡ1������nλ��
// ��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
// ��ӡ��1��2��3һֱ������3λ����999��

bool Increment(char* number);
void PrintNumber(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number,int length,int index);

void Print1ToMaxOfNDigits_1(int n) {
    if(n <= 0)
        return;

    char* number = new char[n+1];
    memset(number,'0',n);
    number[n] = '\0';

    while(!Increment(number)) {
        PrintNumber(number);
    }
    delete[] number;
}

// ��������������
bool Increment(char* number) {
    bool isOverflow = false;// ��������Ƿ����
    int nTakeOver = 0;// ��λ��ʱ��ʹ�ã�ֵֻ��0��1
    int nLength = strlen(number);

    for(int i=nLength-1;i>=0;i--) {

        int nSum = number[i] - '0' + nTakeOver;
        // �����ʱ����Сλ
        if(i == nLength-1)
            nSum++;
        if(nSum >= 10) {// �������10���λ�������ж��Ƿ��Ѿ����
            if(i == 0)// �˿��Ѿ�������ˣ����Խ���
                isOverflow = true;
            else {// ���н�λ
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        } else {// ���С��10����ֱ�����
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

// ������ӡ����
void PrintNumber(char* number) {
    // ��������ǲ���0
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for(int i=0; i < nLength; i++) {
        // ���ǰ��Ķ���0�����˿̲���0
        if(isBeginning0 && number[i]!='0')
            isBeginning0 = false;
        // �����ͷ��Ϊ0�����ӡ���
        if(!isBeginning0)
            printf("%c",number[i]);
    }
    printf("\t");
}

// ȫ����
void Print1ToMaxOfNDigits_2(int n) {
    if(n <= 0)
        return;
    char* number = new char[n + 1];
    number[n] = '\0';

    for(int i=0; i < 10; i++) {
        number[0] = i+'0';
        Print1ToMaxOfNDigitsRecursively(number,n,0);
    }

    delete[] number;
}
// ���õݹ飬�������001��002��003...099
void Print1ToMaxOfNDigitsRecursively(char* number,int length,int index) {
    if(index == length - 1) {
        PrintNumber(number);
        return;
    }
    for(int i=0; i<10; i++) {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number,length,index+1);
    }
}

// ====================���Դ���====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);
    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}
