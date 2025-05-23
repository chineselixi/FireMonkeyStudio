/*
 *   Sqriptor text editor for Qt5
 *   Copyright 2021 by Thomas Lübking <thomas.luebking@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef QSCILEXERJOURNAL_H
#define QSCILEXERJOURNAL_H

#include <Qsci/qscilexercustom.h>

class QsciLexerJournal : public QsciLexerCustom {
    Q_OBJECT
public:
    QsciLexerJournal(QObject *parent);
    void updateColors();
    virtual void styleText (int start, int end);
    virtual const char *language () const { return "Journal"; }
    virtual QString description(int style) const {Q_UNUSED(style); return "Journal"; }
};

#endif // QSCILEXERJOURNAL_H