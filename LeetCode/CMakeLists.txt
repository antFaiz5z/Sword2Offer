aux_source_directory(./Algorithm  LEETCODE_ALGORITHM_SRC_DIR)
aux_source_directory(./DataStructure  LEETCODE_DATASTRUCTURE_SRC_DIR)

add_executable(LeetCode main.cpp ${LEETCODE_ALGORITHM_SRC_DIR} ${LEETCODE_DATASTRUCTURE_SRC_DIR} Algorithm/Bit.cpp Algorithm/Bit.h)