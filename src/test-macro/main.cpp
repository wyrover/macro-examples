//#define CATCH_CONFIG_RUNNER
//#include <catch/catch.hpp>

#include <gtest/gtest.h>
#include <Windows.h>
#include <tchar.h>
#include <time.h>
#include <ATLComTime.h>
#include <stdio.h>
#include <iostream>
#include "fun.h"

#define GP_SCRIPT_EVENT(eventName, eventArgs) \
    struct SCRIPT_EVENT_ ## eventName \
    { \
        SCRIPT_EVENT_ ## eventName() \
        { \
        printf(#eventName ## "\n"); \
        } \
    public: \
        int val1; \
    }; \
    SCRIPT_EVENT_ ## eventName eventName;


TEST(macro, GP_SCRIPT_EVENT)
{
    GP_SCRIPT_EVENT(test_rover, "1111");

    test_rover.val1 = 1111;
    printf("%d", test_rover.val1);


}





int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    system("pause");
    return ret;
}