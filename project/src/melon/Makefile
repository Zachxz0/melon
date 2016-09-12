stumpneuron_obj = $(BUILD_DIR)/stump_neuron.o 
layer_obj = $(BUILD_DIR)/layer.o
logneuron_obj = $(BUILD_DIR)/log_neuron.o 
linearneuron_obj = $(BUILD_DIR)/linear_neuron.o 
vector_obj = $(BUILD_DIR)/vec.o
matrix_obj = $(BUILD_DIR)/mat.o
reader_obj = $(BUILD_DIR)/reader.o
all:$(vector_obj) $(matrix_obj) $(reader_obj) $(logneuron_obj) $(linearneuron_obj) $(stumpneuron_obj) $(layer_obj)
$(vector_obj):vec.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(matrix_obj):mat.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(logneuron_obj):log_neuron.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(linearneuron_obj):linear_neuron.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(reader_obj):reader.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(layer_obj):layer.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)
$(stumpneuron_obj):stump_neuron.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)


.Phony:clean
clean:
	rm -f *.o test