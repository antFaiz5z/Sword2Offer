#aux_source_directory(. COMMONIMPL_SRC_DIR)

add_executable(CommonImplRoundRobin RoundRobin.cpp RoundRobin.h)
add_executable(CommonImplRvalueTest RvalueTest.cpp RvalueTest.h)
add_executable(CommonImplImpPoly ImpPolyByTmplate.cpp ImpPolyByTmplate.h)
add_executable(CommonImplSharedPtr SharedPtr.cpp SharedPtr.h)
add_executable(CommonImplQuickSortK QuickSortK.cpp QuickSortK.h)