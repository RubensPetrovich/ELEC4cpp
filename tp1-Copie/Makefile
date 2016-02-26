##
## header-start
##################################################################################
##
## \file      Makefile
##
## \brief     This file belongs to the C++ tutorial project
##
## \author    Bernard
##
## \copyright Copyright ng2goodies 2015
##            Distributed under the MIT License
##            See http://opensource.org/licenses/MIT
##
##################################################################################
## header-log
##
## $Author$
## $Date$
## $Revision$
##
##################################################################################
## header-end
##



LDFLAGS            := -lm
CC                 := g++
OBJDIR             := ./build

CFLAGS_COMMON      := -Wall -Wshadow -Wextra -Wno-unused-parameter -Werror
CFLAGS_COMMON      += -std=c++14

CFLAGS_DEBUG       := $(CFLAGS_COMMON) -O -g
CFLAGS             := $(CFLAGS_COMMON) -O3


## Special pre-processing statements to define
## the source files associated with each
## target: mean_and_median, map1, map2, histogram


ifeq ($(MAKECMDGOALS), mean_and_median)
TARGET             := mean_and_median.exe
SRC_FILES          := mean_and_median.cpp
else
ifeq ($(MAKECMDGOALS), map1)
TARGET             := map1.exe
SRC_FILES          := map1.cpp
else
ifeq ($(MAKECMDGOALS), map2)
TARGET             := map2.exe
SRC_FILES          := map2.cpp
else
ifeq ($(MAKECMDGOALS), histogram)
TARGET             := histogram.exe
SRC_FILES          := histogram.cpp
else 
TARGET             := *.exe
SRC_FILES          := map1.cpp map2.exe histogram.cpp
endif
endif
endif
endif





OBJECT_FILES       := $(addprefix  $(OBJDIR)/,$(notdir $(SRC_FILES:.cpp=.r.o)))
OBJECT_FILES_DEBUG := $(addprefix  $(OBJDIR)/,$(notdir $(SRC_FILES:.cpp=.d.o)))
DEP_FILES          := $(addprefix  $(OBJDIR)/,$(notdir $(SRC_FILES:.cpp=.r.P)))
DEP_FILES_DEBUG    := $(addprefix  $(OBJDIR)/,$(notdir $(SRC_FILES:.cpp=.d.P)))


.PHONY: help mean_and_median clean map1 map2 histogram

help:
	@printf "make mean_and_median => compile mean_and_median\n"
	@printf "make histogram       => compile histogram\n"
	@printf "make map1            => compile map1\n"
	@printf "make map2            => compile map2\n"
	@printf "make clean           => remove all generated files\n"
	@printf "make help            => print this help\n"


  
mean_and_median: $(TARGET)

map1: $(TARGET)

map2: $(TARGET)
  
histogram: $(TARGET)


$(TARGET): $(OBJECT_FILES) Makefile
	$(CC) -o $@ $(OBJECT_FILES) $(LDFLAGS)

debug: $(OBJECT_FILES_DEBUG) Makefile
	$(CC) -o $(TARGET).$@ $(OBJECT_FILES_DEBUG) $(LDFLAGS)

c-version:
	gcc -O3 -o $(TARGET).$@ mean_and_median.c



$(OBJECT_FILES)        :| $(OBJDIR)
$(OBJECT_FILES_DEBUG)  :| $(OBJDIR)

#
# Generation of dependency include files during compilation
# which will be used during the next compilation
# thanks to  http://make.paulandlesley.org/autodep.html
#


$(OBJDIR)/%.r.o : ./%.cpp
	@printf "Compiling release version of $<\n"
	$(CC) -c -MMD -MF $(OBJDIR)/$*.r.d -MT $(OBJDIR)/$*.r.o $(CFLAGS) -o $@ $<
	@cp $(OBJDIR)/$*.r.d $(OBJDIR)/$*.r.P
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJDIR)/$*.r.d >> $(OBJDIR)/$*.r.P
	@rm -f $(OBJDIR)/$*.r.d

$(OBJDIR)/%.d.o : ./%.cpp
	@printf "Compiling debug version of $<\n"
	$(CC) -c -MMD -MF $(OBJDIR)/$*.d.d -MT $(OBJDIR)/$*.d.o $(CFLAGS_DEBUG) -o $@ $<
	@cp $(OBJDIR)/$*.d.d $(OBJDIR)/$*.d.P
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(OBJDIR)/$*.d.d >> $(OBJDIR)/$*.d.P
	@rm -f $(OBJDIR)/$*.d.d


$(OBJDIR):
	mkdir -p $@




clean:
	$(RM) $(TARGET) $(TARGET).debug $(TARGET).c_version $(OBJECT_FILES)  $(OBJECT_FILES_DEBUG) $(DEP_FILES) $(DEP_FILES_DEBUG)


.SUFFIXES:              # Delete the default suffixes
.SUFFIXES: .cpp .o .h   # Define "CPP" language suffix list

-include $(DEP_FILES)
-include $(DEP_FILES_DEBUG)




## NOTE#1
## target: | dir
## test for existence dependency, not for time dependency
##
## NOTE#2
## additional stuff
## generation of assembly code GAS syntax
##
## g++ -march=core-avx2 -Wall -O3 -std=c++11 -S -fverbose-asm -Wa,-adhln main.cpp
##
