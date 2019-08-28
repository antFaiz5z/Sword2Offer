aux_source_directory(. COMMONIMPL_SRC_DIR)

add_executable(CommonImpl ${COMMONIMPL_SRC_DIR} Rvalue.cpp Rvalue.h)
add_executable(CommonImplRvalue Rvalue.cpp Rvalue.h)