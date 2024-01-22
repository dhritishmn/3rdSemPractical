
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // if working on Linux

    system("echo \"The kernal version is: \"");
    system("cat /proc/sys/kernel/osrelease");
    system("echo \"\nCPU Info: \"");
    system("cat /proc/cpuinfo | awk '/processor|model/{print}'");
    printf("\n");
    printf("\n");

    // if working on macOS

    printf("The kernel version is: ");
    fflush(stdout); // Flush the output buffer
    system("uname -a"); // Use uname to get kernel version
    printf("\nCPU Info: \n");
    system("sysctl -n machdep.cpu.brand_string"); // Use sysctl to get CPU info

    return 0;
}