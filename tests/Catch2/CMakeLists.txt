add_executable(catch_test
	catch_main.cpp
	test_Point.cpp
	test_Circle.cpp
	test_Square.cpp
	test_Rectangle.cpp
	test_Cross.cpp
)

target_link_libraries(catch_test Catch2::Catch2 Circle Square Rectangle Cross)

if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|CLANG")
	setup_target_for_coverage_lcov(
		NAME catch_test_coverage
		EXECUTABLE catch_test
		DEPENDENCIES catch_test
	)
endif()

include (${CMAKE_BINARY_DIR}/_deps/catch2-src/contrib/Catch.cmake)
catch_discover_tests(catch_test)
