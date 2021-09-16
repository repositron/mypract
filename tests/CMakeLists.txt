# 'Google_test' is the subproject name
project(tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(tests testsample.cpp ../ChangeMaker.cpp ../ChangeMaker.h ../Subset.cpp ../Subset.h ../Q1.cpp ../Q1.h ../SubsetSum.cpp ../SubsetSum.h ../RodCutting.h ../QX.h ../QX.cpp ../minSwaps.cpp ../minSwaps.h ../MinBribes.cpp ../MinBribes.h TestUtil.cpp TestUtil.h ../ArrayManipulation.cpp ../ArrayManipulation.h ArrayManipulationTest.cpp ../RansomNote.cpp ../RansomNote.h ../Rotate.cpp ../Rotate.h ../MaxSumArray.cpp ../MaxSumArray.h ../MinAbs.cpp ../MinAbs.h ../PairSum.cpp ../PairSum.h ../CountRectangles.cpp ../CountRectangles.h CountRectanglesTest.cpp ../WaterArea.cpp ../WaterArea.h WaterAreaTest.cpp ../KnapsackProblem.cpp ../KnapsackProblem.h KnapsackProblemTest.cpp ../Staircase.cpp ../Staircase.h ../MaxProfit.cpp ../CoinChangeProplem.cpp CoinChangeProblemTest.cpp ../LinkList2Sum.cpp ../LinkList2Sum.h ../Graph.h ../Graph.cpp LinkList2SumTest.cpp graphtest.cpp maxarratsumtest.cpp ../MaxSumNoAdjacentArray.cpp ../MaxSumNoAdjacentArray.h ../NumStrings.cpp ../NumStrings.h NumStringsTest.cpp ../AbbreviationProblem.cpp ../AbbreviationProblem.h AbbreviationProblemTest.cpp ../PrimeXor.cpp ../PrimeXor.h ../SubStringSum.cpp ../SubStringSum.h SubStringSumTest.cpp ../codility.cpp ../codility.h codilityTest.cpp ../Candies.cpp ../Candies.h ../ExaWizards.cpp ../ExaWizards.h ExaWizardsTest.cpp ../CousinsBinaryTree.cpp ../CousinsBinaryTree.h CousinsBinaryTreeTest.cpp ../AbCodility.cpp ../AbCodility.h AbCodilityTest.cpp ../removeduplicates.cpp RemoveDuplicatesTest.cpp ../SortBalanceParentheses.cpp ../SortBalanceParentheses.h SortBalanceParenthesesTest.cpp ../FindIfPathExistsGraph.cpp ../FindIfPathExistsGraph.h FindIfPathExistsGraphTest.cpp)
target_link_libraries(tests gtest gtest_main)

