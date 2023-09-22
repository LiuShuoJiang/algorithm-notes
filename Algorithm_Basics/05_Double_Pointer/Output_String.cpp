/*
输入一串字符串(每个单词之间只有一个空格)
要求输出每个单词，每个单词占一行
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[1000];

    fgets(str, 100, stdin);

    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && str[j] != ' ') j++;

        for (int k = i; k < j; k++) cout << str[k];
        cout << endl;

        i = j;
    }

    return 0;
}
