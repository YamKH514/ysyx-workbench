ifdef CONFIG_DIFFTEST
DIFF_REF_PATH = $(NEMU_HOME)/build
DIFF_REF_SO = $(DIFF_REF_PATH)/riscv-nemu-interpreter-so
ARGS_DIFF = --diff=$(DIFF_REF_SO)
endif
