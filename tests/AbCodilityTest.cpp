//
// Created by ljw on 14/06/21.
//
#include "gtest/gtest.h"
#include "../AbCodility.h"
//! Using the google test framework, check all elements of two containers
#define EXPECT_ITERABLE_BASE( PREDICATE, REFTYPE, TARTYPE, ref, target) \
    { \
    const REFTYPE& ref_(ref); \
    const TARTYPE& target_(target); \
    REFTYPE::const_iterator refIter = ref_.begin(); \
    TARTYPE::const_iterator tarIter = target_.begin(); \
    unsigned int i = 0; \
    while(refIter != ref_.end()) { \
        if ( tarIter == target_.end() ) { \
            ADD_FAILURE() << #target " has a smaller length than " #ref ; \
            break; \
        } \
        PREDICATE(* refIter, * tarIter) \
            << "Containers " #ref  " (refIter) and " #target " (tarIter)" \
               " differ at index " << i; \
        ++refIter; ++tarIter; ++i; \
    } \
    EXPECT_TRUE( tarIter == target_.end() ) \
        << #ref " has a smaller length than " #target ; \
    }

//! Check that all elements of two same-type containers are equal
#define EXPECT_ITERABLE_EQ( TYPE, ref, target) \
    EXPECT_ITERABLE_BASE( EXPECT_EQ, TYPE, TYPE, ref, target )

//! Check that all elements of two different-type containers are equal
#define EXPECT_ITERABLE_EQ2( REFTYPE, TARTYPE, ref, target) \
    EXPECT_ITERABLE_BASE( EXPECT_EQ, REFTYPE, TARTYPE, ref, target )

//! Check that all elements of two same-type containers of doubles are equal
#define EXPECT_ITERABLE_DOUBLE_EQ( TYPE, ref, target) \
    EXPECT_ITERABLE_BASE( EXPECT_DOUBLE_EQ, TYPE, TYPE, ref, target )

namespace {
    TEST(AbCodility, TestCase1) {
        std::vector<int> val {1, 1, 1};
        EXPECT_EQ(AbCodility::calcValue(val), 3);
    }

    TEST(AbCodility, TestCase2) {
        std::vector<int> val {0, 0, 0, 1, 0, 1};
        EXPECT_EQ(AbCodility::calcValue(val), -40);
    }

    TEST(AbCodility, TestCase3) {
        std::vector<int> val {1, 0, 1};
        auto ans = AbCodility::solution(val);
        EXPECT_ITERABLE_EQ( std::vector<int>, ans, std::vector<int>({1, 1, 1}) );
    }

    TEST(AbCodility, TestCase4) {
        std::vector<int> val {0, 0, 0, 0, 0, 1};
        auto ans = AbCodility::solution(val);
        EXPECT_ITERABLE_EQ( std::vector<int>, ans, std::vector<int>({0, 0, 0, 0, 1, 1}) );
    }

    TEST(AbCodility, TestCase5) {
        std::vector<int> val {1};
        auto ans = AbCodility::solution(val);
        EXPECT_ITERABLE_EQ( std::vector<int>, ans, std::vector<int>({1}) );
    }

    TEST(AbCodility, TestCase6) {
        std::vector<int> val {0, 1}; // -2 => -1
        auto ans = AbCodility::solution(val);
        EXPECT_ITERABLE_EQ( std::vector<int>, ans, std::vector<int>({1, 1}) );
    }

    TEST(AbCodility, TestCase7) {
        std::vector<int> val {1, 1, 1}; // 3 ans 2
        auto ans = AbCodility::solution(val);
        EXPECT_ITERABLE_EQ( std::vector<int>, ans, std::vector<int>({0, 1, 1}) );
    }
}
