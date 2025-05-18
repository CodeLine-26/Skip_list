#include <gtest.h>
#include "Skip_list.h"

class SkipListTesting : public ::testing::Test
{
protected:
    void SetUp() override
    {
        skip_list = new SkipList();
    }
    void TearDown() override
    {
        delete skip_list;
    }
};

TEST_F(SkipListTesting, SingleInsert) 
{
    skip_list->insert(1);
    EXPECT_TRUE(skip_list->search(1));
    EXPECT_FALSE(skip_list->search(2));
}

TEST_F(SkipListTesting, EmptyList) 
{
    EXPECT_FALSE(skip_list->search(1));
    EXPECT_FALSE(skip_list->erase(1));
}

TEST_F(SkipListTesting, DuplicateInserts) 
{
    skip_list->insert(1);
    skip_list->insert(1);
    skip_list->insert(1);

    EXPECT_TRUE(skip_list->erase(1));
    EXPECT_TRUE(skip_list->search(1));
}

TEST_F(SkipListTesting, MultipleInserts) 
{
    skip_list->insert(1);
    skip_list->insert(2);
    skip_list->insert(3);
    skip_list->insert(4);

    EXPECT_TRUE(skip_list->search(1));
    EXPECT_TRUE(skip_list->search(2));
    EXPECT_TRUE(skip_list->search(3));
    EXPECT_TRUE(skip_list->search(4));
    EXPECT_FALSE(skip_list->search(5));
}

TEST_F(SkipListTesting, EraseFromEmpty) 
{
    EXPECT_FALSE(skip_list->erase(1));
}

TEST_F(SkipListTesting, InsertNegativeNumbers)
{
    skip_list->insert(-1);
    skip_list->insert(-2);

    EXPECT_TRUE(skip_list->search(-1));
    EXPECT_TRUE(skip_list->search(-2));
    EXPECT_FALSE(skip_list->search(0));
}

TEST_F(SkipListTesting, MaxLevelInsert) 
{
    for (int i = 0; i < 1000; ++i) {
        skip_list->insert(rand() % 10000);
    }
    EXPECT_TRUE(true);
}

TEST_F(SkipListTesting, PrintNonEmpty) 
{
    skip_list->insert(1);
    skip_list->insert(2);
    testing::internal::CaptureStdout();
    skip_list->print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("1") != std::string::npos);
    EXPECT_TRUE(output.find("2") != std::string::npos);
}