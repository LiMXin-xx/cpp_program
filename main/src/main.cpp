//#include <iostream>
//#include <string>
#include <main/utils.h>
#include <others/Animal.h>
#include <others/Carer.h>
//#include <fmt/format.h>
//#include <GLFW/glfw3.h>
#include <stdio.h>
#include <bsp/add.h>
#include <bsp/minus.h>


/**----------------------------------------------------------------*/
int func(int a, int b, int c)
{
    return a * b + c;
}
int add(int a, int b)
{
    return a + b;
}

int main(int argc,char *argv[])
{
//    std::cout << "This is testmain!\n";
//    others::Animal *a = new others::Cat();
//    others::Carer *c = new others::Carer();
//    std::string res = c->care(a);
//    res = start_main::alluppercase(res);
//    std::cout << res << '\n';
//    delete c;
//    delete a;
//
//    std::string s = fmt::format("{0}is{1}", "abra",12);

    int a = 10;
    int b = 100;
    int c = 200;
    printf("%d * %d = %d, Cool!\n", a, b, c);

    return 0;

}