ifdef CONFIG_DIFFTEST
DIFF_REF_PATH = $(NEMU_HOME)/build/test
ifeq ($(wildcard $(DIFF_REF_PATH)),)
	$(error $(DIFF_REF_PATH) 路径不存在)
endif
DIFF_REF_SO = $(DIFF_REF_PATH)/riscv-nemu-interpreter-so
ARGS_DIFF = --diff=$(DIFF_REF_SO)
endif
