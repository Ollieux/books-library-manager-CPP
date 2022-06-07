#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unistd.h>

class Client {

    int id;
    std::string name;
    std::string lastname;

public:
    void setId(int id) {
        Client::id = id;
    }

    void setImie(const std::string &name) {
        Client::name = name;
    }

    void setNazwisko(const std::string &lastname) {
        Client::lastname = lastname;
    }
};

class Book {


    int id;
    std::string titles;
    std::vector<std::string> genres;
    int year;
    int pages;
    int id_authors;
public:
    void setId(int id) {
        Book::id = id;
    }

    void setTitles(const std::string &titles) {
        Book::titles = titles;
    }

    void setGenres(const std::vector<std::string> &genres) {
        Book::genres = genres;
    }

    void setYear(int year) {
        Book::year = year;
    }

    void setPages(int pages) {
        Book::pages = pages;
    }

    void setIdAuthors(int idAuthors) {
        id_authors = idAuthors;
    }

};

class Author {


    int id;
    std::string name;
    std::string lastname;
public:
    void setId(int id) {
        Author::id = id;
    }

    void setName(const std::string &name) {
        Author::name = name;
    }

    void setLastname(const std::string &lastname) {
        Author::lastname = lastname;
    }
};

class Order {


    int id;
    int book_id;
    int client_id;
    bool lend;
public:
    void setId(int id) {
        Order::id = id;
    }

    void setBookId(int bookId) {
        book_id = bookId;
    }

    void setClientId(int clientId) {
        client_id = clientId;
    }

    void setLend(bool lend) {
        Order::lend = lend;
    }
};

class Entity {
//    Client client;
//    Book book;
//    Author author;
//    Order order;
    int id;
    std::string titles;
    std::vector<std::string> genres;
    int year;
    int pages;
    int id_authors;
    std::string name;
    std::string lastname;
    int book_id;
    int client_id;
    bool lend;


public:
    Entity() : id(-1), titles("0"), genres({}), year(-1), pages(-1), id_authors(-1), name("0"),
              lastname("0"), book_id(-1), client_id(-1), lend(false) {};

    Entity(int id, std::string name, std::string lastname): id(id), name(name), lastname(lastname){};

    Entity(int id, int book_id, int client_id, bool lend): id(id), book_id(book_id), client_id(client_id), lend(lend){};

    Entity (int id, std::string titles, std::vector<std::string>genres, int year, int pages, int id_authors):
        id(id),
        titles(titles),
        genres(genres),
        year(year),
        pages(pages),
        id_authors(id_authors){};

