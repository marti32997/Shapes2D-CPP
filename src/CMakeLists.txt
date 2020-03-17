add_library(Shape2D
	Shape2D.cpp
)

add_library(Point
	Point.cpp
)

add_library(Circle
	Circle.cpp
)

add_library(Square
	Square.cpp
)

add_library(Rectangle
	Rectangle.cpp
)

add_library(Cross
	Cross.cpp
)

target_link_libraries(Circle PUBLIC
	Shape2D
	Point
)

target_link_libraries(Square PUBLIC
	Shape2D
	Point
)

target_link_libraries(Rectangle PUBLIC
	Shape2D
	Point
)

target_link_libraries(Cross PUBLIC
	Shape2D
	Point
)

target_include_directories(Circle
	PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
	"${CMAKE_CURRENT_SOURCE_DIR}/tests"
)

target_include_directories(Square
	PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
	"${CMAKE_CURRENT_SOURCE_DIR}/tests"
)

target_include_directories(Rectangle
	PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
	"${CMAKE_CURRENT_SOURCE_DIR}/tests"
)

target_include_directories(Cross
	PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
	"${CMAKE_CURRENT_SOURCE_DIR}/tests"
)

add_executable(csci251_a2.exe
	main.cpp
	Assn2.cpp
	Point
	Shape2D
	Circle
	Square
	Rectangle
	Cross
)

if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|CLANG")
	setup_target_for_coverage_lcov(
		NAME csci251_a2_coverage
		EXECUTABLE csci251_a2.exe
		DEPENDENCIES csci251_a2.exe
	)
endif()