CSRC_DIR  = csrc
VSRC_DIR  = vsrc
OUT_DIR   = obj_dir
CSRC_NAME = sim_main.cpp
VSRC_NAME = our.v

WAVE_FILE = wave.vcd

VERILATOR_FLAG = --cc --exe --build -j 0 -Wall --trace

include ../Makefile

all:
	verilator $(VERILATOR_FLAG) $(CSRC_DIR)/$(CSRC_NAME) $(VSRC_DIR)/$(VSRC_NAME)
run:
	$(OUT_DIR)/Vour
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	gtkwave $(WAVE_FILE)
clean:
	rm -rf $(OUT_DIR)
	rm $(WAVE_FILE)
