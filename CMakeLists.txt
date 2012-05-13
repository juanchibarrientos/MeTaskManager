cmake_minimum_required (VERSION 2.6)
project (METASK)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-2.4)

add_subdirectory (src) 
#add_subdirectory (bin)
