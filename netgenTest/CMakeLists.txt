set(TEST_SRC
    MyRefineTest.cpp
)

if(MSVC)
    link_directories(${CMAKE_INSTALL_PREFIX}/lib)
else()
endif()

include_directories(
    ${CMAKE_INSTALL_PREFIX}/include
)

add_executable(netgenTest ${TEST_SRC})

if(MSVC)
else()
endif()

list(APPEND NGLIB nglib)
target_link_libraries(netgenTest  ${NGLIB} )