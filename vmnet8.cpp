#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    string command = "netsh interface set interface \"VMware Network Adapter VMnet8\" admin=";
    string admin = "disable"; // 初始状态为禁用

    // 检查当前状态
    system("netsh interface show interface \"VMware Network Adapter VMnet8\" > temp.txt");
    FILE* fp = fopen("temp.txt", "r");
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "已启用")) {
            admin = "disable";
        } else if (strstr(line, "已禁用")) {
            admin = "enable";
        }
    }
    fclose(fp);

    // 切换状态
    command += admin;
    system(command.c_str());

    return 0;
}

