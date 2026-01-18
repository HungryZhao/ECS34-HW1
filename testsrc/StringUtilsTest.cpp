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
	EXPECT_EQ(StringUtils::Capitalize(""), "");
	EXPECT_EQ(StringUtils::Capitalize("a"), "A");
	EXPECT_EQ(StringUtils::Capitalize("hello"), "Hello");
	EXPECT_EQ(StringUtils::Capitalize("hELLo"), "Hello");
	EXPECT_EQ(StringUtils::Capitalize("123ABC"), "123abc");
    EXPECT_EQ(StringUtils::Capitalize("ABC123"), "Abc123");
}

TEST(StringUtilsTest, Upper){
	EXPECT_EQ(StringUtils::Upper(""), "");
	EXPECT_EQ(StringUtils::Upper("Abc!"), "ABC!");
	EXPECT_EQ(StringUtils::Upper("already UPPER"), "ALREADY UPPER");
}

TEST(StringUtilsTest, Lower){
	EXPECT_EQ(StringUtils::Lower(""), "");
	EXPECT_EQ(StringUtils::Lower("AbC!"), "abc!");
	EXPECT_EQ(StringUtils::Lower("already lower"), "already lower");
}

TEST(StringUtilsTest, LStrip){
	EXPECT_EQ(StringUtils::LStrip(""), "");
	EXPECT_EQ(StringUtils::LStrip("abc"), "abc");
	EXPECT_EQ(StringUtils::LStrip("   abc"), "abc");
	EXPECT_EQ(StringUtils::LStrip("\t\n  abc"), "abc");
	EXPECT_EQ(StringUtils::LStrip("   a b c"), "a b c");
}

TEST(StringUtilsTest, RStrip){
	EXPECT_EQ(StringUtils::RStrip(""), "");
	EXPECT_EQ(StringUtils::RStrip("abc"), "abc");
	EXPECT_EQ(StringUtils::RStrip("abc   "), "abc");
	EXPECT_EQ(StringUtils::RStrip("abc\t\n  "), "abc");
	EXPECT_EQ(StringUtils::RStrip("a b c   "), "a b c");
}

TEST(StringUtilsTest, Strip){
	EXPECT_EQ(StringUtils::Strip(""), "");
	EXPECT_EQ(StringUtils::Strip("abc"), "abc");
	EXPECT_EQ(StringUtils::Strip("   abc   "), "abc");
	EXPECT_EQ(StringUtils::Strip("\t\n  abc\r\n"), "abc");
	EXPECT_EQ(StringUtils::Strip("   a b c   "), "a b c");
	EXPECT_EQ(StringUtils::Strip("     "), "");
}

TEST(StringUtilsTest, Center){
	EXPECT_EQ(StringUtils::Center("", 0), "");
	EXPECT_EQ(StringUtils::Center("hi", 1), "hi");    
	EXPECT_EQ(StringUtils::Center("hi", 2), "hi");
    EXPECT_EQ(StringUtils::Center("hi", -3), "hi");
	EXPECT_EQ(StringUtils::Center("hi", 4), " hi ");
	EXPECT_EQ(StringUtils::Center("hi", 5), " hi  ");
	EXPECT_EQ(StringUtils::Center("hi", 5, '*'), "*hi**");
}

TEST(StringUtilsTest, LJust){

	EXPECT_EQ(StringUtils::LJust("", 0), "");
	EXPECT_EQ(StringUtils::LJust("hi", 2), "hi");
	EXPECT_EQ(StringUtils::LJust("hi", 1), "hi");
	EXPECT_EQ(StringUtils::LJust("hi", -1), "hi");
	EXPECT_EQ(StringUtils::LJust("hi", 5), "hi   ");
	EXPECT_EQ(StringUtils::LJust("hi", 5, '*'), "hi***");
}

TEST(StringUtilsTest, RJust){
	EXPECT_EQ(StringUtils::RJust("", 0), "");
	EXPECT_EQ(StringUtils::RJust("hi", 2), "hi");
	EXPECT_EQ(StringUtils::RJust("hi", 1), "hi");
	EXPECT_EQ(StringUtils::RJust("hi", -1), "hi");
	EXPECT_EQ(StringUtils::RJust("hi", 5), "   hi");
	EXPECT_EQ(StringUtils::RJust("hi", 5, '*'), "***hi");
}

