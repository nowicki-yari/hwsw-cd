# Makefile

RISCV_GNU_TOOLCHAIN_GIT_REVISION = 411d134
RISCV_GNU_TOOLCHAIN_INSTALL_PREFIX = /opt/riscv32
TOOLCHAIN_PREFIX = $(RISCV_GNU_TOOLCHAIN_INSTALL_PREFIX)i/bin/riscv32-unknown-elf-

PYTHON = /usr/bin/python3

# GCC_WARNS  = -Werror -Wall -Wextra -Wshadow -Wundef -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings
# GCC_WARNS += -Wredundant-decls -Wstrict-prototypes -Wmissing-prototypes -pedantic # -Wconversion
GCC_ARGS = -mcmodel=medlow

COMPRESSED_ISA = 

CFLAGS  = -Wall -Os --std=c99 -ffreestanding -nostdlib
LDFLAGS = --std=gnu99 -Wl,-Bstatic,-T,firmware.lds,-Map,firmware.map,--strip-debug -lgcc
ARCHITECTURE = rv32i$(subst C,c,$(COMPRESSED_ISA))

BUILDDIR = build
SOURCEDIR = src
TOOLS = tools

SOURCES = $(wildcard $(SOURCEDIR)/*.c)
SOURCES_A = $(wildcard $(SOURCEDIR)/*.S)
OBJECTS = $(patsubst $(SOURCEDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))
OBJECTS_A = $(patsubst $(SOURCEDIR)/%.S, $(BUILDDIR)/%.o, $(SOURCES_A))

BINARY = firmware.elf

RM = rm -rf
MKDIR = mkdir

.PHONY: all clean sizes setup

################################################################################

all: firmware.hex firmware.objdump

################################################################################

%.objdump: %.elf
	$(TOOLCHAIN_PREFIX)objdump -D $< > $@

%.bin: %.elf
	$(TOOLCHAIN_PREFIX)objcopy -O binary $< $@

%.hex: %.bin
	$(PYTHON) $(TOOLS)/makehex.py $^ 8196 > $@

# LINKING ######################################################################
$(BINARY): $(OBJECTS) $(OBJECTS_A)
	$(TOOLCHAIN_PREFIX)gcc -ffreestanding -nostdlib -o $@ $^ $(GCC_ARGS) $(LDFLAGS)

# COMPILING ####################################################################
$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(TOOLCHAIN_PREFIX)gcc -c -march=$(ARCHITECTURE) $(CFLAGS) $(GCC_WARNS) -o $@ $<

# MAIN STRUCTURE
$(BUILDDIR)/start.o: $(SOURCEDIR)/start.S
	$(TOOLCHAIN_PREFIX)gcc -c -march=$(ARCHITECTURE) $(CFLAGS)  $(GCC_WARNS) -o $@ $<


################################################################################

sizes: firmware.elf
	$(TOOLCHAIN_PREFIX)size $^

setup:
	$(MKDIR) -p $(BUILDDIR)

clean:
	$(RM) firmware*.elf firmware*.bin firmware*.hex firmware*.map firmware*.objdump
	$(RM) $(BINARY) $(OBJECTS) $(OBJECTS_A)

assignment1_Yari_Nowicki: src/assignment1_Yari_Nowicki.c src/print.c
	gcc -o assignment1_Yari_Nowicki src/print.c src/assignment1_Yari_Nowicki.c