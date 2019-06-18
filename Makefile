SOURCES = matrix.cc head.cc
OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))
FLAGS = -g -W -Wall
TARGET = out
$(TARGET) : $(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) 
%.o : %.c
	g++ -c $(FLAGS) $< -o $@
clean:
	rm -f *.o $(TARGET)
