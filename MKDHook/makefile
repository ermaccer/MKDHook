EE_BIN = ../scripts/MKDHook.elf
EE_OBJS = main.o mkdeception.o ps2mem.o mkdplrinfo.o mkdhook.o mkdmenu.o

BASE_ADDRESS = 0x02020000
EE_LINKFILE = linkfile

EE_LDFLAGS = -Wl,--entry=init -Wl,-Map,../scripts/MKDHook.map -Wl,'--defsym=BASE_ADDRESS=$(BASE_ADDRESS)'

all: $(EE_BIN)

PS2SDK = ../external/ps2sdk/ps2sdk
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
