#ifndef FINDER_H
#define FINDER_H

#include <QMainWindow>

namespace Ui {
class finder;
}

class finder : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit finder(QWidget *parent = 0);
    ~finder();

protected:
    void mouseMoveEvent(QMouseEvent *);
    
private slots:
    void on_commit_clicked();

    void on_choosebtn1_clicked();

    void on_choosebtn2_clicked();

private:
    Ui::finder *ui;
};

#endif // FINDER_H
