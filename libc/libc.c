#include <Python.h>
#include <stdio.h>

PyObject *add(PyObject *self, PyObject *args) {
    double x;
    double y;
    PyArg_ParseTuple(args, "dd", &x, &y);
    return PyFloat_FromDouble(x + y);
}

static PyModuleDef methods[] = {
    {"add", add, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef clib = {
    PyModuleDef_HEAD_INIT,
    "__name__",
    "__doc__",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_libc() {
    printf("Hello libc\n");
    return PyModule_Create(&clib);
}

// gcc libc.c -shared -o libc.so -I/usr/local/include/python3.11 -fPIC
