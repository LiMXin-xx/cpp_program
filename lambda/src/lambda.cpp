//
// Created by LiMXin-PC on 2023/4/16.
//

#include "lambda/lambda.h"
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : lambda.c
  * @brief          : lambda program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021.
  * All rights reserved.
  *
  * 
  * 
  * 
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/*** Includes ------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
/** Private includes ----------------------------------------------------------*/
/** USER CODE BEGIN Includes */

/** USER CODE END Includes */

/*** Private typedef -----------------------------------------------------------*/
/** USER CODE BEGIN PTD */
class A {
public:
    void print() {
        std::cout << "class A" << std::endl;
    }

    void test() {
        auto foo = [this] {
            print();
            x = 5;
        };
        foo();
    }

private:
    int x;
};

class Bar {
public:
    Bar(int x, int y) : x_(x), y_(y) {}

    int operator()() {
        return x_ * y_;
    }

private:
    int x_;
    int y_;
};
/** USER CODE END PTD */

/*** Private define ------------------------------------------------------------*/
/** USER CODE BEGIN PD */

/** USER CODE END PD */

/*** Private macro -------------------------------------------------------------*/
/** USER CODE BEGIN PM */

/** USER CODE END PM */

/*** Private variables ---------------------------------------------------------*/
/** USER CODE BEGIN PV */

/** USER CODE END PV */

/*** Private function prototypes -----------------------------------------------*/
static void lambda_test01()
{
    int x = 5;
    auto foo = [&x](int y)mutable -> double {
        x = 6;
        return x * y;
    };
    std::cout << foo(8) << std::endl;
    std::cout << x << std::endl;
}
int a = 1;
static void lambda_test02()
{
    int y = 5;
    static int z = 3;

    auto foo = [y](int x) {
        x = a;
        return x + y + z;
    };

    std::cout << foo(10) << std::endl;
}
static void lambda_test03()
{
    int x = 1;
    auto foo = [x]()mutable {
        x++;
        std::cout << x << std::endl;
    };

    foo();
    foo();
    foo();
    foo();
}

static void lambda_test04()
{
//    auto *a = new A;
    A a;

    a.test();

    int x = 1;
    int y = 5;
    auto foo = [=]{

        return x + y;
    };
    std::cout << foo() << std::endl;
//    delete a;
}

static void lambda_test05()
{
    int x = 1;
    int y = 5;

    auto foo = [x, y] { return x * y; };
    Bar bar(x, y);
    std::cout << "foo() = " << foo() << std::endl;
    std::cout << "bar() = " << bar() << std::endl;
}

static void lambda_test06()
{
    std::vector<int> x = {1, 2, 3, 4};

    std::cout << *std::find_if(
            x.cbegin(),
            x.cend(),
            [](int i) {
                return i % 3 == 0;
            }
    ) << std::endl;
}

static void lambda_test07()
{
    //01
//    auto *p = +[] { return 6; };
    //02
//    static int a = 42;
//    auto p = [=] { ++a; };
//    std::cout << sizeof p << std::endl;
//    std::cout << "a = " << a << std::endl;
//    p();
    //03
//    float x;
//    float &r = x;
//    auto p = [=]() {};
//    std::cout << sizeof p << std::endl;
    //04
//    const int N = 10;
//    auto p = [] {
//        int arr[N];
//    };
//    std::cout << sizeof p << std::endl;
    //05
//    const int N = 10;
//    auto p = [=] {
//        int p = N;
//    };
//    std::cout << sizeof p << std::endl;
    //06
    const int x = 17;
    auto g = [=](auto a) {
        typeid(a + x);
    };
    std::cout << sizeof g << std::endl;
}

static void lambda_test08()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    auto f = [](int a, int b) {
        return a > b;
    };

    std::sort(vec.begin(), vec.end(), f);
    
}
/** USER CODE BEGIN PFP */
void lambda_demo(void)
{
//    lambda_test01();
//    lambda_test02();
//    lambda_test03();
//    lambda_test04();
//    lambda_test05();
//    lambda_test06();
//    lambda_test07();
    lambda_test08();
}
/** USER CODE END PFP */

/*** Private user code ---------------------------------------------------------*/
/** USER CODE BEGIN 0 */

/** USER CODE END 0 */
