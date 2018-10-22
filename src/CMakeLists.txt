file(GLOB PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
include_directories ("${PROJECT_SOURCE_DIR}/include")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK gtk+-3.0)

if(GTK_FOUND)
	include_directories("${GTK_INCLUDE_DIRS}")
	link_directories(${GTK_LIBRARY_DIRS})
	add_definitions(${GTK_CFLAGS_OTHER})
endif(GTK_FOUND)

# add_library(raizes raizes.c)

add_executable(mraizes main.c ${PROJECT_SOURCES})
target_link_libraries(mraizes m)
# target_link_libraries(mraizes m ${GTK_LIBRARIES})

# install(TARGETS raizes DESTINATION ${PROJECT_SOURCE_DIR}/bin)

install(TARGETS mraizes DESTINATION ${PROJECT_SOURCE_DIR}/bin)
