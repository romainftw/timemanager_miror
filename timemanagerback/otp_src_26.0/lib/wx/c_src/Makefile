#
# %CopyrightBegin%
#
# Copyright Ericsson AB 2008-2023. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# %CopyrightEnd%
#

include ../vsn.mk
include ../config.mk

# Darwin os have debug default install of wxWidgets 
FORCED_DEBUG = false
ifeq ($(FORCED_DEBUG),debug)
override TYPE=debug
endif

ifneq ($(TYPE),debug)
override TYPE=opt
endif

SO_EXT    = .so
OBJC_CC=gcc
OBJC_CFLAGS=

GENERAL     = wxe_nif wxe_ps_init wxe_main wxe_impl \
		wxe_helpers wxe_callback_impl wxe_return wxe_gl
GENERAL_H   = wxe_callback_impl.h  wxe_events.h  wxe_gl.h \
		wxe_helpers.h  wxe_impl.h  wxe_memory.h  wxe_return.h

GENERATED_F = wxe_wrapper_1 wxe_wrapper_2 wxe_wrapper_3 wxe_wrapper_4 \
	wxe_wrapper_5 wxe_wrapper_6 wxe_wrapper_7 wxe_wrapper_8 \
	wxe_events wxe_init wxe_func_table
GENERATED_H = gen/wxe_macros.h

GL_H = egl_impl.h gen/gl_finit.h gen/gl_fdefs.h

HAVE_OPENGL = true
OPENGL_F = gl_nif glu_nif egl_impl

include $(ERL_TOP)/make/target.mk
include $(ERL_TOP)/make/output.mk
include $(ERL_TOP)/make/$(TARGET)/otp_ded.mk

ERL_INCS= $(DED_INCLUDES)

SYS_TYPE    = x86_64-pc-linux-gnu

GENERAL_O   = $(GENERAL:%=$(SYS_TYPE)/%.o) 
GENERATED_O = $(GENERATED_F:%=$(SYS_TYPE)/%.o)
ifeq ($(HAVE_OPENGL), true)
	GL_OBJECTS = $(OPENGL_F:%=$(SYS_TYPE)/%.o)
else
	GL_OBJECTS = 
endif

TARGET_DIR = ../priv/$(SYS_TYPE)

RC_FILE_EXT = o
ifeq ($(SYS_TYPE),win32)
	RC_FILE     = $(SYS_TYPE)/wxe_win32.$(RC_FILE_EXT)
	WEBVIEW_LOADER_DLL_ORIG = 
else
	RC_FILE     =
	WEBVIEW_LOADER_DLL_ORIG =
endif

ifneq ($(WEBVIEW_LOADER_DLL_ORIG),)
	WEBVIEW_LOADER_DLL_DEST = ../priv/WebView2Loader.dll
endif

WX_OBJECTS  =  $(GENERATED_O) $(GENERAL_O) $(RC_FILE)

OBJECTS = $(WX_OBJECTS) $(GL_OBJECTS)

# -O2 -funroll-loops  -ffast-math -fomit-frame-pointer 

COMMON_CFLAGS = -DPACKAGE_NAME=\"\" -DPACKAGE_TARNAME=\"\" -DPACKAGE_VERSION=\"\" -DPACKAGE_STRING=\"\" -DPACKAGE_BUGREPORT=\"\" -DPACKAGE_URL=\"\" -DHAVE_STDIO_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_STRINGS_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_UNISTD_H=1 -DSTDC_HEADERS=1 -DSIZEOF_VOID_P=8 -DHAVE_GL_GL_H=1 -DHAVE_GL_GLU_H=1 -DHAVE_GL_SUPPORT=1 -DHAVE_GLINTPTR=1 -DHAVE_GLINTPTRARB=1 -DHAVE_GLCHAR=1 -DHAVE_GLCHARARB=1 -DHAVE_GLHALFARB=1 -DHAVE_GLINT64EXT=1 $(ERL_INCS) 

CC		= gcc
CXX		= g++
LD		= $(CXX)
LDFLAGS		= -shared -fPIC 
RESCOMP		= 

