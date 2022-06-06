#include <iostream>
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

    Entity returnEntity() {
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
        std::cout << "#szukanie indexu kolumny " << headerName << " w tableli " << table << "...";
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
        return result.returnEntity();
    }

    static void initializeDB() {
        // TODO: sprawdzneie czy istnieja
        createTables();
        readTables();
    }

    static void createTables() {
        //for(std::vector<std::string item> : data) { //TODO: iterator po hashtable
        //}
    }

    static void writeTables() {
        //TODO:
    }

    static void readTables() {
        //TODO:
    }
};

class system {

    public:
    static void boot() {
        std::cout << "START MANAGERA BIBLIOTECZNEGO...";
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
        //TODO:
    }

    static void updateConfig() {
        //TODO:

    }

    static void quitting() {
        while(true) {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "     CZY CHCESZ ZAPISAĆ ZMIANY? (y/n)";
            char order;
            std::cin >> order;
            std::cout << std::endl;
            if (order == 'y') {
                std::cout << "~ config.json został zaktualizowany ~";
                updateConfig();
                Tables::writeTables();
                break;
            }
            else if (order == 'n') {
                std::cout << "zmiany zostały porzucone";
                break;
            }
        }
        //TODO: exit();
    }
};

class Interface {

    public:
    static void printHeader(std::string title){
        std::cout << std::endl;
        std::cout << "  ########################";
        std::cout << std::endl;
        std::cout << "    ~~~ Baza danych biblioteki ~~~";
        std::cout << "    "+title;
        std::cout << std::endl;
    }

    static std::string printInterface(std::string title, std::vector<std::string> options) { //TODO: sprawdz czy size parametrowego vectora sie sprawdzi czy jakis const
        printHeader(title);
        std::cout << "     OPCJE:";
        std::cout << std::endl;

        for (int i = 0; i < options.size(); i++) {
            std::cout << "     " << i;
        }

        std::cout << std::endl;
        std::cout << "  ########################";
        std::cout << std::endl;
        std::string order;
        std::cout << "     ~[wprowadź komendę]~>";
        std::cin >> order;
        std::cout << std::endl;
        return order;
    }

    static void unknownCommandPrompt() {
        std::cout << "!!! nie rozpoznano komendy !!!";
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

    //std::string specialInput()

    static int choiceFromTable(std::string title) {
        while (true) {
            std::string choice;
            std::cout <<  "    czy chcesz wprowadzić nowy rekord? (y/n)";
            std::cin >> choice;
            if(choice == "y") {
                data[title].push_back(insertRow(title));
                // return config["autoincrement"][title];
                return config[title];
            }
            else if(choice == "n") {
               printTable(title, false);
               std::string temp;
               std::cout << "     wybierz id " << title <<":";
               std::cin >> temp;
               return stoi(temp);
            }
        }
    }

    static std::vector<std::string> _insertRow(std::string title) {
        std::vector<std::string> inputData;
        std::cout << std::endl;
        std::cout << "     tabela " << title << " - wprowadzanie danych";
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
        std::cout << "     zakończono wprowadzanie danych";
        std::cout << std::endl;
        return inputData;

    }

    static Entity insertRow(std::string title) {
        Entity e;
        std::cout << std::endl;
        std::cout << "     tabela " << title << " - wprowadzanie danych";
        std::cout << std::endl;

        for (std::string item : headers[title]) {
            std::string pre = item.substr(0, 3);
            std::string rest = item.substr(3);
            if (item == "id") {
                e.setId(system::autoincrement(title));
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
        std::cout << "     zakończono wprowadzanie danych";
        std::cout << std::endl;

        return e.returnEntity();


    }
};





class Books {

    public:

    static void menu() {
        std::string order;
        order = Interface::printInterface("ksiazki", {
                "dodaj",
                "wypisz",
                "wypisz rosnąco",
                "wypisz malejąco",
                "wypisz konkretnego autorstwa",
                "wypisz chudsze niż",
                "wypisz grubsze niż",
                "wróć"
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
        if (order == "dodaj") {
            addBook();
            menu();
        } else if (order == "wypisz") {
            printBooks();
            menu();
        } else if (order == "wypisz rosnąco") {
            printBooksByColumn("descending");
            menu();
        }
        else if (order == "wypisz malejąco") {
            printBooksByColumn();
            menu();
        }
        else if (order == "wypisz konkretnego autorstwa") {
            printBooksByAuthorOnly();
            menu();
        }
        else if (order == "wypisz chudzsze niż") {
            printBooksBySize();
            menu();
        }
        else if (order == "wypisz grubsze niż") {
            printBooksBySize("thicker");
            menu();
        }
        else if (order == "wróć") {
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
        std::cout << "     wybierz kolumnę:";
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
        std::cout << "Podaj ilość stron: ";
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
        std::cout << "Podaj ilość stron: ";
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
        std::cout << "     podaj id autora:";
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

class clients {

    public:

    static void menu() {
        std::string order;
        order = Interface::printInterface("clients", {"dodaj", "wypisz", "wróć"});

        if (order == "dodaj") {
            addClient();
            menu();
        }
        else if (order == "wypisz") {
            printClients();
            menu();
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

class orders {

    public:

    static void menu() {

        std::string order;
        order = Interface::printInterface("oders", {"dodaj, wypisz, wróć, wypisz niewyporzyczone"});

        if (order == "dodaj") {
            addOrder();
            menu();
        }
        else if (order == "wypisz") {
            printOrders();
            menu();
        }
        else if (order == "wypisz niewyporzyczone") {
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

class authors {
    public:
    static void menu() {
        std::string order;
        order = Interface::printInterface("authors", {"dodaj", "wypisz", "wróć"});
        if (order == "dodaj") {
            addAuthor();
            menu();
        }
        else if (order == "wypisz") {
            printAuthors();
            menu();
        }
        else if (order == "wróć") {
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
        authors::menu();
    }
    else if (order == "clients") {
        clients::menu();
    }
    else if (order == "orders") {
        orders::menu();
    }
    else if(order == "exit") {
        system::quitting();
    }
    else {
        Interface::unknownCommandPrompt();
    }

}

int main() {

    system::boot();
    while(true) {
        std::cout << "UWAGA! zapis danych następuje przy wpisaniu komendy 'wyjdź'";
        menu();
    }



}
