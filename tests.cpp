#include "NextDate.h"
#include <gtest/gtest.h>

void testNextDate(int preYear, int preMonth, int preDay, int nextYear, int nextMonth, int nextDay) {
    Date *a = NewDateInstance(preYear, preMonth, preDay);
    Date *b = NextDate(a);
    ASSERT_FALSE(b == NULL);

    EXPECT_EQ(nextYear, b->year);
    EXPECT_EQ(nextMonth, b->month);
    EXPECT_EQ(nextDay, b->day);
}

void testInvalid(int preYear, int preMonth, int preDay) {
    Date *a = NewDateInstance(preYear, preMonth, preDay);
    Date *b = NextDate(a);
    free(a);
    free(b);
    EXPECT_TRUE(b == NULL);
}

TEST(BoundaryTest, Year) {
    testNextDate(1812, 1, 1, 1812, 1, 2);

    // invalid testing
    testInvalid(1811, 1, 1);
}

TEST(BoundaryTest, Month) {
    testNextDate(2003, 11, 29, 2003, 11, 30);

    // invalid testing
    testInvalid(1876, -1, 1);
}

TEST(BoundaryTest, Day) {
    testNextDate(1901, 4, 2, 1901, 4, 3);

    // invalid testing
    testInvalid(1975, 1, 0);
}

TEST(EquivalentClassTest, SmallMonthNormalYear) {
    testNextDate(1813, 4, 1, 1813, 4, 2);

    // invalid testing
    testInvalid(1989, 4, 31);
}

TEST(EdgeTest, SmallMonthNormalYear) {
    testNextDate(1863, 4, 1, 1863, 4, 2);

    // invalid testing
    testInvalid(1939, 11, 31);
}

TEST(EquivalentClassTest, BigMonthNormalYear) {
    testNextDate(1851, 1, 19, 1851, 1, 20);

    // invalid testing
    testInvalid(1951, 1, 0);
}

TEST(EdgeTest, BigMonthNormalYear) {
    testNextDate(1855, 12, 31, 1856, 1, 1);

    // invalid testing
    testInvalid(2000, 1, 32);
}

TEST(Coverage, C0_1) {
    testInvalid(1992, 1, 40);
}

TEST(Coverage, C2_1) {
    testInvalid(1800, 8, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
