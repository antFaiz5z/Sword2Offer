cmake_minimum_required(VERSION 3.10)
project(JianzhiOffer)

set(CMAKE_CXX_STANDARD 11)

add_executable( JianzhiOffer
        main.cpp
        Utility.cpp Utility.h
        Data_Structure.cpp Data_Structure.h
        Search_and_Sort.cpp Search_and_Sort.h
        Loop_and_Recursion.cpp Loop_and_Recursion.h
        Code_Thinking.cpp Code_Thinking.h
        Bit_Operation.cpp Bit_Operation.h)