#ifndef _UTIL_H_
#define _UTIL_H_

void dump(uint8_t *buf, int len);
char *trim(char *line);
char *expect(struct uart *uart, const char *tx, const char *want, int timeout);

#endif /* _UTIL_H_ */
