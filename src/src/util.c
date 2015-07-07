#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "cmsis_os.h"
#include "main.h"

volatile bool debug_matching;

#ifdef USE_FREERTOS
void HAL_Delay(uint32_t Delay)
{
	osDelay(Delay);
}


uint32_t HAL_GetTick(void)
{
	return osKernelSysTick();
}


uint32_t sys_now(void)
{
	return osKernelSysTick();
}


uint32_t sys_jiffies(void)
{
	return osKernelSysTick();
}
#endif


/* dumps a blob data in hex to the console */
void dump(uint8_t *buf, int len)
{
	int i, offset;
	uint8_t *p;

	offset = 0;
	while (len) {
		printf("\t%3d:", offset);
		for (i=0, p=buf; i<((len < 16) ? len : 16); i++) {
			printf(" %02x", *p++);
		}

		printf("        ");
		for (i=0, p=buf; i<((len < 16) ? len : 16); i++) {
			printf("%c", (isprint(*p)) ? *p : '.');
			p++;
		}

		printf("\n");
		offset += i;
		len -= i;
	};

	printf("\n");
}

