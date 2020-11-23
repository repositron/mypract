# 'Google_test' is the subproject name
project(tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(tests testsample.cpp ../ChangeMaker.cpp ../ChangeMaker.h ../Subset.cpp ../Subset.h ../Q1.cpp ../Q1.h ../SubsetSum.cpp ../SubsetSum.h ../RodCutting.h ../QX.h ../QX.cpp ../minSwaps.cpp ../minSwaps.h ../MinBribes.cpp ../MinBribes.h TestUtil.cpp TestUtil.h ../ArrayManipulation.cpp ../ArrayManipulation.h ArrayManipulationTest.cpp ../RansomNote.cpp ../RansomNote.h ../Rotate.cpp ../Rotate.h ../MaxSumArray.cpp ../MaxSumArray.h ../MinAbs.cpp ../MinAbs.h ../PairSum.cpp ../PairSum.h ../CountRectangles.cpp ../CountRectangles.h CountRectanglesTest.cpp)
target_link_libraries(tests gtest gtest_main)

