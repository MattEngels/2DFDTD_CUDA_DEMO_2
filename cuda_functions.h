#include "parameters.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "grid_2d.h"
#include <stdio.h>

void update_all_fields_CUDA();
void resetBeforeExit();
void deviceSyncAfterKernelLaunch();
void pickGPU(int gpuid);
void checkErrorAfterKernelLaunch();
void initializeGlobalDevicePointers();
int copyTMzArraysToDevice();
bool copyFieldSnapshotsFromDevice();
bool deallocateCudaArrays();			// used to cudaFree() all device arrays
__global__ void HxHyUpdate_Kernel(double *dHx, double *dChxh, double *dChxe, double *dHy, double *dChyh, double *dChye, double *dEz, int M, int N);
__global__ void EzUpdate2D_Kernel(double *dEz, double *dCezh, double *dCeze, float *dImEz, double *dHx, double *dHy, int DIM, int time);

