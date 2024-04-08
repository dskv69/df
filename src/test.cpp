#include <iostream>
#include "df/common.h"
#include "df/table.h"
#include "df/DF.h"
#include <string>

int main(int argc, char *argv[])
{
    std::string data = R"(
	[Student] # table named student
    [
        (id: Int32, name: Str, subjects: Arr[string]) # layout in ()

        {
            0, "Jake", ["biology", "chemistry", "physics"]  #data
        }

        {
            0, "Jhon", ["biology", "chemistry", "physics", English]
        }
    ];)";

    auto df = DF::DFData();

    std::any* hi = df.add_val(69);
    DF::TableDataC_t dat = {{{"hi", hi}}};
    auto tab = DF::Table(&dat);
    df.add_table("test_table", tab);
    auto first_row = df.get_table("test_table").get_row(0);

    std::cout << first_row.get_data<int>("hi") << '\n';

    return 0;
}