TARGET_EXEC ?= s-arp
CC := gcc

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

LDFLAGS := -lncurses -lpcap

CPPFLAGS ?= $(INC_FLAGS)
CFLAGS ?= -std=gnu99

./$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS) 

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@



.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

install:
	cp $(TARGET_EXEC) /usr/local/bin

-include $(DEPS)

MKDIR_P ?= mkdir -p
