#include "movies.h"
#include <algorithm>
#include <iostream>

void MovieCollection::add(const std::string &name, double rating) {
    movies_.push_back({name, rating});
}

bool compareMovies(Movie a, Movie b){
    return a.name < b.name;
}

void MovieCollection::sorting(){
    std::sort(movies_.begin(), movies_.end(), compareMovies);
}

void MovieCollection::printAll() const{
    std::cout << std::fixed;
    std::cout.precision(1);
    for(const Movie &m : movies_){
        std::cout << m.name << ", " << m.rating << "\n";
    }
}


std::vector<Movie> MovieCollection::findWithPrefix(const std::string &prefix) const{
    std::vector<Movie> result;

    for(int i = 0; i < movies_.size(); i++){
        if(movies_[i].name.substr(0, prefix.length()) == prefix){
            result.push_back(movies_[i]);
        }
    }

    for(int i = 0; i < result.size(); i++){
        for(int j = i + 1; j < result.size(); j++){
            if(result[j].rating > result[i].rating){
                Movie temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
            else if(result[j].rating == result[i].rating && result[j].name < result[i].name){
                Movie temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    return result;
}
