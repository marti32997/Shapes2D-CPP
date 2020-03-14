find_package(Catch2 REQUIRED)

add_executable(test_all
	catch_main.cpp
	test_Point.cpp
	test_Circle.cpp
	test_Square.cpp
	test_Rectangle.cpp
	test_Cross.cpp
)

target_link_libraries(test_all Catch2::Catch2 Circle Square Rectangle Cross)

include (CTest)
include (Catch)
catch_discover_tests(test_all)