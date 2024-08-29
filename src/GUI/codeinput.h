#ifndef CODEINPUT_H
#define CODEINPUT_H

#include <QPlainTextEdit>

class CodeInput : public QPlainTextEdit
{
    Q_OBJECT

public:
    explicit CodeInput(QWidget *parent = nullptr);
    ~CodeInput() override;

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void contextMenuEvent(QContextMenuEvent *e) override;
};


#endif // CODEINPUT_H
