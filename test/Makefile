ROOT_RVATOM ?= $(shell cd .. && pwd)

.PHONY: riscv-arch-test

test: riscv-arch-test
	export ROOT_RVATOM=$(Root_RVATOM); \
	#export TARGET_SIM="$(ROOT_RVATOM)/sim/atomsim -t"; \
	export TARGET_SIM="atomsim -t"; \
	export RISCV_TARGET=riscv-atom; \
	$(MAKE) -C riscv-arch-test