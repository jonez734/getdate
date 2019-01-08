#include "Python.h"
#include "xtime.h"

static PyObject *ErrorObject;
extern time_t interpretdateexpression(char *, struct timeb *);

/* ----------------------------------------------------- */

/*
static char getdate_getdate__doc__[] =
""
;
*/
static PyObject *
getdate_getdate(PyObject *self /* Not used */, PyObject *args)
{
	time_t result;
	(void)self;
    char *buf = 0;
    if (!PyArg_ParseTuple(args, "s", &buf))
    {
    	return NULL;
    }
    result = interpretdateexpression(buf, NULL);
    if (result == -1)
    {
    	PyErr_SetString(ErrorObject, "invalid time expression");
        return NULL;
	}
	
	return PyLong_FromLong(result);
}

/* List of methods defined in the module */

static PyMethodDef getdate_methods[] = {
	{"getdate",	(PyCFunction)getdate_getdate, METH_VARARGS, "parse a time expression"},
	{NULL,	 (PyCFunction)NULL, 0, NULL}		/* sentinel */
};


/* Initialization function for the module (*must* be called init_getdate) */

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
	m = Py_InitModule("libgetdate", getdate_methods); /*
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

	/* XXXX Add constants here */
	
	/* Check for errors */
	if (PyErr_Occurred())
		Py_FatalError("can't initialize module getdate");
}

