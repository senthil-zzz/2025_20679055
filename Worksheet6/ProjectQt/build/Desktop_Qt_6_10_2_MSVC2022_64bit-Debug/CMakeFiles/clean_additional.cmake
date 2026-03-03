# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProjectQt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProjectQt_autogen.dir\\ParseCache.txt"
  "ProjectQt_autogen"
  )
endif()
