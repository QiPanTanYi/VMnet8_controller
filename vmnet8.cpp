#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    string command = "netsh interface set interface \"VMware Network Adapter VMnet8\" admin=";
    string admin = "disable"; // 默认设置为禁用

    // 获取当前状态
    system("netsh interface show interface \"VMware Network Adapter VMnet8\" > statu.txt");
    FILE* fp = fopen("statu.txt", "r");
    if (!fp) {
        cerr << "无法读取 statu.txt" << endl;
        return 1;
    }

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

    // 确保状态已经变更
    Sleep(500);

    // 再次获取最新状态
    system("netsh interface show interface \"VMware Network Adapter VMnet8\" > statu.txt");

    return 0;
}

