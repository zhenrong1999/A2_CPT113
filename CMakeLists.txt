# CMake minimum requirement
cmake_minimum_required (VERSION 2.8)
# Project info
project (A2_CPT112)
# search the directory in the folder
# save the name to DIR_SRCS variable
aux_source_directory(. DIR_SRCS)

# sacan for source file of the directory
# save the name to DIR_LIB_SRCS variable

aux_source_directory(. DIR_LIB_SRCS)

# generate the linked lib
add_library (A2_CPT112_Lib ${DIR_LIB_SRCS})

# generate executable target
add_executable(main ${DIR_SRCS})
