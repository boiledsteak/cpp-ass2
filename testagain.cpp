// ... (other code)

class ShapeTwoD 
{
    // ... (other code)

public:
    // ... (other code)

    // Setter function for name
    void setName(const string& n) 
    {
        name = n;
    }

    // Setter function for containsWarpSpace
    void setContainsWarpSpace(bool contains) 
    {
        containsWarpSpace = contains;
    }
};

class cross : public ShapeTwoD
{
private:
    int vert;

public:
    // Public constructor
    cross() : vert(0) {}

    // Getter method for vert
    int getVert() const 
    {
        return vert;
    }

    // Setter method for vert
    void setVert(int v) 
    {
        vert = v;
    }
};

class square : public ShapeTwoD
{
private:
    int vert;

public:
    // Public constructor
    square() : vert(0) {}

    // Getter method for vert
    int getVert() const 
    {
        return vert;
    }

    // Setter method for vert
    void setVert(int v) 
    {
        vert = v;
    }
};

class circle : public ShapeTwoD
{
private:
    int radius;

public:
    // Public constructor
    circle() : radius(0) {}

    // Getter method for radius
    int getRadius() const 
    {
        return radius;
    }

    // Setter method for radius
    void setRadius(int r) 
    {
        radius = r;
    }
};

// ... (rest of your code)
