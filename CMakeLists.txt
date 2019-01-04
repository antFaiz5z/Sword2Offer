cmake_minimum_required(VERSION 3.10)
project(JianzhiOffer)

set(CMAKE_CXX_STANDARD 11)

add_executable(JianzhiOffer
        JianzhiOffer/main.cpp
        JianzhiOffer/Utility.cpp JianzhiOffer/Utility.h
        JianzhiOffer/Data_Structure.cpp JianzhiOffer/Data_Structure.h
        JianzhiOffer/Search_and_Sort.cpp JianzhiOffer/Search_and_Sort.h
        JianzhiOffer/Loop_and_Recursion.cpp JianzhiOffer/Loop_and_Recursion.h
        JianzhiOffer/Code_Thinking.cpp JianzhiOffer/Code_Thinking.h
        JianzhiOffer/Bit_Operation.cpp JianzhiOffer/Bit_Operation.h)

add_executable(LeetCode
        LeetCode/main.cpp)

add_executable(DesignPattern
        DesignPattern/main.cpp
        DesignPattern/Singleton.cpp DesignPattern/Singleton.h
        DesignPattern/Observer.cpp DesignPattern/Observer.h
        DesignPattern/Adapter.cpp DesignPattern/Adapter.h
        DesignPattern/Builder.cpp DesignPattern/Builder.h
        DesignPattern/Prototype.cpp DesignPattern/Prototype.h
        DesignPattern/Decorator.cpp DesignPattern/Decorator.h
        DesignPattern/Command.cpp DesignPattern/Command.h
        DesignPattern/ResponsibilityChain.cpp DesignPattern/ResponsibilityChain.h
        DesignPattern/Memento.cpp DesignPattern/Memento.h)
