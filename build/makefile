CC=/usr/bin/g++
FLAGS=-g -fno-rtti -std=c++11 -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

BIN=./bin
EXDIR=../example
OBJS=$(BIN)/objs
EXOBJ=$(OBJS)/example

# install dirs
INCDIR=/usr/local/include/iterator_decorator

SOURCES=$(wildcard $(SRC)/*.cpp)
OBJECTS=$(patsubst %, $(OBJS)/%, $(notdir $(SOURCES:%.cpp=%.o)))

# examples
EXSRC=$(wildcard $(EXDIR)/*.cpp)
EXOBJS=$(patsubst %, $(EXOBJ)/%, $(notdir $(EXSRC:%.cpp=%.o)))
EXAMPLES=$(patsubst %, $(BIN)/%, $(notdir $(EXSRC:%.cpp=%)))

.PHONY: clean all dirs lib example

$(OBJS)/%.o: $(SRC)/%.cpp
	$(CC) -o $@ -c $< -fPIC $(FLAGS) 2> object.log

$(EXOBJ)/%.o: $(EXDIR)/%.cpp
	$(CC) -c $< -o $@ $(FLAGS) 2> example_object.log

$(BIN)/%: $(EXOBJ)/%.o
	$(CC) $< -o $@ $(FLAGS) $(SLIB) 2> example.log

all: dirs $(EXAMPLES)

$(EXAMPLES): $(EXOBJS)

$(EXOBJS): $(EXSRC)

clean:
	rm -rf $(BIN)
	rm ./*.log

dirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJS)
	mkdir -p $(EXOBJ)

install:
	mkdir -p -m  655 $(INCDIR)
	cp -r ../include/* $(INCDIR)

remove: $(INCDIR)
	rm -r $(INCDIR)
