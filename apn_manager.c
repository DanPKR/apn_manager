#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "apn_manager.h"

int select_apn(do_connection connect)
{
    printf("> Available APN: %ld \n", sizeof(APN_LIST) / sizeof(APN_CONFIG));
    for (size_t i = 0; i < sizeof(APN_LIST) / sizeof(APN_CONFIG); i++)
    {
        int ret = connect(APN_LIST[i]);
        printf("> Testing with: [%ld] %s \n", i, APN_LIST[i].apn);
        if (ret == 0)
        {
            int isConnected = _test_connection();
            if (isConnected == 0)
            {
                printf("> Connected with: %s \n", APN_LIST[i].apn);
                return 0;
            }
        }
    }
    return -1;
}

int _test_connection()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("Error al crear el socket");
        return -1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    inet_pton(AF_INET, "1.1.1.1", &(server.sin_addr));

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("Error al conectar al servidor");
        close(sock);
        return -1;
    }

    close(sock);
    return 0;
}