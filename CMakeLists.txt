cmake_minimum_required(VERSION 3.10)
project(334209)
set (EXE_NAME Search)

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set ()
#   set (input02 "train_target.csv")
# etc....

set (input01 "")
set (input02 "")
#set (input03 "")
#set (input04 "")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS) #input02 input03 input04#
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 14)
add_executable(${EXE_NAME} TwoPointFive.cpp)
