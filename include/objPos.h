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

    // Getters
    int getX() const;
    int getY() const;
    char getSymbol() const;

    // Setters
    void setPosition(int x, int y);  // Add this method

    // Print Method
    void print() const;
};

#endif  // OBJPOS_H
