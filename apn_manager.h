#ifndef APN_MANAGER_H
#define APN_MANAGER_H

// Estructura APN
typedef struct APN_CONFIG {
    char* apn;
    int mcc;
    int mnc;
} APN_CONFIG;

// Definicion de metodo abastracto para conectar la terminal
typedef int (*do_connection)(APN_CONFIG);

// Lista de APN soportados por el cliente;
static APN_CONFIG APN_LIST[] = {
    {"em",295,5},
    {"em",295,9},
    {"em",537,3},
    {"em",901,43},
    {"em",206,1},
    {"em",234,50},
    {"internet.abc.com",334,110},
    {"internet.movil.mx",334,110},
    {"ott.iot.attmex.mx",33,070},
    {"altanwifi",234,10},
    {"apnsim.com",234,10}
};

extern int select_apn(do_connection);
extern int _test_connection();

#endif