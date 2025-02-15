#include "../src/hillsFinder.h"
#include <gtest/gtest.h>
#include <vector>

TEST(HillDetectionTest, MedianTest) {
  std::vector<float> data1 = {1, 2, 3, 4, 5};
  EXPECT_DOUBLE_EQ(median(data1), 3.0);

  std::vector<float> data2 = {1, 2, 3, 4, 5, 6};
  EXPECT_DOUBLE_EQ(median(data2), 3.5);
}

TEST(HillDetectionTest, FindHills) {

  const std::vector<float> data = readBinaryFile("detector_src_32f.bin");
  const auto hills = findHills(data, 3, 1000);
  ASSERT_EQ(hills.size(), 73539);
  EXPECT_EQ(hills[0], std::make_pair(0, 7));
}

TEST(HillDetectionTest, MaxHill) {

  const std::vector<float> data = readBinaryFile("detector_src_32f.bin");
  const auto hills = findHills(data, 100000, 300000);
  ASSERT_EQ(hills.size(), 1);
  EXPECT_EQ(hills[0], std::make_pair(649960, 760443));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
