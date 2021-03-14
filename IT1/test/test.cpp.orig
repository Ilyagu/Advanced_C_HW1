// Copyright 2021 Nagdimaev Ilyagu

#include <cstdio>
#include <fstream>

#include "gtest/gtest.h"

extern "C" {
    #include "func/func.h"
}

class FindQuality : public ::testing::Test {
 protected:
    void SetUp() {
        test_result = new char*[5];
        for (int i = 0; i < 5; i++) {
            test_result[i] = new char[100];
        }

        strncpy(test_result[0], "Отличное", 100);
        strncpy(test_result[1], "Хорошее", 100);
        strncpy(test_result[2], "Плохое", 100);
        strncpy(test_result[3], "Ужасное", 100);
        strncpy(test_result[4], "Фейк", 100);
    }
    void TearDown() {
        for (int i = 0; i < 5; i++) {
            delete []test_result[i];
        }
        delete []test_result;
    }
    char **test_result;
};

TEST_F(FindQuality, find_quality1) {
    EXPECT_EQ(0, find_quality(test_result[0]));
}

TEST_F(FindQuality, find_quality2) {
    EXPECT_EQ(20, find_quality(test_result[1]));
}

TEST_F(FindQuality, find_quality3) {
    EXPECT_EQ(35, find_quality(test_result[2]));
}

TEST_F(FindQuality, find_quality4) {
    EXPECT_EQ(50, find_quality(test_result[3]));
}

TEST_F(FindQuality, invalid_quallity) {
    EXPECT_EQ(200, find_quality(test_result[4]));
}

//
// test decrypt
//

TEST(decrypt, decrypt1) {
    EXPECT_STREQ("Таких дорог нет!", decrypt(0));
}

TEST(decrypt, decrypt2) {
    EXPECT_STREQ("Ужасное", decrypt(50));
}

TEST(decrypt, decrypt3) {
    EXPECT_STREQ("Плохое", decrypt(60));
}

TEST(decrypt, decrypt4) {
    EXPECT_STREQ("Хорошее", decrypt(72));
}

TEST(decrypt, decrypt5) {
    EXPECT_STREQ("Отличное", decrypt(95));
}

TEST(decrypt, decrypt6) {
    EXPECT_STREQ("ERROR", decrypt(200));
}


//
// test qual
//

class TestQual : public ::testing::Test {
 protected:
    void SetUp() {
        test_result = new char*[6];
        for (int i = 0; i < 6; i++) {
            test_result[i] = new char[100];
        }

        strncpy(test_result[0], "Отличное", 100);
        strncpy(test_result[1], "Хорошее", 100);
        strncpy(test_result[2], "Плохое", 100);
        strncpy(test_result[3], "Ужасное", 100);
        strncpy(test_result[4], "Асфальт", 100);
        strncpy(test_result[5], "Грунт", 100);

        all_roads = reinterpret_cast<Road *>(malloc(sizeof(Road) * 6));

        all_roads[0].length = 200;
        strncpy(all_roads[0].type, test_result[5], 50);
        strncpy(all_roads[0].quality, test_result[0], 50);
        all_roads[0].lanes = 3;

        all_roads[1].length = 200;
        strncpy(all_roads[1].type, test_result[5], 50);
        strncpy(all_roads[1].quality, test_result[0], 50);
        all_roads[1].lanes = 3;

        all_roads[2].length = 200;
        strncpy(all_roads[2].type, test_result[5], 50);
        strncpy(all_roads[2].quality, test_result[3], 50);
        all_roads[2].lanes = 3;

        all_roads[3].length = 200;
        strncpy(all_roads[3].type, test_result[5], 50);
        strncpy(all_roads[3].quality, test_result[3], 50);
        all_roads[3].lanes = 3;

        all_roads[4].length = 200;
        strncpy(all_roads[4].type, test_result[4], 50);
        strncpy(all_roads[4].quality, test_result[0], 50);
        all_roads[4].lanes = 5;

        all_roads[5].length = 200;
        strncpy(all_roads[5].type, test_result[4], 50);
        strncpy(all_roads[5].quality, test_result[3], 50);
        all_roads[5].lanes = 5;
    }
    void TearDown() {
        free(all_roads);
        for (int i = 0; i < 6; i++) {
            delete []test_result[i];
        }
        delete []test_result;
    }
    Road *all_roads;
    char **test_result;
};

TEST_F(TestQual, qual1) {
    EXPECT_STREQ("Хорошее", qual(all_roads, 6, test_result[5], 3));
}

TEST_F(TestQual, qual2) {
    EXPECT_STREQ("Хорошее", qual(all_roads, 6, test_result[4], 5));
}

TEST_F(TestQual, qual3) {
    EXPECT_STREQ("Таких дорог нет!", qual(all_roads, 6, test_result[4], 6));
}

//
// test push_back
//
//
// class TestPushBack : public ::testing::Test {
// protected:
//    void SetUp() {
//        test_result = new char*[4];
//        for (int i = 0; i < 4; i++) {
//            test_result[i] = new char[100];
//        }
//
//        strncpy(test_result[0], "Асфальт\0", 100);
//        strncpy(test_result[1], "Отличное\0", 100);
//        strncpy(test_result[2], "Грунт\0", 100);
//        strncpy(test_result[3], "Ужасное\0", 100);
//
//        all_roads = reinterpret_cast<Road *>(malloc(sizeof(Road) * 10));
//
//        added_roads = push_back(all_roads, 0,
//                                       100,
//                                test_result[0],
//                                test_result[1],
//                                       3);
//
//        added_roads = push_back(all_roads, added_roads,
//                                200,
//                                test_result[2],
//                                test_result[3],
//                                5);
//    }
//    void TearDown() {
//        free(all_roads);
//        for (int i = 0; i < 4; i++) {
//            delete []test_result[i];
//        }
//        delete []test_result;
//    }
//    char **test_result;
//    Road * all_roads;
//    size_t added_roads;
// };
//
// TEST_F(TestPushBack, push_back1) {
//    EXPECT_EQ(100, all_roads[0].length);
//    EXPECT_STREQ("Асфальт\0", all_roads[0].type);
//    EXPECT_STREQ("Отличное\0", all_roads[0].quality);
//    EXPECT_EQ(3, all_roads[0].lanes);
// }
//
// TEST_F(TestPushBack, push_back2) {
//    EXPECT_EQ(200, all_roads[1].length);
//    EXPECT_STREQ("Грунт\0", all_roads[1].type);
//    EXPECT_STREQ("Ужасное\0", all_roads[1].quality);
//    EXPECT_EQ(5, all_roads[1].lanes);
// }
