#include "codeinput.h"
#include "syntaxhighlighter.h"
#include <QMenu>
#include <QPalette>
#include <QKeyEvent>
#include <QTextCursor>
#include <QFont>

CodeInput::CodeInput(QWidget *parent)
    : QPlainTextEdit(parent) {
    setTabStopDistance(40);
    setLineWrapMode(QPlainTextEdit::NoWrap);
    setGeometry(70, 80, 750, 450);
    
    // Enable monospace
    QFont monospace("Monospace");
    setFont(monospace);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Text, Qt::white);
    setPalette(palette);

    // Создаем и присоединяем SyntaxHighlighter
    SyntaxHighlighter *highlighter = new SyntaxHighlighter(document());
}

CodeInput::~CodeInput() { }

void CodeInput::keyPressEvent(QKeyEvent *e) {

    // ===============================================

    if (e->key() == Qt::Key_Up) {
        QTextCursor cursor = textCursor();
        int currentBlockNumber = cursor.blockNumber();

        if (currentBlockNumber == 0)
            cursor.movePosition(QTextCursor::StartOfLine);
        
        else
            cursor.movePosition(QTextCursor::Up);

        setTextCursor(cursor);

    // ===============================================

    } else if (e->key() == Qt::Key_Down) {
        QTextCursor cursor = textCursor();
        int currentBlockNumber = cursor.blockNumber();
        int endBlockNumber = blockCount() - 1;

        if (currentBlockNumber == endBlockNumber)
            cursor.movePosition(QTextCursor::EndOfLine);
        
        else
            cursor.movePosition(QTextCursor::Down);

        setTextCursor(cursor);
    
    // ================================================

    } else if (e->key() == Qt::Key_Tab) {

        QString spaces = "    ";
        insertPlainText(spaces);
    
    } else {
        QPlainTextEdit::keyPressEvent(e);
    }
}

void CodeInput::contextMenuEvent(QContextMenuEvent *e) {
    QMenu *menu = createStandardContextMenu();

    menu->exec(e->globalPos());
    delete menu;
}
