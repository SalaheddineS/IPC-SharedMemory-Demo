#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
  HANDLE myHandle;
  int *ptr = (int *)malloc(sizeof(int));
  char i;
  int x = 0;

  myHandle = CreateFileMapping(
      INVALID_HANDLE_VALUE,
      NULL,
      PAGE_READWRITE,
      0,
      256,
      "MySharedMemory");
  if (myHandle == NULL)
  {
    printf("Could not create file mapping object (%d).\n", GetLastError());
    exit(1);
  }
  ptr = (int *)MapViewOfFile(myHandle, FILE_MAP_ALL_ACCESS, 0, 0, 256);
  if (ptr == NULL)
  {
    printf("Could not map view of file (%d).\n", GetLastError());
    CloseHandle(myHandle);
    exit(1);
  }
  CopyMemory(ptr, &x, sizeof(int));
  for (;;)
  {
    printf("Enter space to continue \n");
    i = getch();
    if (i != ' ')
    {
      break;
    }
    printf("The value accessed by the pointer is: %d \n", *ptr);
    printf("The Adress of the variable in hex is: %p \n", ptr);
    x++;
  }
  UnmapViewOfFile(ptr);
  CloseHandle(myHandle);
}
