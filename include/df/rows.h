#ifndef DF_ROWS_H
#define DF_ROWS_H

#include "common.h"

namespace DF 
{
    class Table;

    typedef std::unordered_map<std::string, std::any*>* RowData_t;

    class Row
    {
        public:
            Row(RowData_t d, Table* parent = nullptr);
            ~Row();

            template <typename T> 
            T get_data_ptr(std::string name) {
                return &std::any_cast<T>(*m_data->at(name));
            }

            template <typename T>
            T get_data(std::string name) {
                return std::any_cast<T>(*m_data->at(name));
            }

            inline Table* get_parent() {return m_parent;}

        private:
            RowData_t m_data;
            Table* m_parent;
    };
}

#endif