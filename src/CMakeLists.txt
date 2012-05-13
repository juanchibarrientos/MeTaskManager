link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

add_executable (metask main.cpp gui.cpp date.cpp pi.cpp plain.cpp task.cpp time.cpp)

target_link_libraries(metask 
    ${GTKMM_LIBRARIES}  )

INSTALL(TARGETS metask DESTINATION ${METASK_SOURCE_DIR}/bin)
