#include <iostream>
#include <vector>
#include<string>
int main()
{
    // 自动推导整型
    auto num = 10;
    auto pi = 3.14;
    auto pii = 3.14f;
    auto ch = 'a';
    auto chars = "Hello,C++";
    auto str = std::string("Hello,C++");
    std::cout << typeid(num).name() << std::endl;
    std::cout << typeid(pi).name() << std::endl;
    std::cout << typeid(pii).name() << std::endl;
    std::cout << typeid(ch).name() << std::endl;
    std::cout << typeid(chars).name() << std::endl;
    std::cout << typeid(str).name() << std::endl;
    std::vector<int> v{1, 2, 3, 4, 5};
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}