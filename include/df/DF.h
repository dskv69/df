#ifndef DF_DF_H
#define DF_DF_H

#include "common.h"
#include "table.h"

namespace DF
{
    class DFData
    {
    private:
        std::vector<std::any> m_data;
        std::unordered_map<std::string, Table> m_tables;
        std::unordered_map<std::string, std::any*> m_vars;
        
    public:
        DFData();
        ~DFData();

        void add_table(std::string name, Table table);
        void add_var(std::string name, std::any *var);

        Table get_table(std::string name);

        inline std::any* get_var(std::string name) const { return m_vars.at(name); }


        std::any* add_val(std::any val);
    };
    
}

#endif