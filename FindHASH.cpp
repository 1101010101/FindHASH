#include <iostream>
#include <fstream>
#include "CreateSHA256.h"
#include<cstdlib>
#include<time.h>



//从标准输入读取
void from_input()
{
    std::string src_str;
    std::string hash_hex_str;
    std::cin >> src_str;
    std::string src_str_x = src_str;
    hash_hex_str = picosha2::hash256_hex_string(src_str_x.begin(), src_str_x.end());
    int a = 0;
    std::string str = hash_hex_str.substr(0, 6);

    clock_t start, finish;
    double totaltime;
    start = clock();

    while(str != "000000")
    {
        src_str_x = src_str + std::to_string(a);
        hash_hex_str = picosha2::hash256_hex_string(src_str_x.begin(), src_str_x.end());
        str = hash_hex_str.substr(0, 6);
        //system("cls");
 //       std::cout << "正在进行第" << a << "次尝试"<<std::endl;
        ++a;
    }

    finish = clock();
    totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
    std::cout << "\n挖矿时间为" << totaltime << "秒！" << std::endl;

    std::cout << src_str_x << std::endl;
    std::cout << "Number : " << a << std::endl;
    std::cout << hash_hex_str << std::endl;
}

int main(int argc, char* argv[])
{
 //   from_string();

 //  from_bytes();

 //   from_file();

    from_input();
 //   system("pause");
    return 0;
}
