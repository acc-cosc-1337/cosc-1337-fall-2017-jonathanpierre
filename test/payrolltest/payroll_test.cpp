#include "gtest/gtest.h"
#include "Payroll.h"

TEST(payrollTest, test_overtimeHours_returns_correct){
    EXPECT_EQ(5, getOvertimeHours(45));
}  
 TEST(payrollTest, test_RegularHours_returns_correct){
    EXPECT_EQ(40, getRegularHours(50, 10));
 }

TEST(payrollTest2, test_GetfIT_returns_positive){
    EXPECT_EQ(15, getfIT(100, .15));
}

TEST(payrollTest2, test_GetFIT_returns_negative){
    EXPECT_EQ(-15, getfIT(-100, .15));
}

TEST(payrollTest2, test_GetOvertimeStatus_for_overtime_true){
    EXPECT_EQ(true, getOvertimeStatus(45));
}

TEST(payrollTest2, test_GetOvertimeStatus_for_overtime_false){
    EXPECT_EQ(false, getOvertimeStatus(35));
}


TEST(payrollTest2, test_getNetPay_for_positive){
    EXPECT_EQ(25, getNetPay(100, 25, 25, 25));
}


TEST(payrollTest2, test_getNetPay_when_0){
    EXPECT_EQ(0, getNetPay(0, 0, 0, 0));
}
