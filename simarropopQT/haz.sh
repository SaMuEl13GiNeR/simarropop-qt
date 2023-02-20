#!/bin/bash
make clean
rm *.pro
qmake -project
fichero=$( ls *.pro )
echo "QT += widgets sql core network" >> $fichero
echo "LIBS += -lpq " >> $fichero
qmake
make