TEST(StringUtilsTest, Replace){

	EXPECT_EQ(StringUtils::Replace("hello", "l", "L"), "heLLo");
	EXPECT_EQ(StringUtils::Replace("aaaa", "aa", "b"), "bb");
	EXPECT_EQ(StringUtils::Replace("hello", "xyz", "Q"), "hello");
	EXPECT_EQ(StringUtils::Replace("banana", "na", ""), "ba");

	EXPECT_EQ(StringUtils::Replace("abc", "", "-"), "-a-b-c-");
	EXPECT_EQ(StringUtils::Replace("", "", "-"), "-");
    
}

TEST(StringUtilsTest, Split){
	EXPECT_EQ(StringUtils::Split("  a   b\tc\n"), (std::vector<std::string>{"a", "b", "c"}));
	EXPECT_EQ(StringUtils::Split("   \t\n  "), (std::vector<std::string>{}));
	EXPECT_EQ(StringUtils::Split(""), (std::vector<std::string>{}));

	EXPECT_EQ(StringUtils::Split("a,b,c", ","), (std::vector<std::string>{"a", "b", "c"}));
	EXPECT_EQ(StringUtils::Split("a,,b,", ","), (std::vector<std::string>{"a", "", "b", ""}));
	EXPECT_EQ(StringUtils::Split("abc", ","), (std::vector<std::string>{"abc"}));
	EXPECT_EQ(StringUtils::Split("", ","), (std::vector<std::string>{""}));
	EXPECT_EQ(StringUtils::Split("a--b----c", "--"), (std::vector<std::string>{"a", "b", "", "c"}));
}

TEST(StringUtilsTest, Join){
	EXPECT_EQ(StringUtils::Join(",", (std::vector<std::string>{})), "");
	EXPECT_EQ(StringUtils::Join(",", (std::vector<std::string>{"a"})), "a");
	EXPECT_EQ(StringUtils::Join(",", (std::vector<std::string>{"a", "b", "c"})), "a,b,c");
	EXPECT_EQ(StringUtils::Join("", (std::vector<std::string>{"a", "b", "c"})), "abc");
	EXPECT_EQ(StringUtils::Join("-", (std::vector<std::string>{"", "x", ""})), "-x-");
}

TEST(StringUtilsTest, ExpandTabs){
	EXPECT_EQ(StringUtils::ExpandTabs(""), "");
	EXPECT_EQ(StringUtils::ExpandTabs("a\tb"), "a   b");
	EXPECT_EQ(StringUtils::ExpandTabs("abcd\te"), "abcd    e");
	EXPECT_EQ(StringUtils::ExpandTabs("a\t\tb"), "a       b");
	EXPECT_EQ(StringUtils::ExpandTabs("a\tb\nc\td"), "a   b\nc   d");

	EXPECT_EQ(StringUtils::ExpandTabs("a\tb", 2), "a b");
	EXPECT_EQ(StringUtils::ExpandTabs("a\tb", 0), "ab");
}

TEST(StringUtilsTest, EditDistance){
	EXPECT_EQ(StringUtils::EditDistance("", ""), 0);
	EXPECT_EQ(StringUtils::EditDistance("a", ""), 1);
	EXPECT_EQ(StringUtils::EditDistance("", "abc"), 3);
	EXPECT_EQ(StringUtils::EditDistance("abc", ""), 3);	
	EXPECT_EQ(StringUtils::EditDistance("kitten", "sitting"), 3); // example from geeksforgeeks - Henry
	EXPECT_EQ(StringUtils::EditDistance("flaw", "lawn"), 2);
	EXPECT_EQ(StringUtils::EditDistance("asdddf", "acddde"), 2);

	EXPECT_EQ(StringUtils::EditDistance("AbC", "aBc", false), 3);
	EXPECT_EQ(StringUtils::EditDistance("AbC", "aBc", true), 0);

	
	EXPECT_EQ(StringUtils::EditDistance("abc", "yabc"), StringUtils::EditDistance("yabc", "abc"));
}
