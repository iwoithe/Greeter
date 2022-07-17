#ifndef GT_UI_UITHEME_H
#define GT_UI_UITHEME_H

#include <QColor>
#include <QFont>
#include <QObject>

// TODO: Should `iuitheme.h` exist?

namespace gt::ui
{
class UiTheme : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isDark READ isDark WRITE setIsDark NOTIFY themeChanged)

    Q_PROPERTY(QColor accentColor READ accentColor WRITE setAccentColor NOTIFY themeChanged)
    Q_PROPERTY(QColor backgroundPrimaryColor READ backgroundPrimaryColor WRITE setBackgroundPrimaryColor NOTIFY themeChanged)
    Q_PROPERTY(QColor backgroundSecondaryColor READ backgroundSecondaryColor WRITE setBackgroundSecondaryColor NOTIFY themeChanged)
    Q_PROPERTY(QColor buttonColor READ buttonColor WRITE setButtonColor NOTIFY themeChanged)
    Q_PROPERTY(QColor componentColor READ componentColor WRITE setComponentColor NOTIFY themeChanged)
    Q_PROPERTY(QColor focusColor READ focusColor WRITE setFocusColor NOTIFY themeChanged)
    Q_PROPERTY(QColor fontPrimaryColor READ fontPrimaryColor WRITE setFontPrimaryColor NOTIFY themeChanged)
    Q_PROPERTY(QColor fontSecondaryColor READ fontSecondaryColor WRITE setFontSecondaryColor NOTIFY themeChanged)
    Q_PROPERTY(QColor linkColor READ linkColor WRITE setLinkColor NOTIFY themeChanged)
    Q_PROPERTY(QColor popupBackgroundColor READ popupBackgroundColor WRITE setPopupBackgroundColor NOTIFY themeChanged)
    Q_PROPERTY(QColor strokeColor READ strokeColor WRITE setStrokeColor NOTIFY themeChanged)

public:
    bool isDark() const;
    void setIsDark(bool isDark);

    QColor accentColor() const;
    void setAccentColor(QColor accentColor);

    QColor backgroundPrimaryColor() const;
    void setBackgroundPrimaryColor(QColor backgroundPrimaryColor);

    QColor backgroundSecondaryColor() const;
    void setBackgroundSecondaryColor(QColor backgroundSecondaryColor);

    QColor buttonColor() const;
    void setButtonColor(QColor buttonColor);

    QColor componentColor() const;
    void setComponentColor(QColor componentColor);

    QColor focusColor() const;
    void setFocusColor(QColor focusColor);

    QColor fontPrimaryColor() const;
    void setFontPrimaryColor(QColor fontPrimaryColor);

    QColor fontSecondaryColor() const;
    void setFontSecondaryColor(QColor fontSecondaryColor);

    QColor linkColor() const;
    void setLinkColor(QColor linkColor);

    QColor popupBackgroundColor() const;
    void setPopupBackgroundColor(QColor popupBackgroundColor);

    QColor strokeColor() const;
    void setStrokeColor(QColor strokeColor);

private:
    // TODO: Should this be named "UiState" instead?
    struct StyleState {
        bool enabled = false;
        bool hovered = false;
        bool pressed = false;
        bool focused = false;
    };

    bool m_isDark;

    QColor m_accentColor;
    QColor m_backgroundPrimaryColor;
    QColor m_backgroundSecondaryColor;
    QColor m_buttonColor;
    QColor m_componentColor;
    QColor m_focusColor;
    QColor m_fontPrimaryColor;
    QColor m_fontSecondaryColor;
    QColor m_linkColor;
    QColor m_popupBackgroundColor;
    QColor m_strokeColor;

signals:
    void themeChanged();
};
}

#endif