#include <iostream>
#include <vector>
using namespace std;

// Sunday字符串匹配，在str中匹配p ，返回结果为 p开始的位置，匹配失败返回-1
int Sunday(string str, string p) {
    int start = 0;

    vector<int> next(256, 0); // hash 表，存储p中字符的位置，用来计算下次的偏移量

    for(int i = 0; i < p.size(); i++) {
        next[p[i]] = i;
    }

    while(start <= str.size() - p.size()) {
        int i = 0; // 相对于start位置的偏移量
        while(str[start + i] == p[i]) {
            i++;
            if(i == p.size()) // 偏移量等于则说明匹配成功
                return start;
        }

        if(start + p.size() >= str.size()) { // 若此时已经检测到最后一个字符
            return -1;
        }

        // 若没有匹配成功，则需将start向后移动
        // 若索引为：start + p.size() + 1 的元素不在p中，则直接向后移动 p.size()位。
        if(next[str[start + p.size()]]) { // 如果下一个字符在p中出现，则next[start + i]的值就是需要移动的
            start += p.size() - next[str[start + p.size()]];
        } else { // 若下一个字符没有出现，则start 向后 走p.size()个位置
            start += p.size();
        }
    }
    return -1;
}

int main() {
    string str = "here is a example";
    //string p = "example"; // 10
    string p = "le";
    int ans = Sunday(str, p);
    cout << ans;
    return 0;
}
