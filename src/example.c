/*
 * libstatsdc
 * Copyright 2011 Mina Naguib
 * See the accompanying COPYING file for use and distribution legalese.
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <statsdc.h>

int main(int argc, char ** argv) {
	char *host = "localhost", *port = "8125";
	statsdc_t sdc;

	if (argc >= 2) host = argv[1];
	if (argc >= 3) port = argv[2];
	printf("Sending to statsd at %s:%s\n", host, port);

	sdc = statsdc_init(host, port);

	while (1) {
		statsdc_increment(sdc, "test.libstatsdc.increment");
		statsdc_update(sdc, "test.libstatsdc.sampled_increment", 1, 0.333);
		printf(".");
		fflush(stdout);
		sleep(1);
	}

	statsdc_free(sdc);

	return 0;
}
