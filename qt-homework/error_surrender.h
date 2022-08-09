#ifndef ERROR_SURRENDER_H
#define ERROR_SURRENDER_H

#include <QWidget>

namespace Ui {
class Error_surrender;
}

class Error_surrender : public QWidget
{
    Q_OBJECT

public:
    explicit Error_surrender(QWidget *parent = nullptr);
    ~Error_surrender();

private:
    Ui::Error_surrender *ui;
};

#endif // ERROR_SURRENDER_H
