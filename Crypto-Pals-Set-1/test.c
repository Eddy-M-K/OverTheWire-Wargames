#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(void)
{
    printf("The time is %s and the current line number is %d.", __TIME__, __LINE__);

    return 0;
}
