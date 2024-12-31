cmake_minimum_required(VERSION 3.31)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project("test-dxlib-ruby-cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin/)
set(CMAKE_CXX_FLAGS -static)




set(RUBY_DIR E:/windows/dev-tools/Ruby33-x64/)
set(DXLIB_DIR C:/Users/tanukimaru/use-bin/dxlib-mingw/12_2_0_x86_64_release_win32_seh_ucrt_rt_v10_rev2/)
set(WINDOWS_FLAGS -mwindows)
set(CFLAGS -Wall)

add_subdirectory(src)

