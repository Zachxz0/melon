func_obj = $(BUILD_DIR)/func.o
all:$(func_obj)
$(func_obj):func.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)

.Phony:clean
clean:
	rm -f *.o test