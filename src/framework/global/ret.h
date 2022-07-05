#ifndef GT_GLOBAL_RET_H
#define GT_GLOBAL_RET_H

#include <any>
#include <map>
#include <string>

namespace gt
{
class Ret
{
public:
    enum class Code {
        Undefined = -1,
        Ok = 0,
        Cancel = 1,
        UnknownError = 2,
        NotSupported = 3,
        NotImplemented = 4,
    };

    Ret() = default;
    explicit Ret(int c);
    explicit Ret(Code c);
    explicit Ret(const int& c, const std::string& text);

    int code() const;
    void setCode(int c);
    bool isValid() const;
    bool isSuccess() const;
    const std::string& text() const;
    void setText(const std::string& s);
    std::any data(const std::string& key);
    void setData(const std::string& key, const std::any& val);
private:
    int m_code = static_cast<int>(Code::Undefined);
    std::string m_text;
    std::map<std::string, std::any> m_data;
};
}

#endif
