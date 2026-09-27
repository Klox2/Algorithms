add_executable(Lab1CPPClass lab1.cpp)
target_include_directories(Lab1CPPClass PUBLIC ../LibraryCPPClass)
target_link_libraries(Lab1CPPClass LibraryCPPClass)

add_test(NAME TestLab1CPPClass COMMAND Lab1CPPClass ${CMAKE_CURRENT_SOURCE_DIR}/input.txt)
set_property(TEST TestLab1CPPClass PROPERTY PASS_REGULAR_EXPRESSION "0 0 1 2 3")

add_test(NAME TestLab1CPPClass_Task1Extra COMMAND Lab1CPPClass ${CMAKE_CURRENT_SOURCE_DIR}/input_task1_extra.txt)
set_property(TEST TestLab1CPPClass_Task1Extra PROPERTY PASS_REGULAR_EXPRESSION "0 2")

add_test(NAME TestLab1CPPClass_Task2Left COMMAND Lab1CPPClass ${CMAKE_CURRENT_SOURCE_DIR}/input_task2_left.txt)
set_property(TEST TestLab1CPPClass_Task2Left PROPERTY PASS_REGULAR_EXPRESSION "3 4 5 0 0")

add_test(NAME TestLab1CPPClass_Task2Edge COMMAND Lab1CPPClass ${CMAKE_CURRENT_SOURCE_DIR}/input_task2_edge.txt)
set_property(TEST TestLab1CPPClass_Task2Edge PROPERTY PASS_REGULAR_EXPRESSION "0 0 0")