
QTINCLUDE= -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtGui -I/usr/include

all: finder

moc_finder.cpp: finder.h
	moc -o moc_finder.cpp  finder.h

ui_finder.h: finder.ui
	uic -o ui_finder.h finder.ui

finder: main.cpp finder.cpp moc_finder.cpp ui_finder.h
	g++ -o finder $(QTINCLUDE) -L/usr/lib $< -lQtCore -lQtGui -lpthread 
