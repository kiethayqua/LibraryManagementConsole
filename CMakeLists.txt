cmake_minimum_required(VERSION 3.29)
project(LibraryManagementConsole)

set(CMAKE_CXX_STANDARD 14)

include_directories(LibraryManagement)

add_executable(LibraryManagementConsole
    LibraryManagement/Common.h
    LibraryManagement/LibraryManagement.cpp
        LibraryManagement/Main.cpp
        LibraryManagement/Main.h
        LibraryManagement/Reader.cpp
        LibraryManagement/Reader.h
        LibraryManagement/VariadicTable.h
        LibraryManagement/Common.cpp
        LibraryManagement/Book.cpp
        LibraryManagement/Book.h
)
