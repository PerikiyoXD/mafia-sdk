cmake_minimum_required(VERSION 2.6)

project(mafia-sdk)

file(GLOB_RECURSE MAFIA_SOURCES "src/*.cpp")

if(MSVC)
	add_definitions("-DUNICODE -D_UNICODE")
endif()

add_library(mafia-sdk STATIC
	"${MAFIA_SOURCES}"
)

target_include_directories(mafia-sdk
	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

install(TARGETS mafia-sdk RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/bin"
			LIBRARY DESTINATION "${CMAKE_SOURCE_DIR}/lib"
			ARCHIVE DESTINATION "${CMAKE_SOURCE_DIR}/lib")
