# =========================================================================
#     This makefile was written by
#     LuYang, 2007-07-12. (luyang@datuu.com)
#     Copyright! Datuu Mobile
# =========================================================================




prefix = /usr/local
exec_prefix = ${prefix}
INSTALL = /usr/bin/install -c
CXX = g++
CXXFLAGS = -g  -D_FILE_OFFSET_BITS=64 -D=_LARGEFILE_SOURCE
LD_CXX = $(CXX)   -o
SHARED_LD_CXX = $(CXX) -shared -fPIC -o
AR = ar rcs
LIBPREFIX = lib
SO_SUFFIX = so
DLLIMP_SUFFIX = so
PIC_FLAG = -fPIC -DPIC
STRIP = strip
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_DIR = /usr/bin/install -c -d
srcdir = .
top_builddir = ./
libdir = ${exec_prefix}/lib
DLLPREFIX = lib

INCLUDES =  -I. -I.. -I/home/sixlu/tools/v8/include/ -I/usr/include/libxml2/
LDFLAGS =  -L/usr/local/lib  

### Variables: ###

SERVER_NAME = IChrome 
DESTDIR = 
#STREAMSERVER_CXXFLAGS = $(CXXFLAGS) $(CPPFLAGS) 
STREAMSERVER_OBJECTS =  \
    event/touchEvent.o \
    event/uievent.o \
    event/deviceOrientationEvent.o \
    event/event.o \
    event/eventTarget.o \
    event/gestureEvent.o \
    event/htmlFormEvent.o \
    event/htmlFrameOrObjectEvent.o \
    event/keyboardEvent.o \
    event/mouseEvent.o \
    event/mutationevent.o \
    event/touch.o \
    event/touchList.o \
    event/documentEvent.o \
    config.o \
    node.o \
    base.o \
    element.o \
    htmlElement.o \
    jstimer.o \
    navigator.o \
    select.o \
    textarea.o \
    utils.o \
    anchor.o \
    body.o \
    form.o \
    link.o \
    style.o \
    httpUtil.o \
    window.o \
    area.o \
    button.o \
    frame.o \
    image.o \
    meta.o \
    object.o \
    table.o \
    timer.o \
    attr.o \
    document.o \
    frameset.o \
    input.o \
    namenodemap.o \
    option.o \
    td.o \
    tr.o \
    ichrome.o


### Conditionally set variables: ###


### Targets: ###

all: $(SERVER_NAME) $(CLIENT_NAME)

$(STREAMSERVER_OBJECTS): common.h

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $(INCLUDES) $(srcdir)/$<

$(SERVER_NAME): $(STREAMSERVER_OBJECTS) common.h
	$(LD_CXX) $@ $(STREAMSERVER_OBJECTS) $(LDFLAGS) ~/tools/v8/out/native/obj.target/tools/gyp/libv8_base.a  ~/tools/v8/out/native/obj.target/tools/gyp/libv8_snapshot.a -lpthread -lxml2 -lcurl 
##	$(LD_CXX) $@ $(STREAMSERVER_OBJECTS) $(LDFLAGS) ~/tools/v8/out/x64.debug/obj.target/tools/gyp/libv8_base.a  ~/tools/v8/out/x64.debug/obj.target/tools/gyp/libv8_snapshot.a -lpthread -lxml2 -lcurl 

	 
clean: 
	rm -rf ./.deps ./.pch
	rm -f ./*.o
	rm -f event/*.o
	rm -f $(SERVER_NAME)

distclean: clean
	rm -f config.cache config.log config.status bk-deps bk-make-pch shared-ld-sh Makefile


.PHONY: all install uninstall clean distclean 
