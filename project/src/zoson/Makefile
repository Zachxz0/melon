func_obj = $(BUILD_DIR)/object.o
all:$(func_obj)
$(func_obj):object.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)

.Phony:clean
clean:
	rm -f *.o test