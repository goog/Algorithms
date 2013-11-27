/********************************************************************************
** Form generated from reading UI file 'finder.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDER_H
#define UI_FINDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_finder
{
public:
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *choosebtn1;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *choosebtn2;
    QPushButton *commit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *finder)
    {
        if (finder->objectName().isEmpty())
            finder->setObjectName(QStringLiteral("finder"));
        finder->resize(418, 241);
        centralWidget = new QWidget(finder);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        choosebtn1 = new QPushButton(centralWidget);
        choosebtn1->setObjectName(QStringLiteral("choosebtn1"));
        sizePolicy.setHeightForWidth(choosebtn1->sizePolicy().hasHeightForWidth());
        choosebtn1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(choosebtn1, 0, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        choosebtn2 = new QPushButton(centralWidget);
        choosebtn2->setObjectName(QStringLiteral("choosebtn2"));
        sizePolicy.setHeightForWidth(choosebtn2->sizePolicy().hasHeightForWidth());
        choosebtn2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(choosebtn2, 1, 2, 1, 1);

        commit = new QPushButton(centralWidget);
        commit->setObjectName(QStringLiteral("commit"));
        sizePolicy.setHeightForWidth(commit->sizePolicy().hasHeightForWidth());
        commit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(commit, 2, 2, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout);

        finder->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(finder);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 418, 25));
        finder->setMenuBar(menuBar);
        mainToolBar = new QToolBar(finder);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        finder->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(finder);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        finder->setStatusBar(statusBar);

        retranslateUi(finder);

        QMetaObject::connectSlotsByName(finder);
    } // setupUi

    void retranslateUi(QMainWindow *finder)
    {
        finder->setWindowTitle(QApplication::translate("finder", "Reject Duplicates", 0));
        label->setText(QApplication::translate("finder", "File1", 0));
        choosebtn1->setText(QApplication::translate("finder", "Choose", 0));
        label_2->setText(QApplication::translate("finder", "File2", 0));
        choosebtn2->setText(QApplication::translate("finder", "Choose", 0));
        commit->setText(QApplication::translate("finder", "Process", 0));
    } // retranslateUi

};

namespace Ui {
    class finder: public Ui_finder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDER_H
