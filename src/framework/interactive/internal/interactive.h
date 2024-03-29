#ifndef GT_INTERACTIVE_INTERNAL_INTERACTIVE_H
#define GT_INTERACTIVE_INTERNAL_INTERACTIVE_H

#include <vector>

#include <QObject>

#include "../iinteractive.h"

namespace gt::interactive
{
class Interactive : public QObject, public IInteractive
{
    Q_OBJECT
public:
    explicit Interactive(QObject* parent = nullptr);
    ~Interactive() override = default;

    static Interactive* instance();
    void regDialog(const std::string& path, const std::string& resourcePath) override;
    Result openDialog(const std::string& path, Params& params) override;
private:
    std::map<std::string, std::string> m_dialogs;
};
} // gt::interactive

#endif