ifeq (false,true)
OPT_WX_LIBS      =  
DEBUG_WX_LIBS    =   
else
OPT_WX_LIBS      =  -L/usr/lib/x86_64-linux-gnu -pthread   -lwx_gtk3u_stc-3.0 -lwx_gtk3u_xrc-3.0 -lwx_gtk3u_html-3.0 -lwx_gtk3u_adv-3.0 -lwx_baseu_xml-3.0 -lwx_gtk3u_core-3.0 -lwx_baseu-3.0 -lwx_gtk3u_gl-3.0 -lwx_gtk3u_aui-3.0  
DEBUG_WX_LIBS    =  -L/usr/lib/x86_64-linux-gnu -pthread   -lwx_gtk3u_stc-3.0 -lwx_gtk3u_xrc-3.0 -lwx_gtk3u_html-3.0 -lwx_gtk3u_adv-3.0 -lwx_baseu_xml-3.0 -lwx_gtk3u_core-3.0 -lwx_baseu-3.0 -lwx_gtk3u_gl-3.0 -lwx_gtk3u_aui-3.0  
endif

ifeq ($(TYPE),debug)
WX_CFLAGS	= -I/usr/lib/x86_64-linux-gnu/wx/include/gtk3-unicode-3.0 -I/usr/include/wx-3.0 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread
CFLAGS          = -g -Wall -fPIC -g -O2 -Wno-deprecated-declarations -DDEBUG  -D_GNU_SOURCE -D_THREAD_SAFE -D_REENTRANT  
WX_CXX_FLAGS	= -I/usr/lib/x86_64-linux-gnu/wx/include/gtk3-unicode-3.0 -I/usr/include/wx-3.0 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread
CXX_FLAGS       =  -g -Wall -fPIC -g -O2 -Wno-deprecated-declarations -DDEBUG  -D_GNU_SOURCE -D_THREAD_SAFE -D_REENTRANT  
CXX_NO_OPT_FLAGS =  -g -Wall -fPIC -g -O2 -Wno-deprecated-declarations -DDEBUG  -D_GNU_SOURCE -D_THREAD_SAFE -D_REENTRANT  
WX_LIBS		= $(DEBUG_WX_LIBS)
else
WX_CFLAGS	= -I/usr/lib/x86_64-linux-gnu/wx/include/gtk3-unicode-3.0 -I/usr/include/wx-3.0 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread
CFLAGS          = -Werror=return-type -Wall -fPIC -g -O2 -Wno-deprecated-declarations -fomit-frame-pointer -fno-strict-aliasing  -D_GNU_SOURCE -D_THREAD_SAFE -D_REENTRANT  
WX_CXX_FLAGS	= -I/usr/lib/x86_64-linux-gnu/wx/include/gtk3-unicode-3.0 -I/usr/include/wx-3.0 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread
CXX_FLAGS       = -Werror=return-type  -Wall -fPIC -g -O2 -Wno-deprecated-declarations -fomit-frame-pointer -fno-strict-aliasing  -D_GNU_SOURCE -D_THREAD_SAFE -D_REENTRANT  
CXX_NO_OPT_FLAGS =  -Wall -fPIC -g -O2 -Wno-deprecated-declarations -fomit-frame-pointer -fno-strict-aliasing  -D_GNU_SOURCE -D_THREAD_SAFE -D_REENTRANT  -fno-var-tracking-assignments -fno-move-loop-invariants -O1 
WX_LIBS		= $(OPT_WX_LIBS)
endif

GL_LIBS         = -lGL -lGLU

CC_O		= $(V_CC) -c $(CFLAGS) $(WX_CFLAGS) $(COMMON_CFLAGS)
OBJC_CC_O	= $(OBJC_CC) -c $(CFLAGS) $(OBJC_CFLAGS) $(WX_CFLAGS) $(COMMON_CFLAGS)
CXX_O		= $(V_CXX) -c $(CXX_FLAGS) $(WX_CXX_FLAGS)  $(COMMON_CFLAGS)
CXX_O_NO_OPT    = $(V_CXX) -c $(CXX_NO_OPT_FLAGS) $(WX_CXX_FLAGS)  $(COMMON_CFLAGS)

# Targets

