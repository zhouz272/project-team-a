#ifndef OBJPOS_H
#define OBJPOS_H

class objPos {
   private:
    int x, y;
    char symbol;

   public:
    objPos();
    objPos(int x, int y, char symbol);
    ~objPos();
    int getX() const;
    int getY() const;
    char getSymbol() const;
    void print() const;
};

#endif  // OBJPOS_H
