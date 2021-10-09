#ifndef CTYPEDATA_H
#define CTYPEDATA_H
#include <unordered_map>
#include <string>
#include <QFileInfo>

using namespace std;

class CTypeData
{
public:
    CTypeData();
    ~CTypeData();
    void Init();
    void LoadData(QFileInfo fileInfo);
private:
    std::unordered_map<string, string>m_dd;
};

#endif // CTYPEDATA_H
