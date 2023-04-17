#include <iostream>
#include <string>
#include <main/utils.hpp>
#include <others/Animal.h>
#include <others/Carer.h>
#include <lambda/lambda.h>
#include <fmt/format.h>
#include <GLFW/glfw3.h>
#include <bsp/add.h>
#include <bsp/minus.h>
#include <pthread.h>

/**----------------------------------------------------------------*/

/**----------------------------------------------------------------*/
int main(int argc,char *argv[])
{
    std::cout << "THIS PROGRAM IS c/c++ project" << std::endl;

    others::Animal *a = new others::Cat();
    others::Carer *c = new others::Carer();
    std::string res = c->care(a);
    res = start_main::alluppercase(res);
    std::cout << res << '\n';
    delete c;
    delete a;

    std::string s = fmt::format("{0}is{1}", "abra", 12);

    std::cout << add_int(20, 30) << std::endl;
    std::cout << minus_int(20, 30) << std::endl;
/**----------------------------------------------------------------*/
    std::cout << "This is test for main!\n";
    lambda_demo();

    return 0;

}