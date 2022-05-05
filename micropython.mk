EXAMPLE_MOD_DIR := $(USERMOD_DIR)

# Add all C files to SRC_USERMOD.
SRC_USERMOD += $(EXAMPLE_MOD_DIR)/microecc.c
SRC_USERMOD += $(EXAMPLE_MOD_DIR)/ecc.c
SRC_USERMOD += $(EXAMPLE_MOD_DIR)/bmp180.c
SRC_USERMOD += $(EXAMPLE_MOD_DIR)/uECC.c

# We can add our module folder to include paths if needed
# This is not actually needed in this example.
CFLAGS_USERMOD += -I$(EXAMPLE_MOD_DIR)
CEXAMPLE_MOD_DIR := $(USERMOD_DIR)