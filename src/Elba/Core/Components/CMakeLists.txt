target_sources(elba
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Model.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Transform.cpp

PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Model.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Transform.hpp
)