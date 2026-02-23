CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -O2 -I./include

TARGETS := cachesim dcachesim
TARGET := cachesim
ICACHE_OBJ := build/icache.o build/main.o
DCACHE_OBJ := build/dcache.o build/dcache_main.o
DEP := $(ICACHE_OBJ:.o=.d) $(DCACHE_OBJ:.o=.d)

.PHONY: all clean run test

all: $(TARGETS)

run: cachesim
	@if [ -z "$(M)" ] || [ -z "$(N)" ]; then \
		echo "Usage: make run M=<m> N=<n>"; \
		echo "  M: offset bits (cache line size = 2^M bytes)"; \
		echo "  N: index bits (cache lines = 2^N)"; \
		echo "Example: make run M=6 N=8"; \
		exit 1; \
	fi
	./cachesim $(M) $(N)

run_d: dcachesim
	@if [ -z "$(M)" ] || [ -z "$(N)" ]; then \
		echo "Usage: make run_d M=<m> N=<n>"; \
		echo "  M: offset bits (cache line size = 2^M bytes)"; \
		echo "  N: index bits (cache lines = 2^N)"; \
		echo "Example: make run_d M=6 N=8"; \
		exit 1; \
	fi
	./dcachesim $(M) $(N)

test: cachesim
	@echo "Testing various cache configurations (fixed block size = 64B)..."
	@echo "\n=== Configuration 1: 64B line, 16 lines (1KB) ==="
	@./cachesim 2 4
	@echo "\n=== Configuration 2: 64B line, 64 lines (4KB) ==="
	@./cachesim 2 6
	@echo "\n=== Configuration 3: 64B line, 256 lines (16KB) ==="
	@./cachesim 2 8
	@echo "\n=== Configuration 4: 64B line, 1024 lines (64KB) ==="
	@./cachesim 2 10

cachesim: $(ICACHE_OBJ)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "[Build] $@ done"

dcachesim: $(DCACHE_OBJ)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "[Build] $@ done"

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@
	@echo "[CC] $<"

-include $(DEP)

clean:
	@rm -rf build $(TARGETS)
	@echo "[Clean] done"
