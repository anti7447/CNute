#include "codeinput.h"
#include <QMenu>

CodeInput::CodeInput(QWidget *parent)
    : QPlainTextEdit(parent) {
    setTabStopDistance(40);
    setLineWrapMode(QPlainTextEdit::NoWrap);
    setGeometry(70, 80, 750, 450);
}

CodeInput::~CodeInput() { }

void CodeInput::keyPressEvent(QKeyEvent *e) {
    QPlainTextEdit::keyPressEvent(e);
}

void CodeInput::contextMenuEvent(QContextMenuEvent *e) {
    QMenu *menu = createStandardContextMenu();

    menu->exec(e->globalPos());
    delete menu;
}
