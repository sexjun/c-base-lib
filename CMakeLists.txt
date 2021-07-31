cmake_minimum_required(VERSION 3.0.0)
project(cds_c_kit VERSION 0.1.0)

include(CTest)
enable_testing()

############################################################
# Create a library
############################################################

# 将文件家./test/*.c 下的文件赋值给 USER_TEST_FILE
aux_source_directory(${PROJECT_SOURCE_DIR}/src/ SRC_FILES)
file(GLOB SRC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/*.h)
file(GLOB SRC_A_DIR ${PROJECT_SOURCE_DIR}/src/*.c)

include_directories(./src/)

add_library(cds_c_kit SHARED 
    ${SRC_FILES}
)
# 给cds_c_kit这个库文件新起一个别名叫cds::c_library
add_library(cds::c_library ALIAS cds_c_kit)

target_include_directories(cds_c_kit
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/src
)


############################################################
# Create an executable
############################################################

set(arrylist_test_files
    ./test/test-arraylist.c
    ./test/alloc-testing.c
    ./test/framework.c
)

add_executable(test_arraylist ${arrylist_test_files})

target_include_directories(test_arraylist
PRIVATE 
${PROJECT_SOURCE_DIR}/test
)

# link the new hello_library target with the test_arraylist target
target_link_libraries( test_arraylist
    PRIVATE 
        cds::c_library
)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)