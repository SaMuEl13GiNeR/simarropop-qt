
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"

#include <QVector>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QMainWindow>
#include "dlogin.h"
#include "database.h"
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QMenuBar>
#include <QAction>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QByteArray>
#include <QModelIndex>
#include <QAbstractTableModel>
#include <QTableView>
#include "model/valoracion.h"
#include "model/articulo.h"
#include "model/usuario.h"
#include "controller/valoracioncontroller.h"
#include "controller/articulocontroller.h"
#include "controller/usuariocontroller.h"
#include "modelotabla/modelotablavaloracion.h"
#include "modelotabla/modelotablaarticulo.h"
#include "modelotabla/modelotablausuario.h"
#include "dialogos/dvaloracioneditar.h"
#include "dialogos/darticuloeditar.h"
#include "dialogos/dusuario.h"



class MainWindow : public QMainWindow, public Ui::MainWindow {
Q_OBJECT

public:
	MainWindow(QWidget *parent = NULL);
	QTableView *tablaValoracion;
	ModeloTablaValoracion *modeloTablaValoracion;
	ValoracionController *valCtrl;
	void crearTablaValoracion();
	QVector <Valoracion*> listaValoracion;
	DValoracionEditar *dValoracionEditar;
	
	QTableView *tablaArticulo;
	ModeloTablaArticulo *modeloTablaArticulo;
	ArticuloController *artCtrl;
	void crearTablaArticulo();
	QVector <Articulo*> listaArticulo;
	DArticuloEditar *dArticuloEditar;
	
	QTableView *tablaUsuario;
	ModeloTablaUsuario *modeloTablaUsuario;
	UsuarioController *usuCtrl;
	void crearTablaUsuario();
	QVector <Usuario*> listaUsuario;
	DUsuario *dUsuario;
	
	void crearMenus();
	void crearActions();
	QAction *accionInsertUsuario,*accionInsertArticulo,*accionInsertValoracion;

public slots:
	void slotDialogoValoracion(const QModelIndex &);
	void slotPeticionValoracionTerminada();
	void slotDialogoValoracionInsertar();
	void slotDialogoValoracionFinalizado(int );
	
	
	void slotDialogoArticulo(const QModelIndex &);
	void slotPeticionArticuloTerminada();
	void slotDialogoArticuloInsertar();
	void slotDialogoArticuloFinalizado(int );
	
	
	void slotDialogoUsuario(const QModelIndex &);
	void slotPeticionUsuarioTerminada();
	void slotDialogoUsuarioInsertar();
	void slotDialogoUsuarioFinalizado(int );
	
	void slotActualizarTablas();

};

#endif 
