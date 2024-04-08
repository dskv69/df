#include "df/DF.h"

namespace DF
{
    DFData::DFData() : m_data(), m_tables() {}

    DFData::~DFData() {
    }

    void DFData::add_table(std::string name, Table table) {
        m_tables.insert({name, table});
    }

    void DFData::add_var(std::string name, std::any* var)
    {
        m_vars.insert({name, var});
    }

    Table DFData::get_table(std::string name)
    {
        return m_tables.at(name);
    }

    std::any* DFData::add_val(std::any val)
    {
        m_data.push_back(val);
        return &m_data[m_data.size() - 1];
    }
}