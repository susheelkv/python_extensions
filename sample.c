#include <Python.h>

/************************************/
/* ex1	                 			*/
/************************************/
int 
ex1 (int n)
{
	return n*10;
}

/************************************/
/* ex2                   			*/
/************************************/
int 
ex2 (int n1, 
     int n2)
{
	return n1*n2;
}

/************************************/
/* ex3                   			*/
/************************************/
char
ex3 (char s)
{
	return s;
}

/************************************/
/* ex4                   			*/
/************************************/
const char *
ex4 (const char *s)
{
	return s;
}

/************************************/
/* ex5                   			*/
/************************************/
const char *
ex5 (const char *s, int n)
{
    printf ("this is just a test\n");
	return s;
}

/************************************/
/* Wrapper for ex1 				    */
/************************************/
static PyObject *
wrap_ex1 (PyObject *self,
          PyObject *args)
{
	int n, result;
	if (!PyArg_ParseTuple (args, "i", &n))
	{
		return NULL;
	}
	result = ex1 (n);
	return Py_BuildValue ("i", result);
}

/************************************/
/* Wrapper for ex2      			*/
/************************************/
static PyObject *
wrap_ex2 (PyObject *self, 
          PyObject *args)
{
	int n1, n2, result;

	if (!PyArg_ParseTuple (args, "ii", &n1, &n2))
	{
		return NULL;
	}
	result = ex2 (n1, n2);
	return Py_BuildValue ("i", result);
}

/************************************/
/* Wrapper for ex3      			*/
/************************************/
static PyObject *
wrap_ex3 (PyObject *self, 
          PyObject *args)
{
    char ch;
    char result;

	if (!PyArg_ParseTuple (args, "c", &ch))
	{
		return NULL;
	}
	result = ex3 (ch);
	return Py_BuildValue ("c", result);
}

/************************************/
/* Wrapper for ex4      			*/
/************************************/
static PyObject *
wrap_ex4 (PyObject *self, 
          PyObject *args)
{
    const char *str;
    const char *result;

	if (!PyArg_ParseTuple (args, "s", &str))
	{
		return NULL;
	}
	result = ex4 (str);
	return Py_BuildValue ("s", result);
}

/************************************/
/* Wrapper for ex5      			*/
/************************************/
static PyObject *
wrap_ex5 (PyObject *self, 
          PyObject *args)
{
    const char *str;
    const char *result;
    int n;

	if (!PyArg_ParseTuple (args, "is", &n, &str))
	{
		return NULL;
	}
	result = ex5 (str, n);
	return Py_BuildValue ("s", result);
}

/************************************/
/* Function Table					*/
/************************************/
static PyMethodDef exampleMethods [] = {
	{"ex1",  wrap_ex1, 1},
	{"ex2",  wrap_ex2, 2},
	{"ex3",  wrap_ex3, 1},
	{"ex4",  wrap_ex4, 1},
	{"ex5",  wrap_ex5, 1},
	{NULL, NULL}
};

void initexample ()
{
	PyObject *m;
	m = Py_InitModule ("example", exampleMethods);
}
