# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\CardGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CardGame_autogen.dir\\ParseCache.txt"
  "CardGame_autogen"
  )
endif()
