// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xvecdotproduct.h"

extern XVecdotproduct_Config XVecdotproduct_ConfigTable[];

XVecdotproduct_Config *XVecdotproduct_LookupConfig(u16 DeviceId) {
	XVecdotproduct_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XVECDOTPRODUCT_NUM_INSTANCES; Index++) {
		if (XVecdotproduct_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XVecdotproduct_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XVecdotproduct_Initialize(XVecdotproduct *InstancePtr, u16 DeviceId) {
	XVecdotproduct_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XVecdotproduct_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XVecdotproduct_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

