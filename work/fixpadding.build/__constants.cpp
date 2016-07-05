
#include "nuitka/prelude.hpp"

// Sentinel PyObject to be used for all our call iterator endings. It will
// become a PyCObject pointing to NULL. It's address is unique, and that's
// enough for us to use it as sentinel value.
PyObject *_sentinel_value = NULL;

PyObject *const_int_0;
PyObject *const_int_pos_1;
PyObject *const_str_empty;
PyObject *const_dict_empty;
PyObject *const_bytes_empty;
PyObject *const_tuple_empty;
PyObject *const_str_plain_end;
PyObject *const_str_plain_int;
PyObject *const_str_plain_len;
PyObject *const_str_plain_file;
PyObject *const_str_plain_iter;
PyObject *const_str_plain_join;
PyObject *const_str_plain_open;
PyObject *const_str_plain_repr;
PyObject *const_str_plain_send;
PyObject *const_str_plain_site;
PyObject *const_str_plain_type;
PyObject *const_str_plain_close;
PyObject *const_str_plain_print;
PyObject *const_str_plain_range;
PyObject *const_str_plain_throw;
PyObject *const_str_plain_tuple;
PyObject *const_str_plain_append;
PyObject *const_str_plain_docopt;
PyObject *const_str_plain___all__;
PyObject *const_str_plain___cmp__;
PyObject *const_str_plain___doc__;
PyObject *const_str_plain_compile;
PyObject *const_str_plain_inspect;
PyObject *const_str_plain_replace;
PyObject *const_str_plain___dict__;
PyObject *const_str_plain___exit__;
PyObject *const_str_plain___file__;
PyObject *const_str_plain___iter__;
PyObject *const_str_plain___main__;
PyObject *const_str_plain___name__;
PyObject *const_str_plain___path__;
PyObject *const_str_plain___class__;
PyObject *const_str_plain___enter__;
PyObject *const_str_plain___cached__;
PyObject *const_str_plain___import__;
PyObject *const_str_plain___loader__;
PyObject *const_str_plain___module__;
PyObject *const_str_plain___package__;
PyObject *const_str_plain___builtins__;
PyObject *const_str_plain___internal__;
PyObject *const_str_plain___metaclass__;
PyObject *const_str_digest_25731c733fd74e8333aa29126ce85686;
PyObject *const_str_digest_45e4dde2057b0bf276d6a84f4c917d27;
PyObject *const_str_digest_6fe42bc7767704653d0465c04f34143d;
PyObject *const_str_digest_7a3e3fef9f5b7ad28288683df8a19235;

#if defined(_WIN32) && defined(_NUITKA_EXE)
#include <Windows.h>
const unsigned char* constant_bin;
struct __initResourceConstants
{
    __initResourceConstants()
    {
        constant_bin = (const unsigned char*)LockResource(
            LoadResource(
                NULL,
                FindResource(NULL, MAKEINTRESOURCE(3), RT_RCDATA)
            )
        );
    }
} __initResourceConstants_static_initializer;
#else
extern "C" const unsigned char constant_bin[];
#endif

