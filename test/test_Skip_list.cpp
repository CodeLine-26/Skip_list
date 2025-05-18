#include <gtest.h>
#include "Skip_list.h"

TEST(SkipListTest, InsertTest) {
    SkipList<int> skipList;
    skipList.insert(5);
    skipList.insert(10);
    skipList.insert(3);

    EXPECT_TRUE(skipList.search(5));
    EXPECT_TRUE(skipList.search(10));
    EXPECT_TRUE(skipList.search(3));
    EXPECT_FALSE(skipList.search(7));
}

TEST(SkipListTest, EraseTest) {
    SkipList<int> skipList;
    skipList.insert(5);
    skipList.insert(10);
    skipList.insert(3);
    skipList.erase(10);

    EXPECT_TRUE(skipList.search(5));
    EXPECT_FALSE(skipList.search(10)); 
    EXPECT_TRUE(skipList.search(3));
    EXPECT_FALSE(skipList.search(7)); 
}

TEST(SkipListTest, EmptyTest) {
    SkipList<int> skipList;

    EXPECT_TRUE(skipList.empty());

    skipList.insert(5);

    EXPECT_FALSE(skipList.empty());
}

TEST(SkipListTest, SizeTest) {
    SkipList<int> skipList;

    EXPECT_EQ(skipList.size(), 0);

    skipList.insert(5);
    skipList.insert(10);
    skipList.insert(3);

    EXPECT_EQ(skipList.size(), 3);
}
TEST(SkipListTest, Insert) {
    SkipList<int> skipList;

    skipList.insert(5);
    ASSERT_TRUE(skipList.search(5));

    skipList.insert(10);
    ASSERT_TRUE(skipList.search(10));
}

TEST(SkipListTest, Search) {
    SkipList<int> skipList;

    skipList.insert(5);
    skipList.insert(10);

    ASSERT_TRUE(skipList.search(5));
    ASSERT_TRUE(skipList.search(10));
    ASSERT_FALSE(skipList.search(3));
}

TEST(SkipListTest, Erase) {
    SkipList<int> skipList;

    skipList.insert(5);
    skipList.insert(10);

    skipList.erase(5);
    ASSERT_FALSE(skipList.search(5));
    ASSERT_TRUE(skipList.search(10));

    skipList.erase(10);
    ASSERT_FALSE(skipList.search(10));
}

TEST(SkipListTest, Size) {
    SkipList<int> skipList;

    ASSERT_EQ(skipList.size(), 0);

    skipList.insert(5);
    ASSERT_EQ(skipList.size(), 1);

    skipList.insert(10);
    ASSERT_EQ(skipList.size(), 2);

    skipList.erase(5);
    ASSERT_EQ(skipList.size(), 1);
}

TEST(SkipListTest, Empty) {
    SkipList<int> skipList;

    ASSERT_TRUE(skipList.empty());

    skipList.insert(5);
    ASSERT_FALSE(skipList.empty());

    skipList.erase(5);
    ASSERT_TRUE(skipList.empty());
}