opt:     $(TARGET_DIR)/wxe_driver$(SO_EXT) $(TARGET_DIR)/erl_gl$(SO_EXT) $(WEBVIEW_LOADER_DLL_DEST)

$(filter-out opt, $(TYPES)):
	@${MAKE} TYPE=$@ opt

clean:  
	rm -f $(OBJECTS) 
	rm -f $(TARGET_DIR)/*$(SO_EXT)
	rm -f *~ erl_crash.dump

complete_clean: 
	rm -f $(OBJECTS) 
	rm -f $(GENERATED_F:%=gen/%.cpp)
	rm -f gen/gl_funcs.cpp 
	rm -f $(GENERATED_H)
	rm -f ../priv/*/*
	rm -f *~ erl_crash.dump
	rm -f Makefile

docs:	

$(GL_OBJECTS): $(GL_H)
$(WX_OBJECTS): $(GENERATED_H) $(GENERAL_H) 

$(SYS_TYPE)/%.o: %.cpp 
	$(V_at)mkdir -p $(SYS_TYPE)
	$(CXX_O) $< -o $@

$(SYS_TYPE)/%.o: %.c 
	$(V_at)mkdir -p $(SYS_TYPE)
	$(CC_O) $< -o $@

$(SYS_TYPE)/wxe_ps_init.o: wxe_ps_init.c 
	$(V_at)mkdir -p $(SYS_TYPE)
	$(cc_verbose)$(OBJC_CC_O) $< -o $@

$(SYS_TYPE)/%.o: gen/%.cpp
	$(V_at)mkdir -p $(SYS_TYPE)
	$(CXX_O_NO_OPT) $< -o $@

$(SYS_TYPE)/%.o: gen/%.c 
	$(V_at)mkdir -p $(SYS_TYPE)
	$(CC_O) $< -o $@

$(SYS_TYPE)/wxe_win32.$(RC_FILE_EXT): wxe_win32.rc
	$(V_at)mkdir -p $(SYS_TYPE)
	$(RESCOMP) -o $@ $< 

$(TARGET_DIR)/wxe_driver$(SO_EXT): $(WX_OBJECTS)
	$(V_at)mkdir -p $(TARGET_DIR)
	$(V_LD) $(LDFLAGS) $(WX_OBJECTS) $(WX_LIBS) -o $@

$(TARGET_DIR)/erl_gl$(SO_EXT): $(GL_OBJECTS)
	$(V_at)mkdir -p $(TARGET_DIR)
	$(V_CC) $(LDFLAGS) $(GL_OBJECTS) $(GL_LIBS) -o $@

$(WEBVIEW_LOADER_DLL_DEST): $(WEBVIEW_LOADER_DLL_ORIG)
	$(INSTALL_PROGRAM) $< $@

# ----------------------------------------------------
# Release Target
# ----------------------------------------------------
include $(ERL_TOP)/make/otp_release_targets.mk
release_spec: opt
	$(INSTALL_DIR) "$(RELSYSDIR)/priv"
	$(INSTALL_DATA) ../priv/erlang-logo32.png "$(RELSYSDIR)/priv/"
	$(INSTALL_DATA) ../priv/erlang-logo64.png "$(RELSYSDIR)/priv/"
	$(INSTALL_DATA) ../priv/erlang-logo128.png "$(RELSYSDIR)/priv/"
	$(INSTALL_PROGRAM) $(TARGET_DIR)/wxe_driver$(SO_EXT) "$(RELSYSDIR)/priv/"
	$(INSTALL_PROGRAM) $(TARGET_DIR)/erl_gl$(SO_EXT) "$(RELSYSDIR)/priv/"
ifneq ($(WEBVIEW_LOADER_DLL_ORIG),)
	$(INSTALL_PROGRAM) $(WEBVIEW_LOADER_DLL_DEST) "$(RELSYSDIR)/priv/"
endif
ifeq ($(SYS_TYPE),win32)
	$(INSTALL_PROGRAM) $(TARGET_DIR)/wxe_driver.pdb "$(RELSYSDIR)/priv/"
	$(INSTALL_PROGRAM) $(TARGET_DIR)/erl_gl.pdb "$(RELSYSDIR)/priv/"
endif

release_docs_spec:
