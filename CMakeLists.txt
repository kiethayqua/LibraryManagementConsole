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
        LibraryManagement/BookLoanSlip.cpp
        LibraryManagement/BookLoanSlip.h
        LibraryManagement/Globals.h
        LibraryManagement/BookReturnSlip.cpp
        LibraryManagement/BookReturnSlip.h
        LibraryManagement/DateUtil.cpp
        LibraryManagement/DateUtil.h
        LibraryManagement/Statistics.cpp
        LibraryManagement/Statistics.h
)
