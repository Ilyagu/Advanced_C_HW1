// Copyright 2021 Nagdimaev Ilyagu

#include <cstdio>
#include <fstream>

#include "gtest/gtest.h"

extern "C" {
    #include "func/func.h"
    #include "../src/func.c"
}

#define MAX_ROADS 50
#define ROADS 11
#define QUAL_ERROR -300
#define MAX_RATING 100
#define LOAD_ERROR -1
#define EXCELLENT "Отличное"
#define GOOD "Хорошее"
#define BAD "Плохое"
#define TERRIBLE "Ужасное"
#define NOROADS "Таких дорог нет!"
#define ERROR "ERROR"
#define ASPHALT "Асфальт"
#define GROUND "Грунт"

//
// test find_quality
//


TEST(FindQuality, find_quality_for_null) {
    EXPECT_EQ(-300, find_quality(NULL));
}

TEST(FindQuality, find_quality_for_excellent) {
    EXPECT_EQ(0, find_quality(EXCELLENT));
}

TEST(FindQuality, find_quality_for_good) {
    EXPECT_EQ(20, find_quality(GOOD));
}

TEST(FindQuality, find_quality_for_bad) {
    EXPECT_EQ(35, find_quality(BAD));
}

TEST(FindQuality, find_quality_for_terrible) {
    EXPECT_EQ(50, find_quality(TERRIBLE));
}

TEST(FindQuality, invalid_quallity) {
    EXPECT_EQ(-300, find_quality(NOROADS));
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

TEST(decrypt, invalid_decrypt2) {
    EXPECT_STREQ(ERROR, decrypt(-54));
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
        all_roads = reinterpret_cast<Road *>(malloc(sizeof(Road) * ROADS));

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

        all_roads[6].length = 200;
        strncpy(all_roads[6].type, ASPHALT, 50);
        strncpy(all_roads[6].quality, EXCELLENT, 50);
        all_roads[6].lanes = 5;

        all_roads[7].length = 200;
        strncpy(all_roads[7].type, GROUND, 50);
        strncpy(all_roads[7].quality, EXCELLENT, 50);
        all_roads[7].lanes = 1;

        all_roads[8].length = 200;
        strncpy(all_roads[8].type, GROUND, 50);
        strncpy(all_roads[8].quality, EXCELLENT, 50);
        all_roads[8].lanes = 1;

        all_roads[9].length = 200;
        strncpy(all_roads[9].type, GROUND, 50);
        strncpy(all_roads[9].quality, GOOD, 50);
        all_roads[9].lanes = 1;

        all_roads[10].length = 200;
        strncpy(all_roads[10].type, GROUND, 50);
        strncpy(all_roads[10].quality, GOOD, 50);
        all_roads[10].lanes = 5;
    }
    void TearDown() {
        free(all_roads);
    }
    Road *all_roads;
};

TEST_F(TestQual, qual_for_ground_excellent) {
    EXPECT_STREQ(EXCELLENT, qual(all_roads, ROADS, GROUND, 1));
}

TEST_F(TestQual, qual_for_ground_good) {
    EXPECT_STREQ(GOOD, qual(all_roads, ROADS, GROUND, 3));
}

TEST_F(TestQual, qual_for_one_ground_good) {
    EXPECT_STREQ(GOOD, qual(all_roads, ROADS, GROUND, 5));
}

TEST_F(TestQual, qual_for_asphalt) {
    EXPECT_STREQ(GOOD, qual(all_roads, ROADS, ASPHALT, 5));
}

TEST_F(TestQual, noraods_qual) {
    EXPECT_STREQ(NOROADS, qual(all_roads, ROADS, ASPHALT, 6));
}

TEST_F(TestQual, ivalid_qual_null_on_allroads) {
    EXPECT_STREQ(ERROR, qual(NULL, ROADS, ASPHALT, 6));
}

TEST_F(TestQual, ivalid_qual_null_on_type) {
    EXPECT_STREQ(ERROR, qual(all_roads, ROADS, NULL, 6));
}

//
// test load_data
//

class TestLoad : public ::testing::Test {
 protected:
    void SetUp() {
        all_roads = reinterpret_cast<Road *>(malloc(sizeof(Road) * MAX_ROADS));

        load_data(all_roads);
    }
    void TearDown() {
        free(all_roads);
    }
    Road *all_roads;
};

TEST_F(TestLoad, invalid_load) {
    ASSERT_EQ(LOAD_ERROR, load_data(NULL));
}

TEST_F(TestLoad, load_1_object) {
    EXPECT_EQ(300, all_roads[0].length);
    EXPECT_STREQ(ASPHALT, all_roads[0].type);
    EXPECT_STREQ(GOOD, all_roads[0].quality);
    EXPECT_EQ(4, all_roads[0].lanes);
}

TEST_F(TestLoad, load_2_object) {
    EXPECT_EQ(2000, all_roads[1].length);
    EXPECT_STREQ(GROUND, all_roads[1].type);
    EXPECT_STREQ(EXCELLENT, all_roads[1].quality);
    EXPECT_EQ(1, all_roads[1].lanes);
}

TEST_F(TestLoad, load_3_object) {
    EXPECT_EQ(400, all_roads[2].length);
    EXPECT_STREQ(ASPHALT, all_roads[2].type);
    EXPECT_STREQ(TERRIBLE, all_roads[2].quality);
    EXPECT_EQ(5, all_roads[2].lanes);
}

TEST_F(TestLoad, load_last_object) {
    EXPECT_EQ(30, all_roads[9].length);
    EXPECT_STREQ(GROUND, all_roads[9].type);
    EXPECT_STREQ(TERRIBLE, all_roads[9].quality);
    EXPECT_EQ(1, all_roads[9].lanes);
}

//
// test push_back
//

TEST(TestPushBack, invalid_pushback) {
    ASSERT_EQ(PUSH_ERROR, push_back(NULL, 0, 200, ASPHALT, GOOD, 4));
}
