#!/bin/bash
make clean
rm *.pro
qmake -project
fichero=$( ls *.pro )
echo "QT += widgets sql core" >> $fichero
echo "LIBS += -lpq" >> $fichero
echo "QT += network" >> $fichero
qmake
make

