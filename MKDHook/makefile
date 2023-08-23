EE_BIN = ../scripts/MKDHook.elf
EE_OBJS = main.o\
reactions.o \
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
mkd\fx.o \
ps2mem.o character.o mkdhook.o mkdmenu.o stage.o mouse.o mips.o ladder.o moves.o \
generic.o \
generic_asm.o \
voice.o \
chess.o \
stages\acidbath.o \
stages\katakombs.o \
stages\darkprison.o \
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
characters\kitana.o \
characters\jax.o \
characters\dragonking.o \
characters\frost.o \
characters\blaze.o \
characters\shaokahn.o \
characters\goro.o \
characters\drahmin.o \
characters\sareena.o \
characters\quanchi.o \
characters\character_list.o \
misc\pselect.o \
misc\misc_anims.o \
misc\fatalityanims.o \
sound.o \
sound_bank.o \
pcsx2\rini.o \
pcsx2\inireader.o \
settings.o \
qs.o \


PS2_BUILD = 1

NEWLIB_NANO = 1
KERNEL_NOPATCH = 1


ifeq ($(PS2_BUILD), 1)
# PS2 0x9A0000
BASE_ADDRESS = 0x980000
else
# PC
BASE_ADDRESS = 0x02020000
endif

ifeq ($(PS2_BUILD), 1)
EE_LINKFILE = linkfile_ps2
else
EE_LINKFILE = linkfile
endif


EE_CFLAGS =  -fno-zero-initialized-in-bss  -O0

EE_LDFLAGS = -Wl,--entry=init -Wl,-Map,../scripts/MKDHook.map -Wl,'--defsym=BASE_ADDRESS=$(BASE_ADDRESS)' -ffunction-sections -Wl,--gc-sections -fdata-sections

all: $(EE_BIN)

PS2SDK = ../external/ps2sdk/ps2sdk
include $(PS2SDK)/samples/Makefile.pref

ifeq ($(PS2_BUILD), 1)
include eemakefile.eeglobal
else
include $(PS2SDK)/samples/Makefile.eeglobal
endif



