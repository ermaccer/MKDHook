EE_BIN = ../scripts/MKDHook.elf
EE_OBJS = main.o\
scripthook.o \
mkd\core.o \
mkd\object.o \
mkd\camera.o \
mkd\input.o \
mkd\konquest.o \
mkd\screen.o \
mkd\string.o \
mkd\content.o \
mkd\script.o \
ps2mem.o character.o mkdhook.o mkdmenu.o stage.o mouse.o mips.o ladder.o moves.o \
stages\acidbath.o \
stages\katakombs.o \
characters\mkda_kano.o \
characters\mkda_mokap.o \
characters\mkda_blaze.o \
characters\mkda_raiden.o \
characters\mkda_kung_lao.o \
characters\subzero.o	\
characters\smoke.o \
characters\liukang.o \
characters\scorpion.o \
characters\baraka.o \
characters\ashrah.o \
characters\ermac.o \
characters\noob.o \
characters\sonya.o \
characters\character_list.o \
misc\pselect.o

BASE_ADDRESS = 0x02020000
EE_LINKFILE = linkfile

EE_LDFLAGS = -Wl,--entry=init -Wl,-Map,../scripts/MKDHook.map -Wl,'--defsym=BASE_ADDRESS=$(BASE_ADDRESS)'

all: $(EE_BIN)

PS2SDK = ../external/ps2sdk/ps2sdk
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
