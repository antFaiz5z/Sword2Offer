cmake_minimum_required(VERSION 3.10)
project(JianzhiOffer)

set(CMAKE_CXX_STANDARD 11)

add_executable(JianzhiOffer
        JianzhiOffer/main.cpp
        JianzhiOffer/Utility.cpp JianzhiOffer/Utility.h
        JianzhiOffer/DataStructure.cpp JianzhiOffer/DataStructure.h
        JianzhiOffer/SearchAndSort.cpp JianzhiOffer/SearchAndSort.h
        JianzhiOffer/LoopAndRecursion.cpp JianzhiOffer/LoopAndRecursion.h
        JianzhiOffer/CodeThinking.cpp JianzhiOffer/CodeThinking.h
        JianzhiOffer/BitOperation.cpp JianzhiOffer/BitOperation.h)

add_executable(LeetCode
        LeetCode/main.cpp
        LeetCode/Algorithm/DoublePointer.cpp LeetCode/Algorithm/DoublePointer.h
        LeetCode/Algorithm/Greedy.cpp LeetCode/Algorithm/Greedy.h
        LeetCode/DataStructure/LinkedList.cpp LeetCode/DataStructure/LinkedList.h
        LeetCode/DataStructure/HashTable.cpp LeetCode/DataStructure/HashTable.h)

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
