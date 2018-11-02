cmake_minimum_required(VERSION 3.10)
project(JianzhiOffer)

set(CMAKE_CXX_STANDARD 11)

add_executable( JianzhiOffer
        Algorithm/main.cpp
        Algorithm/Utility.cpp Algorithm/Utility.h
        Algorithm/Data_Structure.cpp Algorithm/Data_Structure.h
        Algorithm/Search_and_Sort.cpp Algorithm/Search_and_Sort.h
        Algorithm/Loop_and_Recursion.cpp Algorithm/Loop_and_Recursion.h
        Algorithm/Code_Thinking.cpp Algorithm/Code_Thinking.h
        Algorithm/Bit_Operation.cpp Algorithm/Bit_Operation.h)


add_executable( DesignModel
        DesignModel/main.cpp
        DesignModel/Singleton.cpp DesignModel/Singleton.h
        DesignModel/Observer.cpp DesignModel/Observer.h DesignModel/Adapter.cpp DesignModel/Adapter.h DesignModel/Builder.cpp DesignModel/Builder.h DesignModel/Prototype.cpp DesignModel/Prototype.h)