<<<<<<< HEAD:keyboards/handwired/onekey/teensy_32/rules.mk
EEPROM_DRIVER = transient
=======
# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
OPT_DEFS += -DNO_USB_STARTUP_CHECK -DENABLE_FACTORY_TEST

SRC += matrix.c

include keyboards/keychron/bluetooth/bluetooth.mk


>>>>>>> c8b2b237b4ef09765e48cbb5c1fdb0afd164289f:keyboards/keychron/k4_pro/rules.mk
