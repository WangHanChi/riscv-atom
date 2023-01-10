#!/bin/bash

# riscv-test dir

cd /home/$USER/riscv-atom/test/riscv-tests/isa

declare -a isa_RV32UI_p=( "add" "addi" "and" "andi" "auipc" "beq" "bge" "bgeu" "blt" "bltu" "bne" "jal" "jalr" "lb" "lbu" "lh" "lhu" "lui" "lw" "or" 
 "ori" "sb" "sh" "sll" "simple" "slli" "slt" "slti" "sltiu" "sltu" "sra" "srai" "srl" "srli" "sub" "sw" "xor" "xori" )

declare -a isa_RV32UM_p=( "div" "divu" "mul" "mulh" "mulhu" "mulhsu" "rem" "remu")

echo "Now test rv32ui for riscv-atom!!"
for isa_RV32UI in ${isa_RV32UI_p[@]}
do
    echo testing instruction ${isa_RV32UI}
    atomsim rv32ui-p-${isa_RV32UI}
    echo
done

echo
echo
echo

echo "Now test rv32um for riscv-atom!!"
for isa_RV32UM in ${isa_RV32UM_p[@]}
do
    echo testing instruction ${isa_RV32UM}
    atomsim rv32um-p-${isa_RV32UM}
    echo
done