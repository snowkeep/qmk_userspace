
CONSOLE_ENABLE = no

AUDIO_ENABLE = no

NKRO_ENABLE = yes

COMBO_ENABLE = yes

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
KEY_OVERRIDE_ENABLE = yes

SRC += snowkeep-hd.c \
	 features/caps_word.c \
	 process_records.c \
	 sk-hd_overrides.c

INTROSPECTION_KEYMAP_C = sk-hd_combos.c

ifneq ($(filter $(strip $(KEYBOARD)), splitkb/halcyon/kyria/rev4),)
	include $(USER_PATH)/splitkb/rules.mk
endif
