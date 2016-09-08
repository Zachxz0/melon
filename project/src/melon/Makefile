logregres_obj = $(BUILD_DIR)/logregres.o
$(logregres_obj):logregres.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)

.Phony:clean
clean:
	rm -f *.o test