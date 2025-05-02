#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "student.h"

// Test getGrade function
void test_getGrade() {
    CU_ASSERT_EQUAL(getGrade(95), 'A');
    CU_ASSERT_EQUAL(getGrade(85), 'B');
    CU_ASSERT_EQUAL(getGrade(75), 'C');
    CU_ASSERT_EQUAL(getGrade(65), 'D');
    CU_ASSERT_EQUAL(getGrade(50), 'F');
}

// Test student calculations
void test_studentCalculations() {
    Student testStudent = { "Alice", 101, {85, 90, 80}, 0, 0, 1 };
    testStudent.total = testStudent.marks[0] + testStudent.marks[1] + testStudent.marks[2];
    testStudent.average = testStudent.total / 3;

    CU_ASSERT_EQUAL(testStudent.total, 255);
    CU_ASSERT_EQUAL(testStudent.average, 85);
    CU_ASSERT_EQUAL(getGrade(testStudent.average), 'B');
}

// Setup and Cleanup Functions (if needed)
int setup() { return 0; }
int teardown() { return 0; }

int main() {
    CU_initialize_registry();

    CU_pSuite pSuite = CU_add_suite("Student_Test_Suite", setup, teardown);
    
    CU_add_test(pSuite, "test_getGrade", test_getGrade);
    CU_add_test(pSuite, "test_studentCalculations", test_studentCalculations);
    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return 0;
}
