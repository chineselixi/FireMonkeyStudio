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

#ifndef QSCILEXERPKGBUILD_H
#define QSCILEXERPKGBUILD_H

#include <Qsci/qscilexerbash.h>
#include <Qsci/qsciabstractapis.h>

class PkgBuildAPI : public QsciAbstractAPIs {
    public:
        PkgBuildAPI(QsciLexer *lexer);
        void updateAutoCompletionList(const QStringList &context, QStringList &list);
        QStringList callTips(const QStringList &context, int commas, QsciScintilla::CallTipsStyle style, QList<int> &shifts);
};

class QsciLexerPkgBuild : public QsciLexerBash {
    Q_OBJECT
public:
    QsciLexerPkgBuild(QObject *parent);
    virtual const char *language () const { return "PkgBuild"; }
    virtual QString description(int style) const {Q_UNUSED(style); return "PkgBuild"; }
};

#endif // QSCILEXERPKGBUILD_H