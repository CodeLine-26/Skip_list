#include <gtest.h>
#include "Skip_list.h"

class SkipListTesting : public ::testing::Test
{
protected:
    void SetUp() override
    {
        SkipList = new SkipList();
    }
    void TearDown() override
    {
        delete SkipList;
    }
    SkipList* SkipList;
};

TEST_F(SkipListTesting, SingleInsert) 
{
    SkipList->insert(1);
    EXPECT_TRUE(SkipList->search(1));
    EXPECT_FALSE(SkipList->search(2));
}

TEST_F(SkipListTesting, EmptyList) 
{
    EXPECT_FALSE(SkipList->search(1));
    EXPECT_FALSE(SkipList->erase(1));
}

TEST_F(SkipListTesting, DuplicateInserts) 
{
    SkipList->insert(1);
    SkipList->insert(1);
    SkipList->insert(1);

    EXPECT_TRUE(SkipList->erase(1));
    EXPECT_TRUE(SkipList->search(1));
}

TEST_F(SkipListTesting, MultipleInserts) 
{
    SkipList->insert(1);
    SkipList->insert(2);
    SkipList->insert(3);
    SkipList->insert(4);

    EXPECT_TRUE(SkipList->search(1));
    EXPECT_TRUE(SkipList->search(2));
    EXPECT_TRUE(SkipList->search(3));
    EXPECT_TRUE(SkipList->search(4));
    EXPECT_FALSE(SkipList->search(5));
}

TEST_F(SkipListTesting, EraseFromEmpty) 
{
    EXPECT_FALSE(SkipList->erase(1));
}

TEST_F(SkipListTesting, InsertNegativeNumbers)
{
    SkipList->insert(-1);
    SkipList->insert(-2);

    EXPECT_TRUE(SkipList->search(-1));
    EXPECT_TRUE(SkipList->search(-2));
    EXPECT_FALSE(SkipList->search(0));
}

TEST_F(SkipListTesting, PrintNonEmpty) 
{
    SkipList->insert(1);
    SkipList->insert(2);
    testing::internal::CaptureStdout();
    SkipList->print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("1") != std::string::npos);
    EXPECT_TRUE(output.find("2") != std::string::npos);
}