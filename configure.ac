AC_INIT(cpa,1.0)
 
AM_INIT_AUTOMAKE
 
#AM_CONFIG_HEADER([config.h])
#AC_CONFIG_HEADERS([config.h])
 
CFLAGS=" $CFLAGS -g"
 
LDFLAGS=" $LDFLAGS -g"
 
# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
 
# Checks for header files.
AC_HEADER_STDC
 
AC_CHECK_HEADERS([\
        stddef.h \
stdio.h\
dirent.h\
stdlib.h\
sys/stat.h\
sys/types.h\
sys/stat.h\
unistd.h\
string.h\
sys/stat.h\
sys/types.h\
sys/stat.h\
])
# Checks for typedefs, structures, and compiler characteristics.
 
# Checks for library functions.
AC_PROG_GCC_TRADITIONAL
AC_CHECK_FUNCS([readdir strcat strlen free calloc fopen fread fwrite ])
 
AC_PATH_PROG(cpapath, cpa)
AC_OUTPUT([Makefile ])
 
echo
echo $PACKAGE $VERSION
echo
