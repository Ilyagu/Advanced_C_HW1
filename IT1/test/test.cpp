// Copyright 2021 Nagdimaev Ilyagu

#include <cstdio>
#include <fstream>

#include "gtest/gtest.h"

extern "C" {
    #include "func/func.h"
    #include "../src/func.c"
}

class FindQuality : public ::testing::Test {
 protected:
    void SetUp() {
        test_result = new char*[5];
        for (int i = 0; i < 5; i++) {
            test_result[i] = new char[100];
        }

        strncpy(test_result[0], EXCELLENT, 100);
        strncpy(test_result[1], GOOD, 100);
        strncpy(test_result[2], BAD, 100);
        strncpy(test_result[3], TERRIBLE, 100);
        strncpy(test_result[4], NOROADS, 100);
    }
    void TearDown() {
        for (int i = 0; i < 5; i++) {
            delete []test_result[i];
        }
        delete []test_result;
    }
    char **test_result;
};

TEST_F(FindQuality, find_quality_for_null) {
    EXPECT_EQ(-300, find_quality(NULL));
}

TEST_F(FindQuality, find_quality_for_excellent) {
    EXPECT_EQ(0, find_quality(test_result[0]));
}

TEST_F(FindQuality, find_quality_for_good) {
    EXPECT_EQ(20, find_quality(test_result[1]));
}

TEST_F(FindQuality, find_quality_for_bad) {
    EXPECT_EQ(35, find_quality(test_result[2]));
}

TEST_F(FindQuality, find_quality_for_terrible) {
    EXPECT_EQ(50, find_quality(test_result[3]));
}

TEST_F(FindQuality, invalid_quallity) {
    EXPECT_EQ(-300, find_quality(test_result[4]));
}

//
// test decrypt
//

TEST(decrypt, decrypt_for_no_such_roads) {
    EXPECT_STREQ(NOROADS, decrypt(0));
}

TEST(decrypt, decrypt_for_terrible) {
    EXPECT_STREQ(TERRIBLE, decrypt(50));
}

TEST(decrypt, decrypt_for_bad) {
    EXPECT_STREQ(BAD, decrypt(60));
}

TEST(decrypt, decrypt_for_good) {
    EXPECT_STREQ(GOOD, decrypt(72));
}

TEST(decrypt, decrypt_for_excellent) {
    EXPECT_STREQ(EXCELLENT, decrypt(95));
}

TEST(decrypt, invalid_decrypt) {
    EXPECT_STREQ(ERROR, decrypt(200));
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

        strncpy(test_result[0], EXCELLENT, 100);
        strncpy(test_result[1], GOOD, 100);
        strncpy(test_result[2], BAD, 100);
        strncpy(test_result[3], TERRIBLE, 100);
        strncpy(test_result[4], ASPHALT, 100);
        strncpy(test_result[5], GROUND, 100);

        all_roads = reinterpret_cast<Road *>(malloc(sizeof(Road) * 6));

        all_roads[0].length = 200;
        strncpy(all_roads[0].type, GROUND, 50);
        strncpy(all_roads[0].quality, EXCELLENT, 50);
        all_roads[0].lanes = 3;

        all_roads[1].length = 200;
        strncpy(all_roads[1].type, GROUND, 50);
        strncpy(all_roads[1].quality, EXCELLENT, 50);
        all_roads[1].lanes = 3;

        all_roads[2].length = 200;
        strncpy(all_roads[2].type, GROUND, 50);
        strncpy(all_roads[2].quality, TERRIBLE, 50);
        all_roads[2].lanes = 3;

        all_roads[3].length = 200;
        strncpy(all_roads[3].type, GROUND, 50);
        strncpy(all_roads[3].quality, TERRIBLE, 50);
        all_roads[3].lanes = 3;

        all_roads[4].length = 200;
        strncpy(all_roads[4].type, ASPHALT, 50);
        strncpy(all_roads[4].quality, EXCELLENT, 50);
        all_roads[4].lanes = 5;

        all_roads[5].length = 200;
        strncpy(all_roads[5].type, ASPHALT, 50);
        strncpy(all_roads[5].quality, TERRIBLE, 50);
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

TEST_F(TestQual, qual_for_ground) {
    EXPECT_STREQ(GOOD, qual(all_roads, 6, GROUND, 3));
}

TEST_F(TestQual, qual_for_asphalt) {
    EXPECT_STREQ(GOOD, qual(all_roads, 6, ASPHALT, 5));
}

TEST_F(TestQual, ivalid_qual) {
    EXPECT_STREQ(NOROADS, qual(all_roads, 6, ASPHALT, 6));
}
