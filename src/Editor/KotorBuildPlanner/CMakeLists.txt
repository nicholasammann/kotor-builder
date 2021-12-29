add_subdirectory(Equipment)
add_subdirectory(FinalStats)
add_subdirectory(InitialCharacter)
add_subdirectory(LevelUpDecisions)
add_subdirectory(Menus)

target_sources(editor
PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/KotorBuildPlanner.cpp

PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/KotorBuildPlanner.hpp
)