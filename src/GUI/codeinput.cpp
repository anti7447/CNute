#include "codeinput.h"
#include <QMenu>
#include <QPalette>
#include <QKeyEvent>
#include <QTextCursor>

CodeInput::CodeInput(QWidget *parent)
    : QPlainTextEdit(parent) {
    setTabStopDistance(40);
    setLineWrapMode(QPlainTextEdit::NoWrap);
    setGeometry(70, 80, 750, 450);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Text, Qt::white);
    setPalette(palette);
}

CodeInput::~CodeInput() { }

void CodeInput::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Up || e->key() == Qt::Key_Down) {
        QTextCursor cursor = textCursor();
        int currentBlockNumber = cursor.blockNumber();

        if (e->key() == Qt::Key_Up) {
            if (currentBlockNumber > 0) {
                cursor.movePosition(QTextCursor::PreviousBlock);
                cursor.movePosition(QTextCursor::EndOfBlock);
            }
        } else if (e->key() == Qt::Key_Down) {
            cursor.movePosition(QTextCursor::NextBlock);
            cursor.movePosition(QTextCursor::EndOfBlock);
        }

        setTextCursor(cursor);
    } else {
        QPlainTextEdit::keyPressEvent(e);
    }
}

void CodeInput::contextMenuEvent(QContextMenuEvent *e) {
    QMenu *menu = createStandardContextMenu();

    menu->exec(e->globalPos());
    delete menu;
}
