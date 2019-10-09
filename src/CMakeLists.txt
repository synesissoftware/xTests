add_library(xTests xtests.core.cpp)
target_link_libraries(xTests STLSoft::STLSoft)
set_target_properties(xTests PROPERTIES
    OUTPUT_NAME "xtests.core"
    PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/xtests/xtests.h)
target_include_directories(xTests PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

install(TARGETS xTests
    EXPORT project-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/xtests
)

