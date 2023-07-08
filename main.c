#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "apn_manager.h"

int wsl_connect(APN_CONFIG apn)
{
    // Generate a random number
    int random_number = rand() % 100 + 1;

    // Check if the random number is greater than 50
    bool is_greater_than_50 = random_number > 50;

    // Print the result
    if (is_greater_than_50)
    {
        return 0;
    }
    return -1;
}

int main(int argc, char **argv)
{
    select_apn(&wsl_connect);

    return 0;
}