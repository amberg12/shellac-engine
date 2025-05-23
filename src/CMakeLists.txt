set(
  SRCS
  util/add.cpp
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
