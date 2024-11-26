#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node *next, *prev;
        int Data;
        Node(int d){
            Data = d;
            next = NULL;
            prev = NULL;
        }

    protected:

    private:
};

#endif // NODE_H
