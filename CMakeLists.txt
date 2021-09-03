cmake_minimum_required(VERSION 3.0.0)
project(OnlineVotingSystem VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(OnlineVotingSystem main.cpp Person.cpp Voter.cpp Candidate.cpp Assembly.cpp State.cpp Election.cpp ElectionCommision.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)