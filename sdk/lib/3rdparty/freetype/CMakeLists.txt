
add_definitions(
    -D__NTDRIVER__
    -DFT2_BUILD_LIBRARY)

include_directories(include)

if(MSVC)
    # error C4312: 'type cast': conversion from 'unsigned long' to 'void *' of greater size
    replace_compile_flags("/we4312" " ")
endif()

list(APPEND SOURCE
    src/autofit/autofit.c
    src/base/ftadvanc.c
    src/base/ftbbox.c
    src/base/ftbitmap.c
    src/base/ftcalc.c
    src/base/ftfntfmt.c
    src/base/ftgloadr.c
    src/base/ftglyph.c
    src/base/ftgxval.c
    src/base/fthash.c
    src/base/ftinit.c
    src/base/ftlcdfil.c
    src/base/ftmm.c
    src/base/ftobjs.c
    src/base/ftotval.c
    src/base/ftoutln.c
    src/base/ftpatent.c
    src/base/ftpfr.c
    src/base/ftpsprop.c
    src/base/ftrfork.c
    src/base/ftsnames.c
    src/base/ftstream.c
    src/base/ftstroke.c
    src/base/ftsynth.c
    src/base/ftsystem.c
    src/base/fttrigon.c
    src/base/fttype1.c
    src/base/ftutil.c
    src/base/ftwinfnt.c
    src/bdf/bdf.c
    src/cff/cff.c
    src/cid/type1cid.c
    src/gzip/ftgzip.c
    src/lzw/ftlzw.c
    src/pcf/pcf.c
    src/pfr/pfr.c
    src/psaux/psaux.c
    src/pshinter/pshinter.c
    src/psnames/psmodule.c
    src/raster/raster.c
    src/sfnt/sfnt.c
    src/smooth/smooth.c
    src/truetype/truetype.c
    src/type1/type1.c
    src/type42/type42.c
    src/winfonts/winfnt.c)

add_library(freetype ${SOURCE})

if(GCC)
    target_compile_options(freetype PRIVATE -fno-builtin-malloc)
elseif(USE_CLANG_CL)
    target_compile_options(freetype PRIVATE "-Wno-tautological-constant-compare")
endif()
