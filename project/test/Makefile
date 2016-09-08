OBJ_FILE = $(BUILD_DIR)/logregres.o
TEST_OBJ = $(BUILD_DIR)/test.o
TEST_EXEC = $(BIN_DIR)/test
$(TEST_EXEC):$(OBJ_FILE) $(TEST_OBJ) 
	$(CC) $^ -o $@ -lstdc++
$(TEST_OBJ):test.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
