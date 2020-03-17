FetchContent_Declare(
	Catch2
	GIT_REPOSITORY      https://github.com/catchorg/Catch2.git
	GIT_PROGRESS        TRUE
	UPDATE_DISCONNECTED ON
)

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.14.0")
	FetchContent_MakeAvailable(Catch2)
endif()

FetchContent_GetProperties(Catch2)
if(NOT catch2_POPULATED)
	FetchContent_Populate(Catch2)
	add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
endif()