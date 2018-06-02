#---------
#
# CppUTest Examples Makefile
#
#----------

#Set this to @ to keep the makefile quiet
ifndef SILENCE
	SILENCE = @
endif

#--- Inputs ----#
COMPONENT_NAME = Logger
CPPUTEST_HOME = /home/wrable/C/cpputest

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

CPPUTEST_CXXFLAGS := -g -Wall

SRC_DIRS = \
	src

TEST_SRC_DIRS = \
	Test \
	Test/Utest
	

INCLUDE_DIRS =\
  .\
  src\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


