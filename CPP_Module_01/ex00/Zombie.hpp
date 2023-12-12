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

    private:
    std::string m_name;
    // Attributs membres de la classe

};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
