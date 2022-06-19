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
    Q_PROPERTY(QString greeting READ greeting NOTIFY greetingChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
public:
    GreetingStore()
    {
        init();
    }

    void init() override;

    QString greeting() const;
    QString name() const;
private:
    QString m_greeting = QString("Hello, ");
    void setGreeting(QVariantMap greeting);

    QString m_name;
    void setName(QVariantMap actionData);
signals:
    void greetingChanged();
    void nameChanged();
};
} // gt::greet

#endif
