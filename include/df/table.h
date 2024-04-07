#ifndef DF_DF_H
#define DF_DF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <stdint.h>

namespace DF
{
    typedef std::vector<std::unordered_map<std::string, void *>>* TableData;
    typedef std::vector<std::unordered_map<std::string, void *>> TableDataC;

    class Table
    {
    public:
        Table(TableData data);
        ~Table();

        template <typename T>
        T* get_data(int idx, std::string item)
        {
            return (T*)m_data->at(idx)[item];
        }

    private:
        TableData m_data;
    };
}

#endif