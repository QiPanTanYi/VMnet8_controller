#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    string command = "netsh interface set interface \"VMware Network Adapter VMnet8\" admin=";
    string admin = "disable"; // Ĭ������Ϊ����

    // ��ȡ��ǰ״̬
    system("netsh interface show interface \"VMware Network Adapter VMnet8\" > statu.txt");
    FILE* fp = fopen("statu.txt", "r");
    if (!fp) {
        cerr << "�޷���ȡ statu.txt" << endl;
        return 1;
    }

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

    // ȷ��״̬�Ѿ����
    Sleep(500);

    // �ٴλ�ȡ����״̬
    system("netsh interface show interface \"VMware Network Adapter VMnet8\" > statu.txt");

    return 0;
}

