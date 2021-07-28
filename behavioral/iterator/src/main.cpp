#include <iostream>

#include "../include/iterator.h"
#include "../include/aggregate.h"
#include "../include/concrete_aggregate.h"
#include "../include/concrete_iterator.h"

int main()
{
    std::shared_ptr<ConcreteAggregate<int>> list = std::make_shared<ConcreteAggregate<int>>( 10 );
    // ConcreteAggregate<int> list = ConcreteAggregate<int>( 5 );
    std::shared_ptr<Iterator<int>> it = list->create_iterator();
    for ( ; !it->isDone(); it->next())
    {
        std::cout << "Item value: " << it->currentItem() << std::endl;
    }

    return 0;
    
}