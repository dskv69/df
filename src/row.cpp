#include "df/rows.h"
#include "df/table.h"


namespace DF 
{
    Row::Row(RowData_t data, Table* parent) : m_data(data), m_parent(parent)
    {
    }

    Row::~Row()
    {
    }
}