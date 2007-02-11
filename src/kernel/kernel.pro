#
# Project file for kernel
#
TEMPLATE = lib
LANGUAGE = C++

CONFIG += staticlib
CONFIG += complete 
CONFIG += console precompile_header
CONFIG += debug
CONFIG -= qt
DEFINES += DEBUG

#PRECOMPILED_HEADER = static.h

#
# Building tests
#
tests.commands	= qmake -o Makefile-tests kernel-tests.pro && make -f Makefile-tests
tests.depends	= libkernel.a
QMAKE_EXTRA_UNIX_TARGETS += tests

#
# Cleaning tests
#
cleanall.commands	= make clean && make -f Makefile-tests clean
QMAKE_EXTRA_UNIX_TARGETS += cleanall


#
# Common utils
#
HEADERS += ../utils/debug.h ../utils/iterator.h ../utils/observer.h

#
# Special utils
#
HEADERS += exceptions.h modecontroller.h filters.h xpdf.h cxref.h xrefwriter.h factories.h
HEADERS += pdfwriter.h
SOURCES += modecontroller.cc filters.cc factories.cc

#
# CObjects
#
HEADERS += iproperty.h cobject.h 
HEADERS += cobjectsimple.h cobjectsimpleI.h carray.h cdict.h cstream.h cstreamsxpdfreader.h
HEADERS += cobjecthelpers.h ccontentstream.h pdfoperators.h pdfoperatorsiter.h cpage.h cpdf.h 
HEADERS += streamwriter.h cinlineimage.h coutline.h stateupdater.h
HEADERS += cannotation.h

SOURCES += cannotation.cc
SOURCES += cxref.cc xrefwriter.cc streamwriter.cc
SOURCES += iproperty.cc carray.cc cdict.cc cstream.cc cobject.cc
SOURCES += cobjecthelpers.cc ccontentstream.cc pdfoperators.cc pdfoperatorsiter.cc stateupdater.cc
SOURCES += pdfwriter.cc
SOURCES += cinlineimage.cc coutline.cc
SOURCES += cpage.cc cpdf.cc 

#
# Add ons
#
HEADERS += textoutput.h textoutputbuilder.h textoutputentities.h textoutputengines.h
SOURCES += textoutputengines.cc textoutputentities.cc textoutputbuilder.cc

#
# Kernel special settings
#
#QMAKE_CXXFLAGS += -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings -Wuninitialized -ansi -pedantic -Wno-unused-variable -finline-limit=10000 --param inline-unit-growth=1000 --param large-function-growth=1000
#QMAKE_CXXFLAGS_DEBUG += -W -Wall -Wconversion -Wcast-qual -Wwrite-strings  -ansi -pedantic -Wno-unused-variable -O0 -Wunused-function
QMAKE_CXXFLAGS += -fexceptions
QMAKE_CXXFLAGS_DEBUG += -fexceptions -W -Wall -Wconversion -Wwrite-strings  -ansi -pedantic -Wno-unused-variable -O0 -Wunused-function -Wwrite-strings -Wunused-macros 

#
# Static lib
#
QMAKE_CXXFLAGS_DEBUG += -static

#
# xpdf and utils
#
INCLUDEPATH += ../ ../utils ../xpdf/ ../xpdf/xpdf ../xpdf/goo ../xpdf/splash ../xpdf/fofi

#
# Directories to creating files
#
unix {
  OBJECTS_DIR = .obj
}

include(kernel-obj.pro)
