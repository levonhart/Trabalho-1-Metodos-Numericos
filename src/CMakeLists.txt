file(GLOB PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/raizes.c")
include_directories ("${PROJECT_SOURCE_DIR}/include")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK gtk+-3.0)

if(GTK_FOUND)
	include_directories("${GTK_INCLUDE_DIRS}")
	link_directories(${GTK_LIBRARY_DIRS})
	add_definitions(${GTK_CFLAGS_OTHER})
	if(WIN32)
		add_definitions(-mwindows)
	endif(WIN32)
	add_executable(mraizes-gui mainInterface.c sinais.c ${PROJECT_SOURCES})
	target_link_libraries(mraizes-gui m -export-dynamic ${GTK_LIBRARIES})
endif(GTK_FOUND)

# add_library(raizes raizes.c)

add_executable(mraizes main.c ${PROJECT_SOURCES})
target_link_libraries(mraizes m)
# target_link_libraries(mraizes m ${GTK_LIBRARIES})

# install(TARGETS raizes DESTINATION ${PROJECT_SOURCE_DIR}/bin)

install(TARGETS mraizes mraizes-gui DESTINATION ${PROJECT_SOURCE_DIR}/bin)
