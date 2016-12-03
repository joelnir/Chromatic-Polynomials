QT += widgets
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += *.cpp

HEADERS += *.h

QMAKE_CXXFLAGS += -std=c++11

# Copies the given files to the destination directory
defineTest(copyToDestdir) {
    files = $$1

    for(FILE, files) {
        DDIR = $$OUT_PWD

        # Replace slashes in paths with backslashes for Windows
        win32:FILE ~= s,/,\\,g
        win32:DDIR ~= s,/,\\,g

        !win32 {
            QMAKE_POST_LINK += cp -r '"'$$FILE'"' '"'$$DDIR'"' $$escape_expand(\\n\\t)
        }
        win32 {
            QMAKE_POST_LINK += $$quote(xcopy '"'$$FILE'"' '"'$$DDIR'"' /e /y $$escape_expand(\\n\\t))
        }
    }

    export(QMAKE_POST_LINK)
}
!win32 {
    copyToDestdir($$files($$PWD/res/*))
}
win32 {
    copyToDestdir($$PWD/res)
}
macx {
    cache()
}

#
# Delete build directory to force re-moving files
#

DISTFILES += \
    res/g1.txt \
    res/g2.txt \
    res/g3.txt \
    res/g4.txt \
    res/g5.txt
