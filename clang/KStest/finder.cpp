#include "finder.h"
#include "ui_finder.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QHash>
#include <QMouseEvent>

finder::finder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::finder)
{
    ui->setupUi(this);
    ui->commit->setEnabled(false);
    ui->centralWidget->setMouseTracking(true);
    setMouseTracking(true);
}

finder::~finder()
{
    delete ui;
}



void finder::on_choosebtn1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                    tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }

        ui->lineEdit->setText(fileName);
        file.close();
    }
}

void finder::on_commit_clicked()
{
    // do the text diff;
    QString file1 = ui->lineEdit->text();
    QString file2 = ui->lineEdit_2->text();

    // backup the original files, rewrite the existed one
    if(QFile::exists(file1+".bak"))
    {
        QFile::remove(file1+".bak");
    }
    QFile::copy(file1, file1+".bak");

    if(QFile::exists(file2+".bak"))
    {
        QFile::remove(file2+".bak");
    }
    QFile::copy(file2, file2+".bak");

    // may try  Google's sparse_hash_set
    // now jusf a simple hash
    QHash<QString,int> hash;

    // choose the shorter one to build a hashmap
    QFile inputFile(file2);
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           QString line;
           while ( !in.atEnd() )
           {
              line = in.readLine();
              hash[line] = 1;
           }
        }
    inputFile.close();

    QFile f(file1);
    if(f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QString s;
        QTextStream t(&f);
        while(!t.atEnd())
        {
            QString line = t.readLine();
            if(hash.value(line) != 1)
                s.append(line + "\n");
            else
                hash[line] = 2;

        }
        f.resize(0);
        t << s;
        f.close();
    }


    // block for the second file
    QFile file(file2);
    if(file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QString s;
        QTextStream t(&file);
        while(!t.atEnd())
        {
            QString line = t.readLine();
            if(hash.value(line) != 2)
                s.append(line + "\n");
        }
        file.resize(0);
        t << s;
        file.close();
    }

}

void finder::on_choosebtn2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString());

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
            }

    ui->lineEdit_2->setText(fileName);

    file.close();
    }
}


// use the mouse move event to enable the process button
void finder::mouseMoveEvent(QMouseEvent *)
{
    if ((!ui->lineEdit->text().isEmpty()) && (!ui->lineEdit_2->text().isEmpty()))
        ui->commit->setEnabled(true);
    else
        ui->commit->setEnabled(false);
}
