cmake_minimum_required( VERSION 3.0)

project( essentialcpp )

set( CPP_FILES
        essential.h
        chapter1.cpp
        chapter2.cpp
        chapter3.cpp
        Stack.h
        Stack.cpp
        chapter4.cpp
		Block.h
		Blockchain.h
)

add_executable(essentialcpp main.cpp ${CPP_FILES})
