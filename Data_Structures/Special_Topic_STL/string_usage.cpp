#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string a = "yes";
    a += "def";
    a += 'c';
    cout << a <<endl;

    //substr(x, y)中x代表起始位置，y代表截取长度(不是截止位置！)
    cout << a.substr(1, 2) << endl;
    cout << a.substr(1, 10) << endl;
    cout << a.substr(2) << endl;

    printf("%s\n", a.c_str()); //c_str()返回string存储的字符数组的起始地址

    return 0;
}