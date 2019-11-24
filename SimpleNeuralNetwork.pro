TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    inputneuron.h \
    inputvalue.h \
    neuron.h \
    neuronelinks.h \
    simpleneuralnetwork.h \
    transition.h

SOURCES += \
        inputneuron.cpp \
        inputvalue.cpp \
        main.cpp \
        neuron.cpp \
        neuronelinks.cpp \
        simpleneuralnetwork.cpp \
        transition.cpp
