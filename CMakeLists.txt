cmake_minimum_required(VERSION 3.10)
project(JianzhiOffer)

set(CMAKE_CXX_STANDARD 11)

add_executable(JianzhiOffer
        Algorithm/main.cpp
        Algorithm/Utility.cpp Algorithm/Utility.h
        Algorithm/Data_Structure.cpp Algorithm/Data_Structure.h
        Algorithm/Search_and_Sort.cpp Algorithm/Search_and_Sort.h
        Algorithm/Loop_and_Recursion.cpp Algorithm/Loop_and_Recursion.h
        Algorithm/Code_Thinking.cpp Algorithm/Code_Thinking.h
        Algorithm/Bit_Operation.cpp Algorithm/Bit_Operation.h)


add_executable(DesignPattern
        DesignPattern/main.cpp
        DesignPattern/Singleton.cpp DesignPattern/Singleton.h
        DesignPattern/Observer.cpp DesignPattern/Observer.h
        DesignPattern/Adapter.cpp DesignPattern/Adapter.h
        DesignPattern/Builder.cpp DesignPattern/Builder.h
        DesignPattern/Prototype.cpp DesignPattern/Prototype.h
        DesignPattern/Decorator.cpp DesignPattern/Decorator.h DesignPattern/Command.cpp DesignPattern/Command.h DesignPattern/ResponsibilityChain.cpp DesignPattern/ResponsibilityChain.h DesignPattern/Memento.cpp DesignPattern/Memento.h)