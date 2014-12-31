CC=gcc
CCFLAGS=-Wall
LDFLAGS=
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
	TARGET=driver
	 
all: $(TARGET)
	 
$(TARGET): $(OBJECTS)
	        $(CC) $(LDFLAGS) -o $@ $^
			 
%.o: %.c %.h
	        $(CC) $(CCFLAGS) -c $<
			 
%.o: %.c
	        $(CC) $(CCFLAGS) -c $<
			 
clean:
	        rm -f *.o $(TARGET)
