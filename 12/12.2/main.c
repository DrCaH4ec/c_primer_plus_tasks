 // compile with pe12-2a.c
#include <stdio.h>
#include <errno.h>
#include "pe12-2a.h"
int main(void)
{
    int status = 0;
    int mode;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    if (scanf("%d", &mode) != 1) {
        status = -EINVAL;
        goto err;
    }

    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        if (scanf("%d", &mode) != 1) {
            status = -EINVAL;
            goto err;
        }
    }
err:
    printf("Done.\n");
    return status;
}
