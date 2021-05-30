#--------------------------------------------------------------
#               KhoaDD2 Cross-compile Makefile
#--------------------------------------------------------------


LIBDIR ?= .libs
OBJDIR ?= .objs
EXEDIR ?= .exes

TARGET = example

ISDIR := $(shell if [ ! -d $(LIBDIR) ]; then mkdir $(LIBDIR); fi;)
ISDIR := $(shell if [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi;)
ISDIR := $(shell if [ ! -d $(EXEDIR) ]; then mkdir $(EXEDIR); fi;)


# Compiler Flags only used for compiling step
CPPFLAGS := -I./                                           \
			-I./inc                                        \

LDFLAGS := 


C_SRCS =  src/main.c

CPP_SRCS =

CPP_OBJS    = $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(CPP_SRCS))
C_OBJS    = $(patsubst src/%.c,$(OBJDIR)/%.o,$(C_SRCS)) 


debug: LDFLAGS += -g -O0 -Wall
debug: all

release: CPPFLAGS += -DDEBUG
release: LDFLAGS += -O3 -Wall
release: all 


all: $(TARGET) install

$(TARGET) : $(CPP_OBJS) $(C_OBJS)
	@echo Targeting $@
	$(LINK.cc) $(OBJDIR)/*.o  -o $(EXEDIR)/$@ 


$(OBJDIR)/%.o: src/%.c
	@echo Compiling C $@
	$(COMPILE.c) $< -o $@

$(OBJDIR)/%.o: src/%.cpp
	@echo Compiling C++ $@
	$(COMPILE.cc) $< -o $@

install:

.PHONY: all install

clean:
	@rm -rf $(OBJDIR) $(LIBDIR) $(EXEDIR) $(GENDIR)

.PHONY:checkmake 
checkmake:  
	@echo -e "\nMAKE_VERSION =	\n	${MAKE_VERSION}"  
	@echo -e "\nMAKEFILE_LIST =	\n	${MAKEFILE_LIST}"  
	@echo -e "\nCOMPILE.c =		\n	${COMPILE.c}"
	@echo -e "\nCOMPILE.cc =	\n	${COMPILE.cc}"
	@echo -e "\nCOMPILE.cpp =	\n	${COMPILE.cpp}"
	@echo -e "\nLINK.cc =		\n	${LINK.cc}"
	@echo -e "\nLINK.o =		\n	${LINK.o}"
	@echo -e "\nCPPFLAGS =		\n	${CPPFLAGS}"
	@echo -e "\nCFLAGS =		\n	${CFLAGS}"
	@echo -e "\nCXXFLAGS =		\n	${CXXFLAGS}"
	@echo -e "\nLDFLAGS =		\n	${LDFLAGS}"
	@echo -e "\nLDLIBS =		\n	${LDLIBS}" 