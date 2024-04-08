#ifndef DF_TABLE_H
#define DF_TABLE_H

#include "common.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <stdint.h>
#include "rows.h"

namespace DF
{
    typedef std::vector<std::unordered_map<std::string, std::any*>>* TableData_t;
    typedef std::vector<std::unordered_map<std::string, std::any*>> TableDataC_t;

    class Table
    {
    public:
        Table(TableData_t data);
        ~Table();

        /// @brief
        /// @tparam T return type
        /// @param idx index of the row that data is present in
        /// @param name name of data needed 
        /// @return 
        template <typename T>
        T get_data_ptr(size_t idx, std::string name)
        {
            return &std::any_cast<T>(*m_data->at(idx)[name]);
        }

        template <typename T>
        T get_data(size_t idx, std::string name)
        {
            return std::any_cast<T>(*m_data->at(idx)[name]);
        }

        Row get_row(size_t idx)
        {
            return Row(&m_data->at(idx), this);
        }

    private:
        TableData_t m_data;
    };
}

#endif