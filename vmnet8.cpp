#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    string command = "netsh interface set interface \"VMware Network Adapter VMnet8\" admin=";
    string admin = "disable"; // ��ʼ״̬Ϊ����

    // ��鵱ǰ״̬
    system("netsh interface show interface \"VMware Network Adapter VMnet8\" > temp.txt");
    FILE* fp = fopen("temp.txt", "r");
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "������")) {
            admin = "disable";
        } else if (strstr(line, "�ѽ���")) {
            admin = "enable";
        }
    }
    fclose(fp);

    // �л�״̬
    command += admin;
    system(command.c_str());

    return 0;
}

