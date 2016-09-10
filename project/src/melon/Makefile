logneuron_obj = $(BUILD_DIR)/log_neuron.o
vector_obj = $(BUILD_DIR)/vec.o
matrix_obj = $(BUILD_DIR)/mat.o
all:$(vector_obj) $(matrix_obj) $(logneuron_obj)
$(vector_obj):vec.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(matrix_obj):mat.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(logneuron_obj):log_neuron.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)

.Phony:clean
clean:
	rm -f *.o test