add_compile_definitions(DX_GCC_COMPILE DX_NON_INLINE_ASM)
add_executable(main main.cpp)
target_compile_options(main PRIVATE ${CFLAGS} ${WINDOWS_FLAGS})

target_include_directories(main PRIVATE  ${DXLIB_DIR} ${RUBY_DIR}/include/ruby-3.3.0/ ${RUBY_DIR}/include/ruby-3.3.0/x64-mingw-ucrt/)
target_link_directories(main PRIVATE ${DXLIB_DIR} ${RUBY_DIR}/lib/)
target_link_libraries(main PRIVATE DxLib DxUseCLib  DxDrawFunc  jpeg  png  zlib  tiff  theora_static  vorbis_static  vorbisfile_static  ogg_static  bulletdynamics  bulletcollision  bulletmath  opusfile  opus  silk_common  celt "${RUBY_DIR}/lib/libx64-ucrt-ruby330.dll.a")

