cmake_minimum_required(VERSION 3.21)
include("cmake/common.cmake")
option(OBSE_SUPPORT_XBYAK "Enables trampoline support for Xbyak." OFF)

project(umbrella)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
	message(FATAL_ERROR "in-source builds are not allowed")
endif()

function(conditionally_add_subdirectory SRC_DIR)
	if(NOT TARGET "${SUBDIRECTORY}")
		if("${ARGC}" GREATER 1)
			add_subdirectory("${SRC_DIR}" "${ARGV1}")
		else()
			add_subdirectory("${SRC_DIR}")
		endif()
	endif()
endfunction()

include(CTest)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

conditionally_add_subdirectory(CommonLibOB64)
