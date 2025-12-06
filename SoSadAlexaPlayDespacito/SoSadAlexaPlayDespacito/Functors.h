#pragma once
#include "Classes.h"

class CompareMovieName
{
public:
    bool operator()(Movie left, Movie right)
    {
        return left.getName() < right.getName();
    }
};

class CompareMovieDurability
{
public:
    bool operator()(Movie left, Movie right)
    {
        return left.getDurability() < right.getDurability();
    }
};

class CompareMovieAudience
{
public:
    bool operator()(Movie left, Movie right)
    {
        return left.getAudience() < right.getAudience();
    }
};

class CompareCinemaName
{
public:
    bool operator()(Cinema left, Cinema right)
    {
        return left.getName() < right.getName();
    }
};

class CompareCinemaHalls
{
public:
    bool operator()(Cinema left, Cinema right)
    {
        return left.getHalls().size() < right.getHalls().size();
    }
};

class CompareSeanceDate
{
public:
    bool operator()(Seance left, Seance right)
    {
        return left.getDate() < right.getDate();
    }
};

class CompareSeanceTime
{
public:
    bool operator()(Seance left, Seance right)
    {
        return left.getTime() < right.getTime();
    }
};

class CompareSeanceMovie
{
public:
    bool operator()(Seance left, Seance right)
    {
        return left.getMovieTitle() < right.getMovieTitle();
    }
};

class CompareSeanceCinema
{
public:
    bool operator()(Seance left, Seance right)
    {
        return left.getCinemaName() < right.getCinemaName();
    }
};
