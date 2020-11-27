// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
// 说明：本题中，我们将空字符串定义为有效的回文串。
// https://leetcode-cn.com/leetbook/read/top-interview-questions/xah8k6/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if(!isalnum(s[i])) {  // isalnum：判断字符是否为字母或者数字
            i++;
            continue;
        }
        if(!isalnum(s[j])) {
            j--;
            continue;
        }
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i] - 'A') + 'a';
        }
        if(s[j] >= 'A' && s[j] <= 'Z') {
            s[j] = (s[j] - 'A') + 'a';
        }
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    string s = " as";
    if(isPalindrome(s)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}
