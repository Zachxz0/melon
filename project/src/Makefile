SUB_DIRS= zoson utils melon
export CC INCLUDE BUILD_DIR APP BIN_DIR

all:$(SUB_DIRS)
$(SUB_DIRS):ECHO
	$(MAKE) -C $@
ECHO:
	@echo $(SUB_DIRS)
	@echo begin complie
clean:
	@$(RM) $(BUILD_DIR)/*.o
	$rm -rf $(BIN_DIR)