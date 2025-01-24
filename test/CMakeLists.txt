message(STATUS "Fetching Google Test.")
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main 
  SOURCE_DIR     ${FETCHCONTENT_BASE_DIR}/googletest
  BINARY_DIR     ${FETCHCONTENT_BASE_DIR}/googletest-build
)

FetchContent_MakeAvailable(googletest)

FetchContent_GetProperties(googletest)
if (googletest_POPULATED)
    message(STATUS "Google Test is populated successfully.")
else()
    message(FATAL_ERROR "Google Test population failed.")
    FetchContent_Populate(googletest)
endif()

message(STATUS "Google Test source dir: ${googletest_SOURCE_DIR}")
message(STATUS "Google Test binary dir: ${googletest_BINARY_DIR}")

set(SOURCE_FILES
    test_iterator.cc
)

add_executable(stl-tests ${SOURCE_FILES})

target_link_libraries(stl-tests PRIVATE gtest gtest_main)

target_include_directories(stl-tests PRIVATE
    ${googletest_SOURCE_DIR}/googletest/include
    ${googletest_SOURCE_DIR}/googlemock/include
)

add_test(NAME IteratorTest COMMAND stl-tests TestIterator)