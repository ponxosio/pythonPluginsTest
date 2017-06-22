
QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_pluginscheck.cpp

debug {
    INCLUDEPATH += X:\utils\dll_debug\include
    LIBS += -L$$quote(X:\utils\dll_debug\bin) -lutils

    INCLUDEPATH += X:\commomModel\dll_debug\include
    LIBS += -L$$quote(X:\commomModel\dll_debug\bin) -lcommonModel

    INCLUDEPATH += X:\pythonPlugins\dll_debug\include
    LIBS += -L$$quote(X:\pythonPlugins\dll_debug\bin) -lpythonPlugins

    LIBS += -L$$quote(X:\libraries\boost_1_63_0\stage\lib) -lboost_python-vc140-mt-gd-1_63
}

!debug {
    INCLUDEPATH += X:\utils\dll_release\include
    LIBS += -L$$quote(X:\utils\dll_release\bin) -lutils

    INCLUDEPATH += X:\commomModel\dll_release\include
    LIBS += -L$$quote(X:\commomModel\dll_release\bin) -lcommonModel

    INCLUDEPATH += X:\pythonPlugins\dll_release\include
    LIBS += -L$$quote(X:\pythonPlugins\dll_release\bin) -lpythonPlugins

    LIBS += -L$$quote(X:\libraries\boost_1_63_0\stage\lib) -lboost_python-vc140-mt-1_63
}

INCLUDEPATH += X:\libraries\cereal-1.2.2\include
INCLUDEPATH += X:\libraries\json-2.1.1\src
INCLUDEPATH += X:\libraries\boost_1_63_0

INCLUDEPATH += X:\swipl\include
LIBS += -L$$quote(X:\swipl\bin) -llibswipl
LIBS += -L$$quote(X:\swipl\lib) -llibswipl

#python environment
INCLUDEPATH += C:\Python27\include
LIBS += -L$$quote(C:\Python27\libs)
