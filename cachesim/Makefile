CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -O2 -I./include

TARGET := cachesim
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:src/%.cpp=build/%.o)
DEP := $(OBJ:.o=.d)

.PHONY: all clean run test

all: $(TARGET)

run: $(TARGET)
	@if [ -z "$(M)" ] || [ -z "$(N)" ]; then \
		echo "Usage: make run M=<m> N=<n>"; \
		echo "  M: offset bits (cache line size = 2^M bytes)"; \
		echo "  N: index bits (cache lines = 2^N)"; \
		echo "Example: make run M=6 N=8"; \
		exit 1; \
	fi
	./$(TARGET) $(M) $(N)

test: $(TARGET)
	@echo "Testing various cache configurations (fixed block size = 64B)..."
	@echo "\n=== Configuration 1: 64B line, 16 lines (1KB) ==="
	@./$(TARGET) 6 4
	@echo "\n=== Configuration 2: 64B line, 64 lines (4KB) ==="
	@./$(TARGET) 6 6
	@echo "\n=== Configuration 3: 64B line, 256 lines (16KB) ==="
	@./$(TARGET) 6 8
	@echo "\n=== Configuration 4: 64B line, 1024 lines (64KB) ==="
	@./$(TARGET) 6 10

$(TARGET): $(OBJ)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "[Build] $@ done"

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@
	@echo "[CC] $<"

-include $(DEP)

clean:
	@rm -rf build $(TARGET)
	@echo "[Clean] done"