static void _createGlobalConstants( void )
{
    NUITKA_MAY_BE_UNUSED PyObject *exception_type, *exception_value;
    NUITKA_MAY_BE_UNUSED PyTracebackObject *exception_tb;

#ifdef _MSC_VER
    // Prevent unused warnings in case of simple programs, the attribute
    // NUITKA_MAY_BE_UNUSED doesn't work for MSVC.
    (void *)exception_type; (void *)exception_value; (void *)exception_tb;
#endif

    const_int_0 = PyLong_FromUnsignedLong( 0ul );
    const_int_pos_1 = PyLong_FromUnsignedLong( 1ul );
    const_str_empty = UNSTREAM_STRING( &constant_bin[ 0 ], 0, 0 );
    const_dict_empty = _PyDict_NewPresized( 0 );
    assert( PyDict_Size( const_dict_empty ) == 0 );
    const_bytes_empty = UNSTREAM_BYTES( &constant_bin[ 0 ], 0 );
    const_tuple_empty = PyTuple_New( 0 );
    const_str_plain_end = UNSTREAM_STRING( &constant_bin[ 1514 ], 3, 1 );
    const_str_plain_int = UNSTREAM_STRING( &constant_bin[ 807 ], 3, 1 );
    const_str_plain_len = UNSTREAM_STRING( &constant_bin[ 2209 ], 3, 1 );
    const_str_plain_file = UNSTREAM_STRING( &constant_bin[ 57 ], 4, 1 );
    const_str_plain_iter = UNSTREAM_STRING( &constant_bin[ 5162 ], 4, 1 );
    const_str_plain_join = UNSTREAM_STRING( &constant_bin[ 5166 ], 4, 1 );
    const_str_plain_open = UNSTREAM_STRING( &constant_bin[ 5170 ], 4, 1 );
    const_str_plain_repr = UNSTREAM_STRING( &constant_bin[ 865 ], 4, 1 );
    const_str_plain_send = UNSTREAM_STRING( &constant_bin[ 5174 ], 4, 1 );
    const_str_plain_site = UNSTREAM_STRING( &constant_bin[ 5178 ], 4, 1 );
    const_str_plain_type = UNSTREAM_STRING( &constant_bin[ 1354 ], 4, 1 );
    const_str_plain_close = UNSTREAM_STRING( &constant_bin[ 5182 ], 5, 1 );
    const_str_plain_print = UNSTREAM_STRING( &constant_bin[ 805 ], 5, 1 );
    const_str_plain_range = UNSTREAM_STRING( &constant_bin[ 5187 ], 5, 1 );
    const_str_plain_throw = UNSTREAM_STRING( &constant_bin[ 5192 ], 5, 1 );
    const_str_plain_tuple = UNSTREAM_STRING( &constant_bin[ 5197 ], 5, 1 );
    const_str_plain_append = UNSTREAM_STRING( &constant_bin[ 5202 ], 6, 1 );
    const_str_plain_docopt = UNSTREAM_STRING( &constant_bin[ 529 ], 6, 1 );
    const_str_plain___all__ = UNSTREAM_STRING( &constant_bin[ 5208 ], 7, 1 );
    const_str_plain___cmp__ = UNSTREAM_STRING( &constant_bin[ 5215 ], 7, 1 );
    const_str_plain___doc__ = UNSTREAM_STRING( &constant_bin[ 5222 ], 7, 1 );
    const_str_plain_compile = UNSTREAM_STRING( &constant_bin[ 5229 ], 7, 1 );
    const_str_plain_inspect = UNSTREAM_STRING( &constant_bin[ 5236 ], 7, 1 );
    const_str_plain_replace = UNSTREAM_STRING( &constant_bin[ 18 ], 7, 1 );
    const_str_plain___dict__ = UNSTREAM_STRING( &constant_bin[ 5243 ], 8, 1 );
    const_str_plain___exit__ = UNSTREAM_STRING( &constant_bin[ 5251 ], 8, 1 );
    const_str_plain___file__ = UNSTREAM_STRING( &constant_bin[ 5259 ], 8, 1 );
    const_str_plain___iter__ = UNSTREAM_STRING( &constant_bin[ 5267 ], 8, 1 );
    const_str_plain___main__ = UNSTREAM_STRING( &constant_bin[ 5275 ], 8, 1 );
    const_str_plain___name__ = UNSTREAM_STRING( &constant_bin[ 5283 ], 8, 1 );
    const_str_plain___path__ = UNSTREAM_STRING( &constant_bin[ 5291 ], 8, 1 );
    const_str_plain___class__ = UNSTREAM_STRING( &constant_bin[ 5299 ], 9, 1 );
    const_str_plain___enter__ = UNSTREAM_STRING( &constant_bin[ 5308 ], 9, 1 );
    const_str_plain___cached__ = UNSTREAM_STRING( &constant_bin[ 5317 ], 10, 1 );
    const_str_plain___import__ = UNSTREAM_STRING( &constant_bin[ 5327 ], 10, 1 );
    const_str_plain___loader__ = UNSTREAM_STRING( &constant_bin[ 5337 ], 10, 1 );
    const_str_plain___module__ = UNSTREAM_STRING( &constant_bin[ 5347 ], 10, 1 );
    const_str_plain___package__ = UNSTREAM_STRING( &constant_bin[ 5357 ], 11, 1 );
    const_str_plain___builtins__ = UNSTREAM_STRING( &constant_bin[ 5368 ], 12, 1 );
    const_str_plain___internal__ = UNSTREAM_STRING( &constant_bin[ 5380 ], 12, 1 );
    const_str_plain___metaclass__ = UNSTREAM_STRING( &constant_bin[ 5392 ], 13, 1 );
    const_str_digest_25731c733fd74e8333aa29126ce85686 = UNSTREAM_STRING( &constant_bin[ 5405 ], 2, 0 );
    const_str_digest_45e4dde2057b0bf276d6a84f4c917d27 = UNSTREAM_STRING( &constant_bin[ 2626 ], 7, 0 );
    const_str_digest_6fe42bc7767704653d0465c04f34143d = UNSTREAM_STRING( &constant_bin[ 5407 ], 46, 0 );
    const_str_digest_7a3e3fef9f5b7ad28288683df8a19235 = UNSTREAM_STRING( &constant_bin[ 5453 ], 22, 0 );

#if _NUITKA_EXE
    /* Set the "sys.executable" path to the original CPython executable. */
    PySys_SetObject(
        (char *)"executable",
        const_str_digest_7a3e3fef9f5b7ad28288683df8a19235
    );
#endif
}

// In debug mode we can check that the constants were not tampered with in any
// given moment. We typically do it at program exit, but we can add extra calls
// for sanity.
#ifndef __NUITKA_NO_ASSERT__
void checkGlobalConstants( void )
{

}
#endif


void createGlobalConstants( void )
{
    if ( _sentinel_value == NULL )
    {
#if PYTHON_VERSION < 300
        _sentinel_value = PyCObject_FromVoidPtr( NULL, NULL );
#else
        // The NULL value is not allowed for a capsule, so use something else.
        _sentinel_value = PyCapsule_New( (void *)27, "sentinel", NULL );
#endif
        assert( _sentinel_value );

        _createGlobalConstants();
    }
}
