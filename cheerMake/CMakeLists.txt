cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

project(cheerMake)

configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)
option(USE_MCHEER
      "Use provided math implementation" ON)


if(USE_MCHEER)
  include_directories("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory(math)
  set(EXTRA_LIBS ${EXTRA_LIBS} MCheer)
endif (USE_MCHEER)

aux_source_directory(. DIR_SRCS)

add_executable(cheer ${DIR_SRCS})
target_link_libraries(cheer ${EXTRA_LIBS})

# CMAKE_INSTALL_PREFIX --- installing root directory
install(TARGETS cheer DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)

# CTest!
enable_testing()

add_test(test_run cheer 1 3)
