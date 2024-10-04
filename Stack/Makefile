CC = g++
NAME = stack
CFLAGS = -I ./Header
HEADERS = $(wildcard Header/*.h)
SOURCES = $(wildcard Source/*.cpp)
SRC = $(patsubst %.cpp, Source_o/%.o, $(notdir $(SOURCES)))

all: createDir $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $@.exe

createDir:
	mkdir -p Source_o

Source_o/%.o: Source/$(notdir %.cpp)
	$(CC) $(CFLAGS) -c $< -o $@

# .PHONY : clear
clear:
	rm -f -r Source_o
	rm -f *.exe 
	rm -f *.o
