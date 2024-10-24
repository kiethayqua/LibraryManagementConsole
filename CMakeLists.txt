cmake_minimum_required(VERSION 3.29)
project(LibraryManagementConsole)

set(CMAKE_CXX_STANDARD 14)

include_directories(LibraryManagement)

add_executable(LibraryManagementConsole
    LibraryManagement/Common.h
    LibraryManagement/LibraryManagement.cpp
    LibraryManagement/MainMenu.cpp
    LibraryManagement/MainMenu.h
    LibraryManagement/ReaderCard.cpp
    LibraryManagement/ReaderCard.h
    LibraryManagement/ReaderMenu.cpp
    LibraryManagement/ReaderMenu.h
    LibraryManagement/VariadicTable.h
        LibraryManagement/Common.cpp)
