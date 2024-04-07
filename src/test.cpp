#include <iostream>
#include "df/common.h"
#include "df/table.h"
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

    int hi = 69;
    void *hi_ref = &hi;
    DF::TableDataC dat = {{{"hi", hi_ref}}};
    auto tab = DF::Table(&dat);

    std::cout << *tab.get_data<int>(0, "hi") << '\n';
    std::cout << *(int *)hi_ref << '\n';
    return 0;
}