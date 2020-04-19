// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// AXILiteS
// 0x000 : Control signals
//         bit 0  - ap_start (Read/Write/COH)
//         bit 1  - ap_done (Read/COR)
//         bit 2  - ap_idle (Read)
//         bit 3  - ap_ready (Read)
//         bit 7  - auto_restart (Read/Write)
//         others - reserved
// 0x004 : Global Interrupt Enable Register
//         bit 0  - Global Interrupt Enable (Read/Write)
//         others - reserved
// 0x008 : IP Interrupt Enable Register (Read/Write)
//         bit 0  - Channel 0 (ap_done)
//         bit 1  - Channel 1 (ap_ready)
//         others - reserved
// 0x00c : IP Interrupt Status Register (Read/TOW)
//         bit 0  - Channel 0 (ap_done)
//         bit 1  - Channel 1 (ap_ready)
//         others - reserved
// 0x080 ~
// 0x0ff : Memory 'd_o' (32 * 32b)
//         Word n : bit [31:0] - d_o[n]
// 0x100 ~
// 0x17f : Memory 'd_i' (32 * 32b)
//         Word n : bit [31:0] - d_i[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XAXI_INTERFACES_AXILITES_ADDR_AP_CTRL  0x000
#define XAXI_INTERFACES_AXILITES_ADDR_GIE      0x004
#define XAXI_INTERFACES_AXILITES_ADDR_IER      0x008
#define XAXI_INTERFACES_AXILITES_ADDR_ISR      0x00c
#define XAXI_INTERFACES_AXILITES_ADDR_D_O_BASE 0x080
#define XAXI_INTERFACES_AXILITES_ADDR_D_O_HIGH 0x0ff
#define XAXI_INTERFACES_AXILITES_WIDTH_D_O     32
#define XAXI_INTERFACES_AXILITES_DEPTH_D_O     32
#define XAXI_INTERFACES_AXILITES_ADDR_D_I_BASE 0x100
#define XAXI_INTERFACES_AXILITES_ADDR_D_I_HIGH 0x17f
#define XAXI_INTERFACES_AXILITES_WIDTH_D_I     32
#define XAXI_INTERFACES_AXILITES_DEPTH_D_I     32

