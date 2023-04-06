cmake_minimum_required (VERSION 3.8)
project(lgfxtest)

add_definitions(-DLGFX_LINUX_FB)

file(GLOB Target_Files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS
    *.cpp
    LovyanGFX/src/lgfx/Fonts/efont/*.c
    LovyanGFX/src/lgfx/Fonts/IPA/*.c
    LovyanGFX/src/lgfx/utility/*.c
    LovyanGFX/src/lgfx/v1/*.cpp
    LovyanGFX/src/lgfx/v1/misc/*.cpp
    LovyanGFX/src/lgfx/v1/panel/Panel_Device.cpp
    LovyanGFX/src/lgfx/v1/platforms/framebuffer/*.cpp
    )

add_executable (lgfxtest ${Target_Files})
target_include_directories(lgfxtest PUBLIC "LovyanGFX/src/")
target_compile_features(lgfxtest PUBLIC cxx_std_17)
target_link_libraries(lgfxtest -lpthread)

