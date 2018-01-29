
OLD_SHELL := $(SHELL)
SHELL = $(warning [$@ ($^) ($?)])$(OLD_SHELL)

MCU = atxmega384c3
AVRDUDE_DEVICE = x384c3
CLOCK = 2000000
TARGET = dfu_bootloader
SRCDIR = common/services/usb/class/dfu_flip/device/bootloader
COMMONDIR = common
XMEGADIR = xmega
SRC = 
ASRC = 
OPT = s
BUILDDIR = _build

AS = avr-as
CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size --mcu=$(MCU)
AVRDUDE = avrdude

# Name of this Makefile (used for "make depend").
MAKEFILE = Makefile

# Debugging format.
# Native formats for AVR-GCC's -g are stabs [default], or dwarf-2.
# AVR (extended) COFF requires stabs, plus an avr-objcopy run.
DEBUG = stabs

# Compiler flag to set the C Standard level.
# c89   - "ANSI" C
# gnu89 - c89 plus GCC extensions
# c99   - ISO C99 standard (not yet fully implemented)
# gnu99 - c99 plus GCC extensions
CSTANDARD = -std=gnu99

# Place -D or -U options here
CDEFS = \
	-DF_CPU=$(CLOCK) \
	-DBOARD=DUMMY_BOARD \
	-DNO_LOCKBITS_DEF

CFLAGS = \
	-mmcu=$(MCU) \
	-save-temps=obj \
	-Os \

AFLAGS = \
	-x assembler-with-cpp

# Place -I options here
CINCS = \
	-I$(SRCDIR)/xmega/atxmega384c3/iar \
	-I$(SRCDIR)/xmega/conf \
	-I$(XMEGADIR)/boards \
	-I$(XMEGADIR)/drivers/cpu \
	-I$(XMEGADIR)/drivers/nvm \
	-I$(XMEGADIR)/utils \
	-I$(XMEGADIR)/utils/preprocessor \
	-I$(COMMONDIR)/utils \
	-I$(COMMONDIR)/boards \
	-I$(COMMONDIR)/services/clock \
	-I$(COMMONDIR)/services/isp/flip \
	-I$(COMMONDIR)/services/usb \
	-I$(COMMONDIR)/services/usb/udc \
	-I$(COMMONDIR)/services/usb/class/dfu_flip \
	-I$(COMMONDIR)/services/usb/class/dfu_flip/device \

SRC +=  \
	$(SRCDIR)/xmega/main.c \
	$(COMMONDIR)/services/usb/class/dfu_flip/device/udi_dfu_atmel.c \
	$(COMMONDIR)/services/usb/class/dfu_flip/device/udi_dfu_atmel_desc.c \
	$(COMMONDIR)/services/usb/udc/udc.c \
	$(COMMONDIR)/services/clock/xmega/sysclk.c \
	$(COMMONDIR)/services/isp/flip/xmega/isp.c \
	$(XMEGADIR)/drivers/nvm/nvm.c \
	$(XMEGADIR)/drivers/usb/usb_device.c \
	
ASRC += \
	$(XMEGADIR)/drivers/nvm/nvm_asm.s \
	$(XMEGADIR)/drivers/cpu/ccp.s \
#	$(COMMONDIR)/services/isp/flip/xmega/cstartup.s90 \

#$(notdir $(ASRC:.s=.o)) $(notdir $(ASRC:.s90=.o))
OBJS += $(SRC:%.c=$(BUILDDIR)/%.o)
OBJS += $(ASRC:%.s=$(BUILDDIR)/%.o)
$(warning ASRC = $(ASRC))
$(warning OBJS = $(OBJS))

all: $(BUILDDIR)/$(TARGET).hex
#all: _build/main.o

clean:
	rm -rf $(BUILDDIR)

$(BUILDDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CDEFS) $(CINCS) -c $< -o $@

$(BUILDDIR)/%.o: %.s
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(AFLAGS) $(CDEFS) $(CINCS) -c $< -o $@

$(BUILDDIR)/$(TARGET).hex: $(BUILDDIR)/$(TARGET).elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@
	$(SIZE) $@

$(BUILDDIR)/$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(CDEFS) -o $@ $(OBJS)
