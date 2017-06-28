CFLAGS = -I/usr/local/include/
CC = clang

librtlsdr.0.dylib: fakertl.c
	${CC} -dynamiclib -std=gnu99 ${CFLAGS} fakertl.c -current_version 999.0 -compatibility_version 0.0.0 -fvisibility=hidden -o librtlsdr.0.dylib
