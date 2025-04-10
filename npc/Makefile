TOPNAME = top
VERILATOR = verilator
VERILATOR_FLAGS += --cc --trace-fst -Wall --top-module $(TOPNAME) -j 0

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

# 自动创建 build 目录
$(shell mkdir -p $(BUILD_DIR))

# 源码
VSRCS = ./vsrc/top.v $(shell find ./vsrc -name "*.v" ! -name "top.v")
CSRCS = ./csrc/main.cpp $(shell find ./csrc -name "*.c" -or -name "*.cc" -or -name "*.cpp" ! -name "main.cpp")

# 头文件路径（可选）
INC_PATH += $(shell find ./csrc -name "*.h")
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -std=c++17 -DTOP_NAME="\"V$(TOPNAME)\""

all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@rm -rf $(OBJ_DIR)
	@echo
	@echo "-- VERILATE ----------------"
	$(VERILATOR) $(VERILATOR_FLAGS) --build \
		--exe $(CSRCS) \
		--Mdir $(OBJ_DIR) \
		-o $(abspath $(BIN)) \
		$(addprefix -CFLAGS , $(CXXFLAGS)) \
		$(VSRCS)

	@echo
	@echo "-- RUN ---------------------"
	@rm -rf logs
	@mkdir -p logs
	obj_dir/Vtop +trace

include ../Makefile
