#include <iostream>

#include "iterator.h"
#include "aggregate.h"
#include "concrete_aggregate.h"
#include "concrete_iterator.h"

int main()
{
    /*Pratise SFINAE with std::enable_if making class only accept Integral type*/
    std::shared_ptr<ConcreteAggregate<int>> list = std::make_shared<ConcreteAggregate<int>>( 10 );
    std::shared_ptr<Iterator<int>> it = list->create_iterator();
    for ( ; !it->isDone(); it->next())
    {
        std::cout << "Item value: " << it->currentItem() << std::endl;
    }

    return 0;
    
}