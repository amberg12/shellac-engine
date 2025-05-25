set(
  SRCS
  board/color.cpp
  board/piece.cpp
  board/square.cpp
)

set(
  TEST_SRCS
  board/test_color.cpp
  board/test_piece.cpp
  board/test_square.cpp
  util/test_matrix.cpp
)

set(BIN_NAME shellac-engine)

add_executable(${BIN_NAME})

target_sources(
  ${BIN_NAME}
  PRIVATE
  main.cpp
  ${SRCS}
)

target_include_directories(
  ${BIN_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

if(MSVC)
  target_compile_options(
    ${BIN_NAME}
    PRIVATE
    /W4 /WX
  )
else()
  target_compile_options(
    ${BIN_NAME}
    PRIVATE
    -Wall -Wextra -Wpedantic -Werror
  )
endif()

if(TESTING)
  enable_testing()
  
  Include(FetchContent)

  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0 # or a later release
  )

  FetchContent_MakeAvailable(Catch2)
  set(TEST_NAME tests)

  add_executable(${TEST_NAME})

  target_sources(
    ${TEST_NAME}
    PRIVATE
    test_main.cpp
    ${SRCS}
    ${TEST_SRCS}
  )

  target_include_directories(
    ${TEST_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
  )

  target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

  # use gcov for non msvc builds 
  if(NOT MSVC)
    target_compile_options(${TEST_NAME} PRIVATE --coverage)
    target_link_options(${TEST_NAME} PRIVATE --coverage)
  endif()

  add_test(NAME unit_tests COMMAND ${TEST_NAME})
endif()

