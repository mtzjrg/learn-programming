# https://www.lucavall.in/blog/crafting-clean-maintainable-understandable-makefile-for-c-project
# Project Settings
.DEFAULT_GOAL := all
debug ?= 0
NAME := $(patsubst %.c,%,$(wildcard ./*/*.c))
BIN_DIR := ./bin

CC := gcc
CFLAGS := -W -Wall -ansi -pedantic
LDFLAGS := -lm

ifeq ($(debug), 1)
	CFLAGS := $(CFLAGS) -g
endif

all: $(addprefix $(BIN_DIR)/,$(NAME))

$(BIN_DIR)/%: %.c | dir
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

dir:
	@mkdir -p $(BIN_DIR)

clean:
	@rm -rf $(BIN_DIR)

.PHONY: all dir clean
