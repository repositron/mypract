cmake_minimum_required(VERSION 3.17)
project(mypract)


set(CMAKE_CXX_STANDARD 20)


add_subdirectory("tests")

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

add_library(mypract main.cpp  ChangeMaker.cpp ChangeMaker.h ParserUtil.cpp ParserUtil.h Subset.cpp Subset.h Q1.cpp Q1.h SubsetSum.cpp SubsetSum.h RodCutting.h QX.h QX.cpp minSwaps.cpp minSwaps.h MinBribes.cpp MinBribes.h ArrayManipulation.cpp ArrayManipulation.h RansomNote.cpp RansomNote.h Rotate.cpp Rotate.h MaxSumArray.cpp MaxSumArray.h MinAbs.h MinAbs.cpp PairSum.cpp PairSum.h CountRectangles.cpp CountRectangles.h WaterArea.cpp WaterArea.h KnapsackProblem.cpp KnapsackProblem.h Staircase.cpp Staircase.h MaxProfit.h MaxProfit.cpp CoinChangeProplem.cpp CoinChangeProplem.h LinkList2Sum.cpp LinkList2Sum.h Graph.cpp Graph.h)

#add_library(tests tests/testsample.cpp)

#target_link_libraries(tests mypract)
