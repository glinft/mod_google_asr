
include $(top_srcdir)/build/modmake.rulesam

MODNAME = mod_sfwhisper
mod_LTLIBRARIES = mod_sfwhisper.la
mod_sfwhisper_la_SOURCES  = mod_sfwhisper.c utils.c curl.c whisper_api.cpp
mod_sfwhisper_la_CFLAGS   = $(AM_CFLAGS) -I. -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label -Wno-declaration-after-statement -Wno-pointer-sign
mod_sfwhisper_la_CXXFLAGS = $(AM_CXXFLAGS) -I.
mod_sfwhisper_la_LIBADD   = $(switch_builddir)/libfreeswitch.la
mod_sfwhisper_la_LDFLAGS  = -avoid-version -module -no-undefined -shared

$(am_mod_sfwhisper_la_OBJECTS): mod_sfwhisper.h whisper_api.h

