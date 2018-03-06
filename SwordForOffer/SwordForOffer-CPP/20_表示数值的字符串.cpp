#include <iostream>
using namespace std;

// ������20����ʾ��ֵ���ַ���
// ��Ŀ����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬
// �ַ�����+100������5e2������-123������3.1416������-1E-16������ʾ��ֵ������12e����
// ��1a3.14������1.2.3������+-5������12e+5.4��������

// ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ������A��C����
// �����������������ţ�Ҳ����û�У�����B��һ���޷�������

bool scanUnsignedInteger(const char** str) {
    const char* before = *str;// ��¼�´�ʱ��λ��
    while(**str!='\0' && **str>='0' && **str<='9')// �������0��9��������ƶ�
        (*str)++;
    return *str > before;// ���������˵������0��9������
}

// �����ж��Ƿ��ʾ����
bool scanInterger(const char** str) {
    if(**str == '+' || **str == '-')// �����ʱ��ͷ������+����-��������ƶ�һλԽ������
        (*str)++;
    return scanUnsignedInteger(str);
}

bool isNumeric(const char* str) {
    if(str == nullptr)
        return false;
    // ɨ�������ţ��Լ�����
    bool numeric = scanInterger(&str);

    // ����С���㣬����Ĳ��־���С��������
    if(*str == '.') {
        str++;
        // ����ʹ�õ���'��'��������'��'��
        // ��Ϊ�����numeric�����С����ǰ��Ĳ����ˣ�
        // 1. С������û���������֣����磺.123 == 0.123 ����ʱ||֮ǰ�ļ�����true��||֮��������false
        // 2. С����������û�����֣����磺233. == 233.0 , ��ʱ||֮ǰ��Ϊfalse��||֮��������true��
        // 3. С����ǰ�������֣���ʱ||ǰ����true��
        numeric = scanUnsignedInteger(&str) || numeric;
    }
    // ����'e'����'E'������ľ���ָ��������
    if(*str == 'e' || *str == 'E') {
        str++;
        // ��ʱ������&& ����Ϊeǰ�󶼱���Ҫ����������
        numeric = numeric && scanInterger(&str);
    }
    return numeric && *str=='\0';// ��ʱӦ���ǽ�������
}

// ====================���Դ���====================
void Test(const char* testName, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    Test("Test21", nullptr, false);

    return 0;
}
