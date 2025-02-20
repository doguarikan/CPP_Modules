#include "Zombie.hpp"

int main() {
    randomChump("dogu");
    Zombie *a = newZombie("baha");
    Zombie b("izzet");
    b.announce();
    a->announce();
    delete a;
}
