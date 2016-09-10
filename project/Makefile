#env path#
CC = gcc
APP = melon
CURR_DIR=$(shell pwd)
INCLUDE = $(CURR_DIR)/include
BUILD_DIR = $(CURR_DIR)/build
BIN_DIR = $(CURR_DIR)/bin
SUB_DIR = $(CURR_DIR)/src/melon $(CURR_DIR)/test
export CC INCLUDE BUILD_DIR BIN_DIR APP
#script#
all:CHECK_DIR $(SUB_DIR)
CHECK_DIR:
	mkdir -p $(BIN_DIR) $(BUILD_DIR)
$(SUB_DIR):ECHO
	$(MAKE) -C $@
ECHO:
	@echo $(SUBDIRS)
	@echo begin complie

.Phony:clean
clean:
	rm $(BUILD_DIR)/*.o $(BIN_DIR)/*

