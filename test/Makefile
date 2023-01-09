ROOT_RVATOM ?= $(shell cd .. && pwd)

.PHONY: riscv-arch-test

test: riscv-arch-test
	export ROOT_RVATOM=$(Root_RVATOM); \
	export TARGET_SIM="$(ROOT_RVATOM)/sim/sim -t"; \
	export RISCV_TARGET=srv32; \
	$(MAKE) -C riscv-arch-test