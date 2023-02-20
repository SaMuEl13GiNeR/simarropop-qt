
#include "dlogin.h"
#include <QDebug>

DLogin::DLogin(QWidget *parent): QDialog(parent){
		setupUi(this);
connect(btnLogin,SIGNAL(clicked()),
			this,SLOT(slotAceptar()));
	
}


void DLogin::slotAceptar(){
	MainWindow *main = new MainWindow();
	main->show();
	accept();

}

