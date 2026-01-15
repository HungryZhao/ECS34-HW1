#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    // I summarize various test cases and ask claude to implement them
    // Since most of them are same.
    // Henry Zhao

	EXPECT_EQ(StringUtils::Slice("hello", 1, 3), "el");
	EXPECT_EQ(StringUtils::Slice("hello", 0, 5), "hello");

	// end==0 -> end of str
	EXPECT_EQ(StringUtils::Slice("hello", 2), "llo");
	EXPECT_EQ(StringUtils::Slice("hello", 1, 0), "ello");

	// - indices like py
	EXPECT_EQ(StringUtils::Slice("hello", -2), "lo");
	EXPECT_EQ(StringUtils::Slice("hello", 0, -1), "hell");
	EXPECT_EQ(StringUtils::Slice("hello", -4, -1), "ell");

	// out-of-range indices
	EXPECT_EQ(StringUtils::Slice("hello", -100, 2), "he");
	EXPECT_EQ(StringUtils::Slice("hello", 1, 100), "ello");
	EXPECT_EQ(StringUtils::Slice("hello", 100, 0), "");

	// Empty
	EXPECT_EQ(StringUtils::Slice("", 0), "");
	EXPECT_EQ(StringUtils::Slice("hello", 3, 1), "");
}

TEST(StringUtilsTest, Capitalize){
    
}

TEST(StringUtilsTest, Upper){
    
}

TEST(StringUtilsTest, Lower){
    
}

TEST(StringUtilsTest, LStrip){
    
}

TEST(StringUtilsTest, RStrip){
    
}

TEST(StringUtilsTest, Strip){
    
}

TEST(StringUtilsTest, Center){
    
}

TEST(StringUtilsTest, LJust){
    
}

TEST(StringUtilsTest, RJust){
    
}

TEST(StringUtilsTest, Replace){
    
}

TEST(StringUtilsTest, Split){
    
}

TEST(StringUtilsTest, Join){
    
}

TEST(StringUtilsTest, ExpandTabs){
    
}

TEST(StringUtilsTest, EditDistance){
    
}
