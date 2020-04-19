############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project axi_array
set_top axi_interfaces
add_files axi_interfaces.c
add_files -tb axi_interfaces_test.c
add_files -tb result.golden.dat
open_solution "solution1"
set_part {xc7z020clg400-2} -tool vivado
create_clock -period 10 -name default
#source "./axi_array/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
