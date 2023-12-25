SOURCE_DIR ?= src
HEADER_OUT_DIR ?= include
LIB_OUT_DIR ?= lib

OBJS += $(SOURCE_DIR)/llib.o
HEADER ?= llib.h

LIB_OUT ?= $(LIB_OUT_DIR)/llib.a
HEADER_SRC ?= $(SOURCE_DIR)/$(HEADER)
HEADER_OUT ?= $(HEADER_OUT_DIR)/$(HEADER)

# Set to gcc if not defined
CC ?= gcc
MKDIR ?= mkdir -p
CP ?= cp -f

WFLAGS += -Wall -Wextra -Wpedantic -Werror
CFLAGS ?= -O2
AFLAGS += rcs
LFLAGS += 

.SUFFIXES: .c .o

.c.o:
	@echo "  CC $@"
	@ $(CC) -c $(CFLAGS) $(WFLAGS) -o $@ $<

all : $(LIB_OUT_DIR) $(HEADER_OUT_DIR) $(LIB_OUT) $(HEADER_OUT)

$(LIB_OUT): $(OBJS)
	@echo "  AR $@"
	@ $(AR) $(AFLAGS) $@ $^

$(HEADER_OUT):
	@echo "  CP $(HEADER_SRC) $@"
	@ $(CP) $(HEADER_SRC) $@

$(LIB_OUT_DIR):
	@echo "  MKDIR $(LIB_OUT_DIR)"
	@ $(MKDIR) ./$(LIB_OUT_DIR)

$(HEADER_OUT_DIR):
	@echo "  MKDIR $(HEADER_OUT_DIR)"
	@ $(MKDIR) $(HEADER_OUT_DIR)

.PHONY: clean

clean:
	@echo "  CLEAN $(OBJS) $(LIB_OUT) $(HEADER_OUT)"
	@ $(RM) $(OBJS) $(LIB_OUT) $(HEADER_OUT)
	@echo "  CLEAN $(LIB_OUT_DIR) $(HEADER_OUT_DIR)"
	@ $(RM) -r $(LIB_OUT_DIR) $(HEADER_OUT_DIR)
