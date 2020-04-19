// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xaxi_interfaces.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XAxi_interfaces_CfgInitialize(XAxi_interfaces *InstancePtr, XAxi_interfaces_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XAxi_interfaces_Start(XAxi_interfaces *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAxi_interfaces_ReadReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_AP_CTRL) & 0x80;
    XAxi_interfaces_WriteReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XAxi_interfaces_IsDone(XAxi_interfaces *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAxi_interfaces_ReadReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XAxi_interfaces_IsIdle(XAxi_interfaces *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAxi_interfaces_ReadReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XAxi_interfaces_IsReady(XAxi_interfaces *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAxi_interfaces_ReadReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XAxi_interfaces_EnableAutoRestart(XAxi_interfaces *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAxi_interfaces_WriteReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XAxi_interfaces_DisableAutoRestart(XAxi_interfaces *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAxi_interfaces_WriteReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_AP_CTRL, 0);
}

u32 XAxi_interfaces_Get_d_o_BaseAddress(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_O_BASE);
}

u32 XAxi_interfaces_Get_d_o_HighAddress(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_O_HIGH);
}

u32 XAxi_interfaces_Get_d_o_TotalBytes(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XAXI_INTERFACES_AXILITES_ADDR_D_O_HIGH - XAXI_INTERFACES_AXILITES_ADDR_D_O_BASE + 1);
}

u32 XAxi_interfaces_Get_d_o_BitWidth(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAXI_INTERFACES_AXILITES_WIDTH_D_O;
}

u32 XAxi_interfaces_Get_d_o_Depth(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAXI_INTERFACES_AXILITES_DEPTH_D_O;
}

u32 XAxi_interfaces_Write_d_o_Words(XAxi_interfaces *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XAXI_INTERFACES_AXILITES_ADDR_D_O_HIGH - XAXI_INTERFACES_AXILITES_ADDR_D_O_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_O_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XAxi_interfaces_Read_d_o_Words(XAxi_interfaces *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XAXI_INTERFACES_AXILITES_ADDR_D_O_HIGH - XAXI_INTERFACES_AXILITES_ADDR_D_O_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_O_BASE + (offset + i)*4);
    }
    return length;
}

u32 XAxi_interfaces_Write_d_o_Bytes(XAxi_interfaces *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XAXI_INTERFACES_AXILITES_ADDR_D_O_HIGH - XAXI_INTERFACES_AXILITES_ADDR_D_O_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_O_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XAxi_interfaces_Read_d_o_Bytes(XAxi_interfaces *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XAXI_INTERFACES_AXILITES_ADDR_D_O_HIGH - XAXI_INTERFACES_AXILITES_ADDR_D_O_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_O_BASE + offset + i);
    }
    return length;
}

u32 XAxi_interfaces_Get_d_i_BaseAddress(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_I_BASE);
}

u32 XAxi_interfaces_Get_d_i_HighAddress(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_I_HIGH);
}

u32 XAxi_interfaces_Get_d_i_TotalBytes(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XAXI_INTERFACES_AXILITES_ADDR_D_I_HIGH - XAXI_INTERFACES_AXILITES_ADDR_D_I_BASE + 1);
}

u32 XAxi_interfaces_Get_d_i_BitWidth(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAXI_INTERFACES_AXILITES_WIDTH_D_I;
}

u32 XAxi_interfaces_Get_d_i_Depth(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAXI_INTERFACES_AXILITES_DEPTH_D_I;
}

u32 XAxi_interfaces_Write_d_i_Words(XAxi_interfaces *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XAXI_INTERFACES_AXILITES_ADDR_D_I_HIGH - XAXI_INTERFACES_AXILITES_ADDR_D_I_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_I_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XAxi_interfaces_Read_d_i_Words(XAxi_interfaces *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XAXI_INTERFACES_AXILITES_ADDR_D_I_HIGH - XAXI_INTERFACES_AXILITES_ADDR_D_I_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_I_BASE + (offset + i)*4);
    }
    return length;
}

u32 XAxi_interfaces_Write_d_i_Bytes(XAxi_interfaces *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XAXI_INTERFACES_AXILITES_ADDR_D_I_HIGH - XAXI_INTERFACES_AXILITES_ADDR_D_I_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_I_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XAxi_interfaces_Read_d_i_Bytes(XAxi_interfaces *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XAXI_INTERFACES_AXILITES_ADDR_D_I_HIGH - XAXI_INTERFACES_AXILITES_ADDR_D_I_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Axilites_BaseAddress + XAXI_INTERFACES_AXILITES_ADDR_D_I_BASE + offset + i);
    }
    return length;
}

void XAxi_interfaces_InterruptGlobalEnable(XAxi_interfaces *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAxi_interfaces_WriteReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_GIE, 1);
}

void XAxi_interfaces_InterruptGlobalDisable(XAxi_interfaces *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAxi_interfaces_WriteReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_GIE, 0);
}

void XAxi_interfaces_InterruptEnable(XAxi_interfaces *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAxi_interfaces_ReadReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_IER);
    XAxi_interfaces_WriteReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_IER, Register | Mask);
}

void XAxi_interfaces_InterruptDisable(XAxi_interfaces *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAxi_interfaces_ReadReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_IER);
    XAxi_interfaces_WriteReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_IER, Register & (~Mask));
}

void XAxi_interfaces_InterruptClear(XAxi_interfaces *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAxi_interfaces_WriteReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_ISR, Mask);
}

u32 XAxi_interfaces_InterruptGetEnabled(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAxi_interfaces_ReadReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_IER);
}

u32 XAxi_interfaces_InterruptGetStatus(XAxi_interfaces *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAxi_interfaces_ReadReg(InstancePtr->Axilites_BaseAddress, XAXI_INTERFACES_AXILITES_ADDR_ISR);
}

