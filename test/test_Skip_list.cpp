#include <gtest.h>
#include "Skip_list.h"


TEST(SkipListTest, InsertAndSearch) {
    SkipList<int> list;
    list.insert(3);
    list.insert(6);
    list.insert(2);
    list.insert(9);
    EXPECT_TRUE(list.search(3));
    EXPECT_TRUE(list.search(6));
    EXPECT_TRUE(list.search(2));
    EXPECT_TRUE(list.search(9));
    EXPECT_FALSE(list.search(1));
    EXPECT_FALSE(list.search(10));
}

TEST(SkipListTest, Erase) {
    SkipList<int> list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.erase(10);
    EXPECT_FALSE(list.search(10));
    EXPECT_TRUE(list.search(5));
    EXPECT_TRUE(list.search(15));
    list.erase(20);
    EXPECT_EQ(list.size(), 2);
}

TEST(SkipListTest, SizeAndEmpty) {
    SkipList<int> list;
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    list.insert(1);
    list.insert(2);
    EXPECT_EQ(list.size(), 2);
    EXPECT_FALSE(list.empty());
    list.erase(1);
    EXPECT_EQ(list.size(), 1);
    list.erase(2);
    EXPECT_TRUE(list.empty());
}

TEST(SkipListTest, Duplicates) {
    SkipList<int> list;
    list.insert(5);
    list.insert(5);  
    EXPECT_EQ(list.size(), 1);  
}

TEST(SkipListTest, Print) {
    SkipList<int> list;
    list.insert(1);
    list.insert(3);
    list.insert(2);
    EXPECT_NO_THROW(list.print());
}

TEST(SkipListTest, Clear) {
    SkipList<int> list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.erase(10);
    list.erase(20);
    list.erase(30);
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(SkipListTest, MaxLevel) {
    SkipList<int> list(5, 0.5); 
    for (int i = 0; i < 100; ++i) 
    {
        list.insert(i);
    }
    EXPECT_NO_THROW(list.print());
}
