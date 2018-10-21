include_directories ("${PROJECT_SOURCE_DIR}/include")
# add_library(raizes raizes.c)

file(GLOB PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
add_executable(mraizes main.c ${PROJECT_SOURCES})
target_link_libraries(mraizes m)

# install(TARGETS raizes DESTINATION ${PROJECT_SOURCE_DIR}/bin)

install(TARGETS mraizes DESTINATION ${PROJECT_SOURCE_DIR}/bin)
