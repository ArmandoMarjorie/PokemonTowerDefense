#ifndef POKEMONENEMY_H
#define POKEMONENEMY_H

class PokemonEnemy
{
private:
    int x;
    int y;
    float speed;
public:
    PokemonEnemy();
    PokemonEnemy(int beginX, int beginY, float s);
    ~PokemonEnemy();
    void update();
    int getX() const;
    int getY() const;
};

#endif // POKEMONENEMY_H
