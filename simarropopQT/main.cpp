#include <QApplication>
#include "mainwindow.h"


 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
  	  MainWindow * dialogo = new MainWindow();
  	  dialogo->show();

     return app.exec();
 }

