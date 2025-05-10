TOPNAME = top
NXDC_FILES = constr/top.nxdc
INC_PATH ?= $(NPC_HOME)/include

VERILATOR = verilator
VERILATOR_COVERAGE = verilator_coverage
VERILATOR_FLAGS += --cc --trace -j 0 --top-module top

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS += ./vsrc/top.v $(shell find $(abspath ./vsrc) -name "*.v" ! -name "top.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

LDFLAGS += -lreadline -lncurses

# am img
IMG ?=

$(BIN): $(VSRCS) $(CSRCS) $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE)
	@echo "--Build--"
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_FLAGS) --build \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all:
	@echo "Write this Makefile by your self."

nvb: $(BIN)
	@echo "--RUN--"
	@$^

sim: $(VSRCS) $(CSRCS)
	@echo
	@echo "-- BUILD ----------------"
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_FLAGS) --build \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

	@echo
	@echo "-- RUN ---------------------"
	@rm -rf logs
	@mkdir -p logs
	$(BIN) -i $(IMG) +trace

run: sim

clean:
	rm -rf $(BUILD_DIR) logs obj_dir

include ../Makefile

.PHONY: all clean sim nvb
