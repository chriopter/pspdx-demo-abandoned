TARGET = pspdx-demo-abandoned
OBJS = main.o

INCDIR =
CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =
LIBS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = PSPDX Abandoned Demo
PSP_EBOOT_ICON = media/xmb/ICON0.PNG
PSP_EBOOT_PIC1 = media/xmb/PIC1.PNG
PSP_EBOOT_ICON1 = media/xmb/ICON1.PMF
PSP_EBOOT_SND0 = media/xmb/SND0.AT3

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
