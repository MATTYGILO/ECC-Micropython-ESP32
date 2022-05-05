// Include MicroPython API.
#include "py/runtime.h"
#include "ecc.h"

// uint8_t == byte

// This is the function which will be called from Python as microecc.encrypt_key(a, b).
// uint8_t * input, unsigned size_input, uint8_t * extern_pubkey, uint8_t * output
STATIC mp_obj_t encrypt_key(mp_obj_t input, mp_obj_t size_input, mp_obj_t extern_pubkey, mp_obj_t output) {
    // Extract the ints from the micropython input objects.

    char key_string = mp_obj_get_type_str(input)
    int size_input_int = mp_obj_get_int(size_input);
    char extern_pubkey_string = mp_obj_get_type_str(extern_pubkey)
    char wrapped_key_string = mp_obj_get_type_str(output)

    // Convert from string to key string array
    uint8_t key_string_array[key_string.length()];
    key_string.toCharArray(key_string_array, key_string.length())

    // Convert from string to key string array
    uint8_t extern_pubkey_string_array[extern_pubkey_string.length()];
    extern_pubkey_string.toCharArray(extern_pubkey_string_array, extern_pubkey_string.length())

    // Convert from string to key string array
    uint8_t wrapped_key_string_array[wrapped_key_string.length()];
    wrapped_key_string.toCharArray(wrapped_key_string_array, wrapped_key_string.length())

    // Calculate the addition and convert to MicroPython object.
    // return mp_obj_new_int(a + b);

    //    uint8_t * input, unsigned size_input, uint8_t * extern_pubkey, uint8_t * output
    // key, 32, extern_pubkey, wraped_key
    return ECIES_encrypt_key(key_string_array, size_input_int, extern_pubkey_string_array, wrapped_key_string_array);
}
// Define a Python reference to the function above.
STATIC MP_DEFINE_CONST_FUN_OBJ_2(encrypt_key_obj, encrypt_key);

// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t example_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_microecc) },
    { MP_ROM_QSTR(MP_QSTR_add_ints), MP_ROM_PTR(&encrypt_key_obj) },
};

STATIC MP_DEFINE_CONST_DICT(example_module_globals, example_module_globals_table);

// Define module object.
const mp_obj_module_t example_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&example_module_globals,
};

// Register the module to make it available in Python.
// Note: the "1" in the third argument means this module is always enabled.
// This "1" can be optionally replaced with a macro like MODULE_microecc_ENABLED
// which can then be used to conditionally enable this module.
MP_REGISTER_MODULE(MP_QSTR_microecc, example_user_cmodule, 1);