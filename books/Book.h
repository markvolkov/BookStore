//
// Created by Mark Volkov on 12/5/17.
//

#ifndef BOOKSTORE_BOOK_H
#define BOOKSTORE_BOOK_H


class Book {
private:
    std::string title;
    //When stock < wish order more books.
    //When sock > wish return some books.
    int stockCount;
    int wishCount;


};


#endif //BOOKSTORE_BOOK_H
