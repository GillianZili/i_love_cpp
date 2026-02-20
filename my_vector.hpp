class myVct
{
public:
    myVct();
    myVct(int cap);
    int get_size() const;
    int get_capacity() const;
    void push_back(int value);
    void pop_back();
    int get_value(int index) const;

private:
    void scale_up();
    void scale_down();
    void move(int capacity);

    int size;
    int capacity;
    int *ptr;
};