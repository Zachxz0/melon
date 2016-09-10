OBJ_FILE = $(BUILD_DIR)/log_neuron.o $(BUILD_DIR)/vec.o $(BUILD_DIR)/mat.o
TEST_OBJ = $(BUILD_DIR)/test.o
TEST_EXEC = $(BIN_DIR)/test
$(TEST_EXEC):$(TEST_OBJ) $(OBJ_FILE) 
	$(CC) $^ -o $@ -lstdc++
$(TEST_OBJ):test.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
