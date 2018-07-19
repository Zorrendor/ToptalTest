struct Node

{

    Node *parent = nullptr;

    int parentValue;

    

    Node(int parentValue)

    {

        this->parentValue = parentValue;

    }

    

    int FindDepth()

    {

        if (parent == nullptr)

        {

            return 0;

        }

        

        return (parent->FindDepth() + 1);

    }

};



vector<int> solution(vector<int> &T)

{

    int M = (int)T.size();

    vector<int> network(M - 1);

    int capital = -1;

    

    vector<Node *> nodes(M);

    

    for (int i = 0; i < M; ++i)

    {

        if (T[i] == i)

        {

            capital = i;

        }

        

        nodes[i] = new Node(T[i]);

    }

    

    for (int i = 0; i < M; ++i)

    {

        if (i != capital)

        {

            Node *child = nodes[i];

            Node *parent = nodes[child->parentValue];

            child->parent = parent;

        }

    }

    

    for (int i = 0; i < M; ++i)

    {

        if (i != capital)

        {

            int val = nodes[i]->FindDepth();

            ++network[val - 1];

        }

    }

    return network;

}
