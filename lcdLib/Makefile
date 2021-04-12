COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS 	= -L/opt/ti/msp430_gcc/include -L../lib
LDLFLAG1        = -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar


all: libLcd.a lcddemo.elf blink.elf

libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^

blink.elf: ${COMMON_OBJECTS} blinkMain.o stateMachines.o led.o buzzer.o switches.o p1_interrupt_handler.o wdInterruptHandler.o ../lib/libTimer.a font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	${CC} ${CFLAGS} ${LDFLAGS} ${LDFLAGS1} -o $@ $^

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h
lcdutils.o: lcdutils.c lcdutils.h
led.o: led.c led.h
buzzer.o: buzzer.h
switches.o: switches.h
wdInterruptHandler.o: stateMachines.h
stateMachines.o: led.h stateMachines.h buzzer.h switches.h

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

clean:
	rm -f libLcd.a *.o *.elf *~

lcddemo.elf: lcddemo.o libLcd.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer

lcddemo2.elf: lcddemo2.o libLcd.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer

load: lcddemo.elf
	msp430loader.sh $^

load2: lcddemo2.elf
	msp430loader.sh $^

load3: blink.elf
	msp430loader.sh blink.elf
