#define PY_SSIZE_T_CLEAN

#include "Python.h"
#include <modsupport.h>
#include <object.h>
#include <longobject.h>
#include <sys/timeb.h>

//#include "xtime.h"

#if PY_MAJOR_VERSION >= 3
  #define MOD_ERROR_VAL NULL
  #define MOD_SUCCESS_VAL(val) val
  #define MOD_INIT(name) PyMODINIT_FUNC PyInit_##name(void)
  #define MOD_DEF(ob, name, doc, methods) \
          static struct PyModuleDef moduledef = { \
            PyModuleDef_HEAD_INIT, name, doc, -1, methods, NULL, NULL, NULL, NULL}; \
          ob = PyModule_Create(&moduledef);
#else
  #define MOD_ERROR_VAL
  #define MOD_SUCCESS_VAL(val)
  #define MOD_INIT(name) void init##name(void)
  #define MOD_DEF(ob, name, doc, methods) \
          ob = Py_InitModule3(name, methods, doc);
#endif

static PyObject *ErrorObject;
extern time_t parse(char *, struct timeb *);

/* ----------------------------------------------------- */

static char libgetdate_doc[] = "parses a given datetime expression into unix time via the 'getdate()' function.";

static PyObject *
libgetdate_getdate(PyObject *self /* Not used */, PyObject *args)
{
    time_t result;
    (void)self;
    char *buf = 0;
    if (!PyArg_ParseTuple(args, "s", &buf))
    {
        PyErr_SetString(ErrorObject, "invalid input type");
    	return MOD_ERROR_VAL;
    }
    result = parse(buf, NULL);
    if (result == -1)
    {
    	PyErr_SetString(ErrorObject, "invalid time expression");
        return NULL;
    }
	
	return PyLong_FromLong(result);
}

/* List of methods defined in the module */
static PyMethodDef libgetdate_methods[] = {
	{"getdate",	(PyCFunction)libgetdate_getdate, METH_VARARGS, "parse a datetime expression into a unix time or getdate.error on error"},
	{NULL,	 (PyCFunction)NULL, 0, NULL}		/* sentinel */
};

#ifdef PYTHON2

/* Initialization function for the module (*must* be called initlibgetdate) */

/*
static char getdate_module_documentation[] = 
"based on a lexer and a parser from the CVS source code in roughly 1997."
;
*/
PyMODINIT_FUNC
initlibgetdate(void)
{
	PyObject *m, *d;

	/* Create the module and add the functions */
	m = Py_InitModule("libgetdate", libgetdate_methods); /*
		getdate_module_documentation);*/ /* ,
		(PyObject*)NULL,PYTHON_API_VERSION); */
	if (m == NULL)
	{
		return;
	}

	/* Add some symbolic constants to the module */
	d = PyModule_GetDict(m);
	ErrorObject = PyString_FromString("getdate.error");
	PyDict_SetItemString(d, "error", ErrorObject);
	PyDict_SetItemString(d, "version", PyString_FromString("20200421-1");

	/* XXXX Add constants here */
	
	/* Check for errors */
	if (PyErr_Occurred())
		Py_FatalError("can't initialize module getdate");
}
#else

#if 0
static struct PyModuleDef libgetdatemoddef =
{
    PyModuleDef_HEAD_INIT,
    "libgetdate", /* name of module */
    libgetdate_doc,          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    libgetdate_methods,
    NULL, /* m_slots */
    NULL, /* m_traverse */
    NULL, /* m_clear */
    NULL /* m_free */
};
#endif

/*
static char getdate_module_documentation[] = 
"based on a lexer and a parser from the CVS source code circa 1997."
;
*/

/*

MOD_INIT(_zope_proxy_proxy)
{
    PyObject *m;

    MOD_DEF(m, "_zope_proxy_proxy", module___doc__,
            module_functions)

    if (m == NULL)
        return MOD_ERROR_VAL;

    if (empty_tuple == NULL)
        empty_tuple = PyTuple_New(0);

    ProxyType.tp_free = _PyObject_GC_Del;

    if (PyType_Ready(&ProxyType) < 0)
        return MOD_ERROR_VAL;

    Py_INCREF(&ProxyType);
    PyModule_AddObject(m, "ProxyBase", (PyObject *)&ProxyType);

    if (api_object == NULL) {
        api_object = PyCObject_FromVoidPtr(&wrapper_capi, NULL);
        if (api_object == NULL)
        return MOD_ERROR_VAL;
    }
    Py_INCREF(api_object);
    PyModule_AddObject(m, "_CAPI", api_object);

    return MOD_SUCCESS_VAL(m);

}
*/

static PyObject *ErrorObject;

MOD_INIT(libgetdate)
{
	PyObject *m;

	MOD_DEF(m, "_libgetdate", libgetdate_doc, libgetdate_methods)
	if (m == NULL)
	{
            return MOD_ERROR_VAL;
        }

/*
	m = PyModule_Create(&libgetdatemoddef);
	if (m == NULL)
	{
		return NULL;
	}
*/
	ErrorObject = PyErr_NewException("getdate.error", NULL, NULL);
	Py_XINCREF(ErrorObject);
	if (PyModule_AddObject(m, "error", ErrorObject) < 0)
	{
        	Py_XDECREF(ErrorObject);
	        Py_CLEAR(ErrorObject);
	        Py_DECREF(m);
	        return MOD_ERROR_VAL;
	}
	return MOD_SUCCESS_VAL(m);
}
#endif
