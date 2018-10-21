find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

include_directories ("${PROJECT_SOURCE_DIR}/include")
include_directories("${GTK_INCLUDE_DIRS}")
link_directories(${GTK_LIBRARY_DIRS})

add_definitions(${GTK_CFLAGS_OTHER})
# add_library(raizes raizes.c)

file(GLOB PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
add_executable(mraizes main.c ${PROJECT_SOURCES})
target_link_libraries(mraizes m ${GTK_LIBRARIES})

# install(TARGETS raizes DESTINATION ${PROJECT_SOURCE_DIR}/bin)

install(TARGETS mraizes DESTINATION ${PROJECT_SOURCE_DIR}/bin)