    Entity getEntity() {
        if (id != -1) {
            if (name != "0") {
                if (lastname != "0") {
                    Entity e(id, name, lastname);
                    return e;
                }
            }
            else {
                if (book_id != -1) {
                    if (client_id != -1) {
                        Entity e(id, book_id, client_id, lend);
                        return e;
                    }
                }
                else {
                    if(titles != "0") {
                        if (genres.size() != 0) {
                            if (year != -1) {
                                if (pages != -1) {
                                    if (id_authors != -1) {
                                        Entity e(id, titles, genres, year, pages, id_authors);
                                        return e;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    void setId(int id) {
        this->id = id;
    }

    void setTitles(const std::string &titles) {
        this->titles = titles;
    }

    void setGenres(const std::vector<std::string> &genres) {
        this->genres = genres;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setPages(int pages) {
        this->pages = pages;
    }

    void setIdAuthors(int idAuthors) {
        this->id_authors = idAuthors;
    }

    void setName(const std::string &name) {
        this->name = name;
    }

    void setLastname(const std::string &lastname) {
        this->lastname = lastname;
    }

    void setBookId(int bookId) {
        this->book_id = bookId;
    }

    void setClientId(int clientId) {
        this->client_id = clientId;
    }

    void setLend(bool lend) {
        this->lend = lend;
    }

    int getId() const {
        return id;
    }

    const std::string &getTitles() const {
        return titles;
    }

    const std::vector<std::string> &getGenres() const {
        return genres;
    }

    int getYear() const {
        return year;
    }

    int getPages() const {
        return pages;
    }

    int getIdAuthors() const {
        return id_authors;
    }

    const std::string &getName() const {
        return name;
    }

    const std::string &getLastname() const {
        return lastname;
    }

    int getBookId() const {
        return book_id;
    }

    int getClientId() const {
        return client_id;
    }

    bool isLend() const {
        return lend;
    }


};

std::map<std::string, std::vector<std::string>> headers;
// std::map<std::string, std::vector<std::vector<std::string>>> data;
// std::map<std::string, std::vector<std::vector<Entity>>> data;
std::map<std::string, std::vector<Entity>> data;
// std::map<std::string, std::map<std::string, int>> config;
std::map<std::string, int> config;

void initializeHeaders() {
    std::vector<std::string> clients = {"id", "name", "lastname"};
    std::vector<std::string> books = {"id", "titles", "genres", "year", "pages", "id authors"};
    std::vector<std::string> authors = {"id", "name", "lastname"};
    std::vector<std::string> orders = {"id", "id books", "id clients",  "lend"};
    headers["clients"] = clients;
    headers["books"] = books;
    headers["authors"] = authors;
    headers["orders"] = orders;

}

void initializeData() {
    // std::vector<std::vector<std::string>> clients = {};

    //e.setAuthor()
    // std::vector<std::vector<Client>> clients = {};
    // std::vector<std::vector<Book>> books = {};
    // std::vector<std::vector<Author>> authors = {};
    // std::vector<std::vector<Order>> orders = {};
    // std::vector<std::vector<Entity>> clients = {};
    // std::vector<std::vector<Entity>> books= {};
    // std::vector<std::vector<Entity>> authors= {};
    // std::vector<std::vector<Entity>> orders = {};

    std::vector<Entity> clients = {};
    std::vector<Entity> books = {};
    std::vector<Entity> authors = {};
    std::vector<Entity> orders = {};


    data["clients"] = clients;
    data["books"] = books;
    data["authors"] = authors;
    data["orders"] = orders;
}

void initializeConfig() {
    config["books"] = 0;
    config["clients"] = 0;
    config["authors"] = 0;
    config["orders"] = 0;

}



class Tables {

    public:
    static int getColumnIndex(std::string table, std::string headerName) {
        std::cout << "#searching for column index " << headerName << " in table " << table << "...";
        int temp {-1};
        for (int i = 0; i < headers[table].size(); i++) {
            if (headers[table][i] == headerName) {
                temp = i;
            }
        }
        return temp;
    }

    static Entity getById(std::string table, int id) {
    //// static std::string getById(std::string table, int id) {
        Entity result;
        std::cout << "#szukanie id " << id << " w tableli " << table << "...";
        //// int idColumn = getColumnIndex(table, "id");
        for(Entity item : data[table]) {
        //// for (std::vector<std::string> item : data[table]) {
            bool flag = item.getId() == id;
            std::cout << item.getId() << "==" << id << "--> " << flag;
            ////std::cout << std::to_string(item[idColumn]) << "==" << std::to_string(id) <<"--> " << item[idColumn] == id;
            ////if(item[idColumn] == id) {
            if (item.getId() == id) {
                result = item;
            }
        }
        return result.getEntity();
    }

    static void initializeDB() { //TODO: potencjalna konktatencja nazwy pliku z .txt

        bool flag = false;
        for(std::map<std::string, std::vector<Entity>>::iterator iter = data.begin(); iter != data.end(); ++iter) {
            std::string item = iter->first;
            std::ifstream file;
            file.open(item);
            if (!file) {
                flag = true;
                std::cout << "File " << item << " not found" << std::endl;
            }
            file.close();
        }
        if(flag) {
            std::cout << "There was no existing database" << std::endl; //TODONE: endl
            createTables();
            std::cout << "~  database was created ~"; //TODONE: endl
        }
        else {
            std::cout << "database exists!" << std::endl;
            readTables();
        }

    }

    static void createTables() {
        for(std::map<std::string, std::vector<Entity>>::iterator iter = data.begin(); iter != data.end(); ++iter) { //TODONE: iterator po hashtable
            std::string item = iter->first;
            std::ofstream file;
            file.open(item);
            if(!file) {
                std::cerr << "file creation error " << item;
            }
            file.close();

            std::cout << "~ table created " << item << "  ~" << std::endl;
        }
    }

    static void writeTables() {
        //TODONE:
        for(std::map<std::string, std::vector<Entity>>::iterator iter = data.begin(); iter != data.end(); ++iter) {
            std::vector<Entity> item = iter -> second;
            std::string table = iter->first;
            std::ofstream file;
            file.open(table, std::ios::app);
            for(Entity e: item) {
                std::string output;
                if (table == "books") {
                    output.append(std::to_string(e.getId()));
                    output.append(",");
                    output.append(e.getTitles());
                    output.append(",");
                    output.append(e.getGenres()[0]);
                    output.append(",");
                    output.append(std::to_string(e.getYear()));
                    output.append(",");
                    output.append(std::to_string(e.getPages()));
                    output.append(",");
                    output.append(std::to_string(e.getIdAuthors()));
                    output.append("\n");


                }
                else if (table == "orders") {
                    output.append(std::to_string(e.getId()));
                    output.append(",");
                    output.append(std::to_string(e.getBookId()));
                    output.append(",");
                    output.append(std::to_string(e.getClientId()));
                    output.append(",");
                    output.append(std::to_string(e.isLend()));
                    output.append("\n");
                }

                else if (table == "clients" || table == "authors") {
                    output.append(std::to_string(e.getId()));
                    output.append(",");
                    output.append(e.getName());
                    output.append(",");
                    output.append(e.getLastname());
                    output.append("\n");
                }



            if(!file) {
                std::cerr << "file opening error " << table;
            }

            file << (output);
            }
        file.close();
        }
    }

    static void readTables() {
        for(std::map<std::string, std::vector<Entity>>::iterator iter = data.begin(); iter != data.end(); ++iter) {

            std::vector<Entity> item = iter->second;
            std::string table = iter->first;
            std::cout << "-read table " << table << std::endl;
            std::ifstream file;
            file.open(table);

            if (!file) {
                std::cerr << "File opening error" << table ;
            }

            if (table == "books") {

                while (file) {

                    Entity e;
                    std::string input, value;
                    file >> input;
                    int i = input.find(",");
                    value = input.substr(0, i);
                    e.setId(std::stoi(value));

                    input = input.substr(i + 1);
                    i = input.find(",");
                    value = input.substr(0, i);
                    e.setTitles(value);

                    input = input.substr(i + 1);
                    i = input.find(",");
                    value = input.substr(0, i);
                    std::vector<std::string> genres;
                    genres.push_back(value);
                    e.setGenres(genres);

                    input = input.substr(i + 1);
                    i = input.find(",");
                    value = input.substr(0, i);
                    e.setYear(std::stoi(value));

                    input = input.substr(i + 1);
                    i = input.find(",");
                    value = input.substr(0, i);
                    e.setPages(std::stoi(value));

                    input = input.substr(i + 1);
                    i = input.find(",");
                    value = input.substr(0, i);
                    e.setIdAuthors(std::stoi(value));

                    item.push_back(e.getEntity());

                }
                file.close();
            } else if (table == "orders") {

                while (file) {

                    Entity e;
                    std::string input, value;
                    file >> input;
                    int i = input.find(",");
                    value = input.substr(0, i);
                    e.setId(std::stoi(value));

                    input = input.substr(i + 1);
                    i = input.find(",");
                    value = input.substr(0, i);
                    e.setBookId(std::stoi(value));

                    input = input.substr(i + 1);
                    i = input.find(",");
                    value = input.substr(0, i);
                    e.setClientId(std::stoi(value));

                    input = input.substr(i + 1);
                    i = input.find(",");
                    value = input.substr(0, i);
                    e.setLend(std::stoi(value));

                    item.push_back(e.getEntity());

                }
                file.close();
            }

            else if(table == "clients" || table == "authors") {

                while (file) {
                    std::string input, value;
                    Entity e;
                    file >> input;
                    int i = input.find(",");
                    value = input.substr(0, i);
                    e.setId(std::stoi(value));

                    input = input.substr(i + 1);
                    i = input.find(",");
                    value = input.substr(0, i);
                    e.setName(value);

                    input = input.substr(i + 1);
                    i = input.find(",");
                    value = input.substr(0, i);
                    e.setLastname(value);

                    item.push_back(e.getEntity());
                }
                file.close();
            }
        }
        std::cout << std::endl;
    }
};

class System {

    public:
    static void boot() {
        std::cout << "LIBRARY MANAGER IS BOOTING..." << std::endl;
        //sleep
        configLoading();
        Tables::initializeDB();
    }

    static int autoincrement(std::string title) {
        config[title]++;
        return config[title];
    }

    static int decrement(std::string title) {
        config[title]--;
        return config[title];
    }

    static void configLoading() {

        std::ifstream file;
        file.open("config.txt");
        if (file) { //// Config istnieje
            for (std::map<std::string, int>::iterator iter = config.begin(); iter != config.end(); ++iter) {
                std::string item = iter->first;
                int line = 0;

                if(item == "books") {
                }
                else if(item == "authors") {
                    line = 1;
                }
                else if(item == "clients") {
                    line  = 2;
                }
                else if(item == "orders") {
                    line = 3;
                }
                int i = 0;
                while(true) {
                    std::string input;
                    file >> input;
                    if(i == line) {
                        config[item] = std::stoi(input);
                        break;
                    }
                    i++;
                }
            }
            std::cout << "config read successfully" << std::endl;
            file.close();
        }
        else {
            std::cout << "ERROR: config couldn't be read" << std::endl;
            updateConfig();
        }

    }

    static void updateConfig() {

        std::ofstream file;
        file.open("config.txt");
        for (std::map<std::string, int>::iterator iter = config.begin(); iter != config.end(); ++iter) {
            std::string item = iter->first;
            int value = iter->second;
            file << std::to_string(value) << "\n";
        }
        file.close();

    }

    static void quitting() {
        while(true) {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "     DO YOU WANT TO SAVE CHANGES? (y/n)";
            char order;
            std::cin >> order;
            std::cout << std::endl;
            if (order == 'y') {
                std::cout << "~ config was updated ~";
                updateConfig();
                Tables::writeTables();
                break;
            }
            else if (order == 'n') {
                std::cout << "changes were abandon";
                break;
            }
        }
        //TODO: exit();
    }
};

class Interface {

    public:
    static void printHeader(std::string title){
        std::cout  << std::endl;
        std::cout << "  ########################" << std::endl;
        std::cout << std::endl;
        std::cout << "    ~~~ Library database ~~~" << std::endl;
        std::cout << "    "+title << std::endl;
        std::cout << std::endl;
    }

    static std::string printInterface(std::string title, std::vector<std::string> options) { //TODO: sprawdz czy size parametrowego vectora sie sprawdzi czy jakis const
        printHeader(title);
        std::cout << "     OPTIONS:" << std::endl;
        std::cout << std::endl;

        for (int i = 0; i < options.size(); i++) {
            std::cout << "     " << options[i] << std::endl;
        }

        std::cout << std::endl;
        std::cout << "  ########################" << std::endl;
        std::cout << std::endl;
        std::string order;
        std::cout << "     ~[provide command]~>";
        std::cin >> order;
        std::cout << std::endl;
        return order;
    }

    static void unknownCommandPrompt() {
        std::cout << "!!! Unrecognised command !!!";
        //sleep
    }

    //static void printTableFromData(std::string title, std::vector<std::string> headers, std::vector<std::vector<std::string>> data, bool pauseEnded=true) {
    static void printTableFromData(std::string title, std::vector<std::string> header, std::vector<Entity> _data,  bool pauseEnded=true) {
        std::cout << "  ########################";
        std::cout << std::endl;
        std::cout << "     " << title;
        std::cout << std::endl;
        for (int i = 0; i < header.size(); i++) {
            std::cout << "     " << header[i] << "  |  " ; //TODO: te pierwsze spacje chyba po za petle
        }
        std::cout << std::endl;
        //for (std::vector<std::string> item: data) {
        for(Entity item : _data) {
            // std::vector <std::string> temp;
            //for (std::string subitem: item) {
                if (title == "books") {
                    std::cout << "     " << item.getId() << "  |  "
                              << "     " << item.getTitles() << "  |  "
                              << "     " << item.getGenres()[0] << "  |  "
                              << "     " << item.getYear() << "  |  "
                              << "     " << item.getPages() << "  |  "
                              << "     " << item.getIdAuthors() << "  |  ";
                }
                else if (title == "authors" || title == "clients") {
                    std ::cout << "     " << item.getId() << "  |  "
                               << "     " << item.getName() << "  |  "
                               << "     " << item.getLastname() << "  |  ";
                }
                else if (title == "orders") {
                    std::cout << "     " << item.getId() << "  |  "
                              << "     " << item.getBookId() << "  |  "
                              << "     " << item.getClientId() << "  |  "
                              << "     " << item.isLend() << "  |  ";
                }
        }
        if (pauseEnded) {
            std::cout << "     [wciśnij ENTER]                 ";
            std::cin.get(); // TODO: https://stackoverflow.com/questions/903221/press-enter-to-continue
        }
    }

    static void printTable(std::string name, bool pauseEnded=true) {
        printTableFromData(name, headers[name], data[name], pauseEnded);
    }


    static int choiceFromTable(std::string title) {
        while (true) {
            std::string choice;
            std::cout <<  "    do you want to insert new record? (y/n)";
            std::cin >> choice;
            if(choice == "y") {
                data[title].push_back(insertRow(title));
                // return config["autoincrement"][title];
                return config[title];
            }
            else if(choice == "n") {
               printTable(title, false);
               std::string temp;
               std::cout << "     choose id " << title <<":";
               std::cin >> temp;
               return stoi(temp);
            }
        }
    }

    static std::vector<std::string> _insertRow(std::string title) {
        std::vector<std::string> inputData;
        std::cout << std::endl;
        std::cout << "     table " << title << " - data entry";
        std::cout << std::endl;
        //for(int i = 0; i < headers[title].size(); i++) {
        for (std::string item : headers[title]) {
            std::string pre = item.substr(0, 3);
            std::string rest = item.substr(3);
            if (item == "id") {
                // inputData.push_back(system::autoincrement(title));
            }
            else if (pre == "id ") {
                // inputData.push_back(choiceFromTable(rest));
            }
            else {
                std::string input;
                std::cin >> input;
                std::replace(input.begin(), input.end(), ',', '.');
            }


        }
        std::cout << std::endl;
        std::cout << "     finished data entry";
        std::cout << std::endl;
        return inputData;

    }

    static Entity insertRow(std::string title) {
        Entity e;
        std::cout << std::endl;
        std::cout << "     table " << title << " - data entry";
        std::cout << std::endl;

        for (std::string item : headers[title]) {
            std::string pre = item.substr(0, 3);
            std::string rest = item.substr(3);
            if (item == "id") {
                e.setId(System::autoincrement(title));
            }
            else if (pre == "id ") {
                if (rest == "clients") {
                    e.setClientId(choiceFromTable(rest));
                }
                else if(rest == "authors") {
                    e.setIdAuthors(choiceFromTable(rest));
                }

                else if (rest == "books") {
                    e.setBookId(choiceFromTable(rest));
                }
            }
            else {

                std::string input;
                std::cin >> input;
                std::replace(input.begin(), input.end(), ',', '.');
                if(item == "name") {
                    e.setName(input);
                }
                else if (item == "lastname") {
                    e.setLastname(input);
                }
                else if (item == "pages") {
                    e.setPages(std::stoi(input));
                }
                else if(item == "genres") {
                    std::vector<std::string> temp;
                    temp.push_back(input);
                    e.setGenres(temp);
                }
                else if (item == "lend") {
                    e.setLend( std::stoi(input.c_str()));
                }

                else if (item == "year") {
                    e.setYear(std::stoi(input));
                }

                else if (item == "titles") {
                    e.setTitles(input);
                }
            }


        }
        std::cout << std::endl;
        std::cout << "     finished data entry";
        std::cout << std::endl;

        return e.getEntity();


    }
};





class Books {

    public:

    static void menu() {
        std::string order;
        order = Interface::printInterface("books", {
                "enter",
                "read",
                "read ascending",
                "read descending",
                "read by author",
                "read thicker than",
                "read slimmer than",
                "back"
        });

//        switch(order) {
//            case "dodaj":
//                addBook();
//                menu();
//                // break;
//            case "wypisz":
//                printBooks();
//                menu();
//            case "wypisz rosnoąco":
//                printBooksByColumn("descending");
//                menu();
//            case "wypisz malejąco":
//                printBooksByColumn();
//                menu();
//            case "wypisz konkretnego autorstwa":
//                printBooksByAuthorOnly();
//                menu();
//            case "wypisz chudsze niż":
//                printBooksBySize();
//                menu();
//
//            case "wypisz grubsze niż":
//                printBooksBySize("thicker");
//                menu();
//            case "wróć":
//                //TODO: None
//            default:
//                interface::unknownCommandPrompt();
//                menu();
//        }
        if (order == "enter") {
            addBook();
            menu();
        } else if (order == "read") {
            printBooks();
            menu();
        } else if (order == "read ascending") {
            printBooksByColumn();
            menu();
        }
        else if (order == "read descending") {
            printBooksByColumn("descending");
            menu();
        }
        else if (order == "read by author") {
            printBooksByAuthorOnly();
            menu();
        }
        else if (order == "read slimmer than") {
            printBooksBySize();
            menu();
        }
        else if (order == "read thicker than") {
            printBooksBySize("thicker");
            menu();
        }
        else if (order == "back") {
            //TODO: None
        }
        else {
            Interface::unknownCommandPrompt();
            menu();
        }
    }

    private:

    static void _printBooksByColumn(std::string mode="ascending") {
        std::cout << std::endl;
        for (std::string item : headers["books"]) {
            std::cout << "       " << item;
        }
        std::cout << std::endl;
        std::string input;
        std::cout << "     wybierz kolumnę:";
        std::cin >> input;
        int column = Tables::getColumnIndex("books", input);

        std::vector<std::string> temp, result, temp2;


//        for (std::vector<std::string> item : data["books"]){
//            std::string text = std::to_string(item[column]);
//            text.append(",");
//            std::string s = std::to_string(item[Tables::getColumnIndex("books", "id")]);
//            temp2.push_back(s);
//            text.append(s);
//            temp.push_back(text);
//        }
//        if (mode == "asceding") {
//
//        }
//        else {
//
//        }
//        for (std::string item : temp2) {
//            result.push_back(Tables::getById("books", std::stoi(item)));
//        }
//        Interface::printTableFromData("books", headers["books"], result);
    }

    static void printBooksByColumn(std::string mode="ascending") {
        std::cout << std::endl;
        for (std::string item : headers["books"]) {
            std::cout << "       " << item;
        }
        std::cout << std::endl;
        std::string input;
        std::cout << "     choose column:";
        std::cin >> input;
        int column = Tables::getColumnIndex("books", input);

        std::vector<std::string> temp;
        std::vector<Entity> result;


        for (Entity item : data["books"]){

            std::string text;

            switch(column){
                case 0:
                    text = std::to_string(item.getId());
                    break;
                case 1:
                    text = item.getTitles();
                    break;
                case 2:
                    text = item.getGenres()[0];
                    break;
                case 3:
                    text = std::to_string(item.getYear());
                    break;
                case 4:
                    text = std::to_string(item.getPages());
                    break;
                case 5:
                    text = std::to_string(item.getIdAuthors());
                    break;
            }
            text.append(",");
            text.append(std::to_string(item.getId()));
            temp.push_back(text);

        }
        if (mode == "asceding") {
            // TODONE: temp sort
            std::sort(temp.begin(), temp.end());


        }
        else {
            // TODONE temp sort, temp reverse
            std::reverse(temp.begin(), temp.end());
        }

        //TODONE: sprawdz implementacje getById
        for (std::string item : temp) {
            int i = item.find_first_of(",");
            std::string id = item.substr(i + 1);

            result.push_back(Tables::getById("books", std::stoi(id)));
        }
        Interface::printTableFromData("books", headers["books"], result);
    }

    static void _printBooksBySize(std::string mode="slimmer") {
        std::cout << "Provide page number: ";
        std::string input;
        std::cin >> input;
        std::vector<std::vector<std::string>> result;

        int pageCount = Tables::getColumnIndex("books", "pages");
//        for (std::vector<std::string> item : data["books"]) {
//            if (mode == "slimmer") {
//                if (std::stoi(item[pageCount]) >= std::stoi(input)) {
//                    result.push_back(item);
//                }
//            }
//            else if (mode == "thicker") {
//                if (std::stoi(item[pageCount]) <= std::stoi(input)) {
//                    result.push_back(item);
//
//                }
//            }
//        }
//        Interface::printTableFromData("books", headers["books"], result);
    }

    static void printBooksBySize(std::string mode="slimmer") {
        std::cout << "Provide number of pages:  ";
        std::string input;
        std::cin >> input;
        std::vector<Entity> result;

        int pageCount = Tables::getColumnIndex("books", "pages");
        for (Entity item : data["books"]) {
            if (mode == "slimmer") {
                if (item.getPages() >= std::stoi(input)) {
                ////if (std::stoi(item[pageCount]) >= std::stoi(input)) {
                    result.push_back(item);
                }
            }
            else if (mode == "thicker") {
                ////if (std::stoi(item[pageCount]) <= std::stoi(input)) {
                if (item.getPages() <= std::stoi(input)) {
                    result.push_back(item);
                }
            }
        }
        Interface::printTableFromData("books", headers["books"], result);
    }

    static void printBooksByAuthorOnly() {
        std::cout << std::endl;
        Interface::printTable("authors", false);
        std::cout << std::endl;
        std::cout << "     provide author's id:";
        int idSearched;
        std::cin >> idSearched;
        //// std::vector<std::vector<std::string>> result;
        std::vector<Entity> result;

        for(Entity item: data["books"]) {
        //// for (std::vector<std::string> item : data["books"]) {
            if(item.getIdAuthors() == idSearched) {
            ////if (item[Tables::getColumnIndex("books", "id authors")] == idSearched) {
                result.push_back(item);
            }
        }
        // std::cout << getById("authors", idSearched));
        std::string title = "ksiazka autorstwa ";
        title.append(Tables::getById("authors", idSearched).getName());
        //// title.append(Tables::getById("authors", idSearched)[1]);
        title.append(" ");
        title.append(Tables::getById("authors", idSearched).getLastname());
        //// title.append(Tables::getById("authors", idSearched)[2]);
        Interface::printTableFromData(title, headers["books"], result);

    }

    static void printBooks() {
        Interface::printTable("books");
    }

    static void addBook() {
        data["books"].push_back(Interface::insertRow("books"));
    }
};

class Clients {

    public:

    static void menu() {
        std::string order;
        order = Interface::printInterface("clients", {"enter", "read", "back"});

        if (order == "enter") {
            addClient();
            menu();
        }
        else if (order == "read") {
            printClients();
            menu();
        }

        else if (order == "back") {
            //TODO: exit()
        }

        else {
            Interface::unknownCommandPrompt();
            menu();
        }
    }
    private:

    static void printClients() {
        Interface::printTable("clients");
    }

    static void addClient() {
        data["clients"].push_back(Interface::insertRow("clients"));
    }

};

class Orders {

    public:

    static void menu() {

        std::string order;
        order = Interface::printInterface("oders", {"enter, read, back, read not lend"});

        if (order == "enter") {
            addOrder();
            menu();
        }
        else if (order == "read") {
            printOrders();
            menu();
        }
        else if (order == "read not lend") {
            printAvailableBooks();
            menu();
        }
        else if (order == "wróć") {
            //TODO: none
        }
        else {
            Interface::unknownCommandPrompt();
            menu();
        }
    }

    private:

    static void printOrders() {
        Interface::printTable("orders");
    }

    static void printAvailableBooks() {

        std::vector<std::vector<std::string>> result;
        int idBooks = Tables::getColumnIndex("orders", "id books");
        //TODO: brak implementacji

    }

    static void addOrder() {
        data["orders"].push_back(Interface::insertRow("orders"));
    }
};

class Authors {
    public:
    static void menu() {
        std::string order;
        order = Interface::printInterface("authors", {"enter", "read", "back"});
        if (order == "enter") {
            addAuthor();
            menu();
        }
        else if (order == "read") {
            printAuthors();
            menu();
        }
        else if (order == "back") {
            //TODO: None
        }
        else {
            Interface::unknownCommandPrompt();
            menu();
        }
    }
    private:
    static void printAuthors() {
        Interface::printTable("authors");
    }

    static void addAuthor() {
        data["authors"].push_back(Interface::insertRow("authors"));
    }
};


void menu() {
    std::string order;
    order = Interface::printInterface("Main menu", {"books", "authors", "clients", "orders", "exit"});
    if (order == "books") {
        Books::menu();
    }
    else if (order == "authors") {
        Authors::menu();
    }
    else if (order == "clients") {
        Clients::menu();
    }
    else if (order == "orders") {
        Orders::menu();
    }
    else if(order == "exit") {
        System::quitting();
    }
    else {
        Interface::unknownCommandPrompt();
    }

}

int main() {

    System::boot();
    while(true) {
        std::cout << "WARNING! data write occurs after providing 'exit' command" << std::endl;
        menu();
    }



}
