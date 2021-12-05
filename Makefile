CC = g++

SDIR = src
IDIR = -Iinclude

COMPILER_FLAGS = -w $(IDIR)
LINKER_FLAGS = -lSDL2

CPPFILES = $(wildcard $(SDIR)/*.cpp)

OBJ_NAME = COR

all : $(CPPFILES)
	$(CC) $(CPPFILES) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

