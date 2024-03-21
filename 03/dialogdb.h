#ifndef DIALOGDB_H
#define DIALOGDB_H

#include <QDialog>

namespace Ui {
class DialogDb;
}

class DialogDb : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDb(QWidget *parent = nullptr);
    ~DialogDb();

private:
    Ui::DialogDb *ui;
};

#endif // DIALOGDB_H
