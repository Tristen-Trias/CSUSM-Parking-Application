# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CSUSM_Parking_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CSUSM_Parking_autogen.dir\\ParseCache.txt"
  "CSUSM_Parking_autogen"
  )
endif()
