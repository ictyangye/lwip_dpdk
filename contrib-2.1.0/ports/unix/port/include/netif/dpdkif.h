#ifndef LWIP_DPDKIF_H
#define LWIP_DPDKIF_H

#include "lwip/netif.h"

int init_dpdk(int argc, char** argv);
err_t dpdk_device_init(struct netif*);

#endif