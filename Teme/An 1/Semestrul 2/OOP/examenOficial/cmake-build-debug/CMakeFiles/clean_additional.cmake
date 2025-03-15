# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/examenOficial_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/examenOficial_autogen.dir/ParseCache.txt"
  "examenOficial_autogen"
  )
endif()
