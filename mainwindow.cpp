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

    qry.prepare("select * FROM bookings");
    qry.exec();
    model->setQuery(std::move(qry));
    ui->tableView->setModel(model);
    connClose();


    QSqlQueryModel *newmodel = new QSqlQueryModel();
    connOpen();


    QSqlQuery new_qry(mydb); // Do NOT allocate on the heap

    new_qry.prepare("select passengerid FROM bookings");
    new_qry.exec();
    newmodel->setQuery(std::move(new_qry));
    ui->comboBox->setModel(newmodel);
    connClose();



    // QSqlQuery qry = *new QSqlQuery (mydb);
    // qry.prepare("select * from tbl_bookings");

    //  qDebug()<<qry.exec()<<"debug";

    qDebug()<<(model->rowCount());
}






void MainWindow::on_delete_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    connOpen();


    QSqlQuery qry(mydb); // Do NOT allocate on the heap

    qry.prepare("DELETE * FROM bookings");
    qry.exec();
    model->setQuery(std::move(qry));
    ui->tableView->setModel(model);
    connClose();

    qDebug()<<(model->rowCount());

}


void MainWindow::on_delete_3_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    connOpen();


    QSqlQuery qry(mydb); // Do NOT allocate on the heap

    qry.prepare("select passengerid FROM bookings");
    qry.exec();
    model->setQuery(std::move(qry));
    ui->comboBox->setModel(model);
    connClose();
    // QSqlQuery qry = *new QSqlQuery (mydb);
    // qry.prepare("select * from tbl_bookings");

    //  qDebug()<<qry.exec()<<"debug";

    qDebug()<<(model->rowCount());
}

