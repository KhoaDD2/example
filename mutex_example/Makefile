#--------------------------------------------------------------
#               KhoaDD2 Cross-compile Makefile
#--------------------------------------------------------------


LIBDIR ?= .libs
OBJDIR ?= .objs
EXEDIR ?= .exes

TARGET_WRONG = example_wrong
TARGET_RIGHT = example_right

ISDIR := $(shell if [ ! -d $(LIBDIR) ]; then mkdir $(LIBDIR); fi;)
ISDIR := $(shell if [ ! -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi;)
ISDIR := $(shell if [ ! -d $(EXEDIR) ]; then mkdir $(EXEDIR); fi;)


# Compiler Flags only used for compiling step
CPPFLAGS := -I./                                           \
			-I./inc                                        \

# LDFLAGS add lib for thread
LDFLAGS := -lpthread



# Right code
C_RIGHT_SRCS =  src/main_right.c
CPP_RIGHT_SRCS =

C_RIGHT_OBJS    = $(patsubst src/%.c,$(OBJDIR)/%.o,$(C_RIGHT_SRCS)) 
CPP_RIGHT_OBJS    = $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(CPP_RIGHT_SRCS))
# Wrong code
C_WRONG_SRCS =  src/main_wrong.c
CPP_WRONG_SRCS =

C_WRONG_OBJS    = $(patsubst src/%.c,$(OBJDIR)/%.o,$(C_WRONG_SRCS)) 
CPP_WRONG_OBJS    = $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(CPP_WRONG_SRCS))

# define for debug and release
debug: LDFLAGS += -g -O0 -Wall
debug: all

release: CPPFLAGS += -DDEBUG
release: LDFLAGS += -O3 -Wall
release: all 


all: $(TARGET_WRONG) $(TARGET_RIGHT) install

$(TARGET_WRONG) : $(CPP_WRONG_OBJS) $(C_WRONG_OBJS)
	@echo Targeting $@
	$(LINK.cc) -o $(EXEDIR)/$@ $< $(LDFLAGS)

$(TARGET_RIGHT) : $(CPP_RIGHT_OBJS) $(C_RIGHT_OBJS)
	@echo Targeting $@
	$(LINK.cc) -o $(EXEDIR)/$@ $< $(LDFLAGS)


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
	@echo -e "\nC_WRONG_OBJS =		\n	${C_WRONG_OBJS}" 
	@echo -e "\nC_RIGHT_OBJS =		\n	${C_RIGHT_OBJS}" 