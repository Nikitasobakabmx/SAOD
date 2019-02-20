template<typename T>
class Node
{
    public:
        Node<T> *next;
        T data;
    
        Node();
        Node(const T &item)
        {
            data = item;
        }
};
