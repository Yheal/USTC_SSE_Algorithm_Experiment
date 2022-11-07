CMAKE_MINIMUM_REQUIRED( VERSION 3.0)
# generate lib
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIRH}/lib)
#########增加此行，2019.10.17
aux_source_directory (. DIR_SRC)
add_library(mylib ${DIR_SRC})
