#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <vector>

struct Movie {
    std::string name;
    double rating;
};

class MovieCollection {
public:
    void add(const std::string &name, double rating);
    void sorting();
    void printAll() const;
    std::vector<Movie> findWithPrefix(const std::string &prefix) const;

private:
    std::vector<Movie> movies_;
};

#endif
