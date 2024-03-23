#include <QSqlQueryModel>
#include <QSqlQuery>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //  mydb = QSqlDatabase::addDatabase("QSQLITE");
    // mydb.setDatabaseName("C:/Users/Franz Sundiam/Documents/1 QT Projects/SQLiteTestDB/mySQLdatabase.db");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    connOpen();


    QSqlQuery qry(mydb); // Do NOT allocate on the heap

    qry.prepare("select * FROM tbl_bookings");
    qry.exec();
    model->setQuery(std::move(qry));
    ui->tableView->setModel(model);
    // connClose();
    // QSqlQuery qry = *new QSqlQuery (mydb);
    // qry.prepare("select * from tbl_bookings");

    //  qDebug()<<qry.exec()<<"debug";

    qDebug()<<(model->rowCount());
}





