#include "expense_diary.h"

int run(Diary kito) {

    int option = -1;
    int type = 0, cost = 0, show_type = 0, sort_field = 1, order = 0;
    std::string time, note, answer;

    while (option) {
        system("cls");
        kito.display_diary(show_type, sort_field, order);

        std::cout << "\n\n\n===============================================\n\n\n";
        std::cout << "1. show list record\n2. add new record\n0. exit";

        std::cout << "\n\n\n===============================================\n\n\n";
        
        std::cout << "\noption: ";
        if (option == -1)
            std::cin >> option;
        switch (option)
        {
        case 0:
            return 0;
        case 1:
            system("cls");
            kito.display_diary(show_type, sort_field, order);

            std::cout << "\n\n\n===============================================\n\n\n";
            std::cout << "show type list: 0(ALL), 1, 2, 3, 4\nsort field list: 1(type), 2(time), 3(cost)\norder: 0(ASC), 1(DESC)";

            std::cout << "\n\n\n===============================================\n\n\n";
            std::cout << std::endl << "show type: ";
            std::cin >> show_type;
            std::cout << std::endl << "sort field: ";
            std::cin >> sort_field;
            std::cout << std::endl << "order: ";
            std::cin >> order;

            option = -1;
            break;
        case 2:
            system("cls");
            kito.display_diary(show_type, sort_field, order);

            std::cout << "\n\n\n===============================================\n\n\n";
            std::cout << "type list: 1, 2, 3, 4\ncost between 1000 and 10000000";

            std::cout << "\n\n\n===============================================\n\n\n";

            std::cout << std::endl << "type: ";
            std::cin >> type;
            std::cout << std::endl << "cost: ";
            std::cin >> cost;
            std::cin.ignore();
            std::cout << std::endl << "time (dd/mm/yyyy): ";
            std::getline(std::cin, time);
            std::cout << std::endl << "note: ";
            std::getline(std::cin, note);

            if (kito.add_record(type, cost, time, note) == -1)
            {
                std::cout << "wrong input. do you want to re-enter? (yes/no)\n";
                std::cin >> answer;
                if (answer == "yes")
                    option = 2;
                else
                    option = -1;
            }
            else
                option = -1;
            break;

        default:
            option = -1;
            break;
        }

    }

    return 0;
}

int main()
{
    Diary kito;

    enum sort_field { TYPE = 1, TIME = 2, COST = 3 };
    enum order { ASC = 1, DESC = 0 };

    // kito.add_record(0, 2000, "1/12/2022", "error type");

    // kito.add_record(1, 500, "6/2/2022", "error cost");
    
    // kito.add_record(4, 1000, "31/6/2022", "error time 1");
    // kito.add_record(4, 1000, "32/7/2022", "error time 2");
    // kito.add_record(4, 1000, "30/2/2024", "error time 3");
    // kito.add_record(4, 1000, "29/2/2022", "error time 4");
    // kito.add_record(4, 1000, "0/6/2022", "error time 5");
    // kito.add_record(4, 1000, "0/7/2022", "error time 6");
    // kito.add_record(4, 1000, "0/2/2022", "error time 7");

    kito.add_record(2, 4000, "23/12/2022", "a");
    kito.add_record(1, 6200, "2/5/2022", "b");
    kito.add_record(3, 3000, "23/7/2022", "c");

    std::cout << std::endl;

    kito.display_diary(0, TYPE, DESC);

    kito.add_record(2, 8000, "2/2/2023", "d");
    kito.add_record(4, 12200, "29/2/2024", "e");
    
    std::cout << std::endl;
    std::cout << std::endl;

    run(kito);

}
