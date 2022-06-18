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
    void init() override;

    QString greeting() const;
    QString name() const;
private:
    QString m_greeting = QString("Hello, ");
    void setGreeting(QString greeting);
    void setGreeting(QVariantMap args)
    {
        setGreeting(args["greeting"].toString());
    }

    QString m_name;
    void setName(QString name);
    void setName(QVariantMap args)
    {
        setName(args["name"].toString());
    }
signals:
    void greetingChanged();
    void nameChanged();
};
} // gt::greet

#endif
