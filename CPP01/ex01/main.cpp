#include "Zombie.hpp"

int main() {
    int n = 5;
    Zombie *a = zombieHorde(n, "Zombie");
    for(int i = 0; i < n; i++) {
        a[i].announce();
    }
    delete []a;
}
