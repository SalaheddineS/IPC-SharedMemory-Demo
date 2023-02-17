#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    HANDLE myHandle;
    int *ptr = NULL;
    int i=1000;
    myHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, "MySharedMemory");
    if (myHandle == NULL)
    {
        printf("OpenFileMapping failed with error %d)\n", GetLastError());
        exit(1);
    }
    ptr = (int *)MapViewOfFile(myHandle, FILE_MAP_ALL_ACCESS, 0, 0, 256);
    if (ptr == NULL)
    {
        printf("MapViewOfFile failed with error %d)\n", GetLastError());
        exit(1);
    }
    CopyMemory(ptr, &i, sizeof(int));
    
    UnmapViewOfFile(ptr);
    CloseHandle(myHandle);
}
