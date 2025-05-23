// config.h

#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QSize>
#include <QFont>
#include <QStringList>
#include "ColorConfig.h"

class Config : public QObject
{
    Q_OBJECT
    Q_PROPERTY(SizeMode sizeMode READ sizeMode WRITE setSizeMode NOTIFY sizeModeChanged)
    Q_PROPERTY(QSize size READ size WRITE setSize NOTIFY sizeChanged)
    Q_PROPERTY(QFont font READ font WRITE setFont NOTIFY fontChanged)
    Q_PROPERTY(bool wrapWords READ wrapWords WRITE setWrapWords NOTIFY wrapWordsChanged)
    Q_PROPERTY(bool wrapIndicator READ wrapIndicator WRITE setWrapIndicator NOTIFY wrapIndicatorChanged)
    Q_PROPERTY(int wrapIndicatorPos READ wrapIndicatorPos WRITE setWrapIndicatorPos NOTIFY wrapIndicatorPosChanged)
    Q_PROPERTY(bool tabIsTab READ tabIsTab WRITE setTabIsTab NOTIFY tabIsTabChanged)
    Q_PROPERTY(int tabWidth READ tabWidth WRITE setTabWidth NOTIFY tabWidthChanged)
    Q_PROPERTY(ColorConfig* color READ color CONSTANT)
    Q_PROPERTY(bool changed READ changed WRITE setChanged NOTIFY changedChanged)
    Q_PROPERTY(QStringList recentFiles READ recentFiles WRITE setRecentFiles NOTIFY recentFilesChanged)

public:
    enum SizeMode { Small, Medium, Large };
    Q_ENUM(SizeMode)

    explicit Config(QObject *parent = nullptr) : QObject(parent), m_color(new ColorConfig(this)), m_changed(false) {}

    SizeMode sizeMode() const { return m_sizeMode; }
    void setSizeMode(SizeMode mode) { if (m_sizeMode != mode) { m_sizeMode = mode; emit sizeModeChanged(); } }

    QSize size() const { return m_size; }
    void setSize(const QSize &size) { if (m_size != size) { m_size = size; emit sizeChanged(); } }

    QFont font() const { return m_font; }
    void setFont(const QFont &font) { if (m_font != font) { m_font = font; emit fontChanged(); } }

    bool wrapWords() const { return m_wrapWords; }
    void setWrapWords(bool wrap) { if (m_wrapWords != wrap) { m_wrapWords = wrap; emit wrapWordsChanged(); } }

    bool wrapIndicator() const { return m_wrapIndicator; }
    void setWrapIndicator(bool indicator) { if (m_wrapIndicator != indicator) { m_wrapIndicator = indicator; emit wrapIndicatorChanged(); } }

    int wrapIndicatorPos() const { return m_wrapIndicatorPos; }
    void setWrapIndicatorPos(int pos) { if (m_wrapIndicatorPos != pos) { m_wrapIndicatorPos = pos; emit wrapIndicatorPosChanged(); } }

    bool tabIsTab() const { return m_tabIsTab; }
    void setTabIsTab(bool isTab) { if (m_tabIsTab != isTab) { m_tabIsTab = isTab; emit tabIsTabChanged(); } }

    int tabWidth() const { return m_tabWidth; }
    void setTabWidth(int width) { if (m_tabWidth != width) { m_tabWidth = width; emit tabWidthChanged(); } }

    ColorConfig* color() const { return m_color; }

    bool changed() const { return m_changed; }
    void setChanged(bool changed) { if (m_changed != changed) { m_changed = changed; emit changedChanged(); } }

    QStringList recentFiles() const { return m_recentFiles; }
    void setRecentFiles(const QStringList &files) { if (m_recentFiles != files) { m_recentFiles = files; emit recentFilesChanged(); } }

signals:
    void sizeModeChanged();
    void sizeChanged();
    void fontChanged();
    void wrapWordsChanged();
    void wrapIndicatorChanged();
    void wrapIndicatorPosChanged();
    void tabIsTabChanged();
    void tabWidthChanged();
    void changedChanged();
    void recentFilesChanged();

private:
    SizeMode m_sizeMode;
    QSize m_size;
    QFont m_font;
    bool m_wrapWords;
    bool m_wrapIndicator;
    int m_wrapIndicatorPos;
    bool m_tabIsTab;
    int m_tabWidth;
    ColorConfig *m_color;
    bool m_changed;
    QStringList m_recentFiles;
};
#endif // CONFIG_H
