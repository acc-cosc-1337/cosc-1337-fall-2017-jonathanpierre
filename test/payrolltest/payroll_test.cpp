#include "gtest/gtest.h"
#include "Payroll.h"

TEST(payrollTest, test_overtimeHours_returns_correct){
    EXPECT_EQ(5, getOvertimeHours(45));
}  
 TEST(payrollTest, test_RegularHours_returns_correct){
    EXPECT_EQ(40, getRegularHours(50, 10));
 }

Test(payrollTest2, test_GetFIT_returns_correct){
    EXPECT_EQ(15, getFIT(100));
}

Test(payrollTest2, test_GetOvertimeStatus_for_overtime_true){
    EXPECT_EQ(true, getOvertimeStatus(45));
}

Test(payrollTest2, test_GetOvertimeStatus_for_overtime_false){
    EXPECT_EQ(false, getOvertimeStatus(35));
}
