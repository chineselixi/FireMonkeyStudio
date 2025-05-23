#ifndef COLORCONFIG_H
#define COLORCONFIG_H
#include <QObject>
#include <QColor>

class ColorConfig : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor bg READ bg WRITE setBg NOTIFY bgChanged)
    Q_PROPERTY(QColor fg READ fg WRITE setFg NOTIFY fgChanged)
    Q_PROPERTY(QColor string READ string WRITE setString NOTIFY stringChanged)
    Q_PROPERTY(QColor character READ character WRITE setCharacter NOTIFY characterChanged)
    Q_PROPERTY(QColor comment READ comment WRITE setComment NOTIFY commentChanged)
    Q_PROPERTY(QColor preproc READ preproc WRITE setPreproc NOTIFY preprocChanged)
    Q_PROPERTY(QColor number READ number WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(QColor operateur READ operateur WRITE setOperateur NOTIFY operateurChanged)
    Q_PROPERTY(QColor keyword READ keyword WRITE setKeyword NOTIFY keywordChanged)
    Q_PROPERTY(QColor error READ error WRITE setError NOTIFY errorChanged)

public:
    explicit ColorConfig(QObject *parent = nullptr) : QObject(parent) {}

    QColor bg() const { return m_bg; }
    void setBg(const QColor &color) { if (m_bg != color) { m_bg = color; emit bgChanged(); } }

    QColor fg() const { return m_fg; }
    void setFg(const QColor &color) { if (m_fg != color) { m_fg = color; emit fgChanged(); } }

    QColor string() const { return m_string; }
    void setString(const QColor &color) { if (m_string != color) { m_string = color; emit stringChanged(); } }

    QColor character() const { return m_character; }
    void setCharacter(const QColor &color) { if (m_character != color) { m_character = color; emit characterChanged(); } }

    QColor comment() const { return m_comment; }
    void setComment(const QColor &color) { if (m_comment != color) { m_comment = color; emit commentChanged(); } }

    QColor preproc() const { return m_preproc; }
    void setPreproc(const QColor &color) { if (m_preproc != color) { m_preproc = color; emit preprocChanged(); } }

    QColor number() const { return m_number; }
    void setNumber(const QColor &color) { if (m_number != color) { m_number = color; emit numberChanged(); } }

    QColor operateur() const { return m_operateur; }
    void setOperateur(const QColor &color) { if (m_operateur != color) { m_operateur = color; emit operateurChanged(); } }

    QColor keyword() const { return m_keyword; }
    void setKeyword(const QColor &color) { if (m_keyword != color) { m_keyword = color; emit keywordChanged(); } }

    QColor error() const { return m_error; }
    void setError(const QColor &color) { if (m_error != color) { m_error = color; emit errorChanged(); } }

signals:
    void bgChanged();
    void fgChanged();
    void stringChanged();
    void characterChanged();
    void commentChanged();
    void preprocChanged();
    void numberChanged();
    void operateurChanged();
    void keywordChanged();
    void errorChanged();

private:
    QColor m_bg;
    QColor m_fg;
    QColor m_string;
    QColor m_character;
    QColor m_comment;
    QColor m_preproc;
    QColor m_number;
    QColor m_operateur;
    QColor m_keyword;
    QColor m_error;
};

#endif // COLORCONFIG_H
