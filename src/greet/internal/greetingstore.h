#ifndef GT_GREET_GREETINGSTORE_H
#define GT_GREET_GREETINGSTORE_H

#include <QObject>
#include <QString>
#include <QVariantMap>

#include "actions/istore.h"

using namespace gt::actions;

namespace gt::greet
{
class GreetingStore : public QObject, public IStore
{
    Q_OBJECT
    Q_PROPERTY(QString greeting READ greeting WRITE setGreeting NOTIFY greetingChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    GreetingStore()
    {
        init();
    }

    void init() override;

    QString greeting() const;
    void setGreeting(const QString& greeting);
    QString name() const;
    void setName(const QString& name);

    Q_INVOKABLE void showGreetingSettings();
private:
    QString m_greeting = QString("Hello");
    QString m_name;
signals:
    void greetingChanged();
    void nameChanged();
};
} // gt::greet

#endif
