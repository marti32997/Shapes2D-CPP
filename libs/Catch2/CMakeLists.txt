FetchContent_Declare(
	Catch2
	GIT_REPOSITORY      https://github.com/catchorg/Catch2.git
	GIT_PROGRESS        TRUE
	UPDATE_DISCONNECTED ON
)

FetchContent_MakeAvailable(Catch2)
LIST(APPEND)