cmake_minimum_required (VERSION 2.8)

# if(WIN32)
#     set (CMAKE_C_COMPILER C:/msys64/mingw64/bin/gcc.exe)
# endif(WIN32)

project (Metodos C)

set (Metodos_VERSION_MAJOR 0)
set (Metodos_VERSION_MINOR 1)
set (Metodos_VERSION_PATCH 0)

add_subdirectory(src)

# find_package(PkgConfig REQUIRED)
# pkg_check_modules(GTK REQUIRED gtk+-3.0)
#
# include_directories(${GTK_INCLUDE_DIRS})
# link_directories(${GTK_LIBRARY_DIRS})
#
# add_definitions(${GTK_CFLAGS_OTHER})
# message(status " GTK_CFLAGS_OTHER = ${GTK_CFLAGS_OTHER}")

# add_executable(gui gui.c)

# target_link_libraries(gui ${GTK_LIBRARIES})
#
# message(status "GTK_LIBRARIES = ${GTK_LIBRARIES}")
# message(status "GTK_INCLUDE = ${GTK_INCLUDE_DIRS}")
#
# message(status "pkgs_cflags = ${PKGS_CFLAGS}")
