#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>


class Zombie
{
    public:
    // Méthodes de la classe
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void    announce(void) const;
    void    setName(std::string name);

    private:
    std::string m_name;
    // Attributs membres de la classe

};

Zombie* zombieHorde(int N, std::string name);

#endif

class nomADefinir
{
    public:
    // Méthodes de la classe
    nomADefinir();
    ~nomADefinir();

    private:
    // Attributs membres de la classe

};
