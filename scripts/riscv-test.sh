#!/bin/bash

# riscv-test dir

RED="\e[31m"
GREEN="\e[32m"
ORANGE="\e[33m"
CYAN="\e[36m"
NOCOLOR="\e[0m"

cd /home/$USER/riscv-atom/test/riscv-tests/isa

declare -a isa_RV32UI_p=( "add" "addi" "and" "andi" "auipc" "beq" "bge" "bgeu" "blt" "bltu" "bne" "jal" "jalr" "lb" "lbu" "lh" "lhu" "lui" "lw" "or" 
 "ori" "sb" "sh" "sll" "simple" "slli" "slt" "slti" "sltiu" "sltu" "sra" "srai" "srl" "srli" "sub" "sw" "xor" "xori" )

declare -a isa_RV32UM_p=( "div" "divu" "mul" "mulh" "mulhu" "mulhsu" "rem" "remu")


suss_rv32ui=0
fail_rv32ui=0
total_rv32ui=0

suss_rv32um=0
fail_rv32um=0
total_rv32um=0

echo "Now test rv32ui for riscv-atom!!"
for isa_RV32UI in ${isa_RV32UI_p[@]}
do
    echo testing instruction ${isa_RV32UI}
    atomsim rv32ui-p-${isa_RV32UI}
    output=$(atomsim rv32ui-p-${isa_RV32UI})
    length=${#output}
    substring=${output:length-1:1}
    if [ $substring == "1" ]
    then 
    	suss_rv32ui=$(($suss_rv32ui+1))
    else 
    	fail_rv32ui=$(($fail_rv32ui+1))
    fi
    total_rv32ui=$(($total_rv32ui+1))
    echo
done

echo



echo "Now test rv32um for riscv-atom!!"
for isa_RV32UM in ${isa_RV32UM_p[@]}
do
    echo testing instruction ${isa_RV32UM}
    atomsim rv32um-p-${isa_RV32UM}
    output=$(atomsim rv32um-p-${isa_RV32UM})
    length=${#output}
    substring=${output:length-1:1}
    if [ $substring == "1" ]
    then 
    	suss_rv32um=$(($suss_rv32um+1))
    else 
    	fail_rv32um=$(($fail_rv32um+1))
    fi
    total_rv32um=$(($total_rv32um+1))
    echo
done

echo "=============================="
echo "rv32ui-p instruction set :"
echo -e "${NOCOLOR}The pass rate is ${GREEN}$suss_rv32ui/$total_rv32ui"
echo -e "${NOCOLOR}The fail rate is ${RED}$fail_rv32ui/$total_rv32ui${NOCOLOR}"
if [ $fail_rv32ui == "0" ]
then 
	echo -e "${CYAN}Pass rv32ui-p testing! ${NOCOLOR}"
else
	echo -e "${CYAN}Fail rv32ui-p testing! ${NOCOLOR}"
fi	
echo "=============================="
echo "rv32um-p instruction set :"
echo -e "${NOCOLOR}The pass rate is ${GREEN}$suss_rv32um/$total_rv32um"
echo -e "${NOCOLOR}The fail rate is ${RED}$fail_rv32um/$total_rv32um${NOCOLOR}"
if [ $fail_rv32um == "0" ]
then 
	echo -e "${CYAN}Pass rv32um-p testing! ${NOCOLOR}"
else
	echo -e "${CYAN}Fail rv32um-p testing! ${NOCOLOR}"
fi	
echo "=============================="
