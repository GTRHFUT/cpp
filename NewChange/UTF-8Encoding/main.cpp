#include <iostream>
#include <windows.h>  // Windows 系统专用设置
int main() {
    // 设置控制台编码为 UTF-8
    SetConsoleOutputCP(65001);
    // 输出测试
    std::cout << "你好，世界！" << std::endl;

    system("pause");
    return 0;
}