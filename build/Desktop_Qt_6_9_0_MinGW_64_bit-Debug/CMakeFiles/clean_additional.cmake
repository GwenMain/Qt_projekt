# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DatabaseGamesApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DatabaseGamesApp_autogen.dir\\ParseCache.txt"
  "DatabaseGamesApp_autogen"
  )
endif()
